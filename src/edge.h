/**
	edge.h
	this file specifies the Edge ADT
	
	author: zeph|nzer aka Joseph Matthias Goh
	website: http://zephinzer.sg
	github: https://github.com/zephinzer
**/

#ifndef Z_EDGE_H
#define Z_EDGE_H
#include <sstream>
#include <string>

#include "node.h"
#include "direction.h"

template <class T>
class Edge {
	Node<T> 	*node1;
	Node<T> 	*node2;
	bool		directed;
	Direction	direction;
	int			weight;
public:
	Edge();
	Edge(Node<T> *node1, Node<T> *node2, int weight, Direction direction);
	
	Direction getDirection();
	T	getNode1Value();
	T	getNode2Value();
	int getWeight();
	bool isDirected();
	String toString();
};

template <class T>
Edge<T>::Edge() : node1(NULL), node2(NULL), direction(NULL), weight(-1) {}

template <class T>
Edge<T>::Edge(Node<T> *node1, Node<T> *node2, int weight, Direction direction) :
	node1(node1), node2(node2), weight(weight), direction(direction) {
	if(direction == UNDIRECTED) {
		directed = false;
	} else {
		directed = true;
	}
}

template <class T>
Direction Edge<T>::getDirection() {
	return direction;
}

template <class T>
T	Edge<T>::getNode1Value() {
	return node1->getValue();
}

template <class T>
T	Edge<T>::getNode2Value() {
	return node2->getValue();
}

template <class T>
int Edge<T>::getWeight() {
	return weight;
}

template <class T>
bool Edge<T>::isDirected() {
	return directed;
}

template <class T>
String Edge<T>::toString() {
	std::stringstream retval;
	char dir;
	if(directed) {
		if(direction == FORWARD) {
			dir = '>';
		} else {
			dir = '<';
		}
	} else {
		dir = '-';
	}
	retval << "[" <<
		node1->toString() << " " <<
		dir << " " <<
		node2->toString() <<
		"]";
	return retval.str();
}

#endif