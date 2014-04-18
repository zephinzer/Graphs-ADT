/**
	node.h
	this file specifies the Node ADT
	
	author: zeph|nzer aka Joseph Matthias Goh
	website: http://zephinzer.sg
	github: https://github.com/zephinzer
**/

#ifndef Z_NODE_H
#define Z_NODE_H
#include <sstream>
#include <string>

template <class T>
class Node {
	T value;
	Node* next;
public:
	Node();
	Node(T value);
	void setValue(T value);
	T getValue();
	String toString();
};

/**
/// constructors
**/
template <class T>
Node<T>::Node() : value(NULL) {}
template <> Node<int>::Node() : value(0) {}
template <> Node<char>::Node() : value('\0') {}
template <class T> Node<T>::Node(T value) : value(value) {}

/**
///	sets the internal value of this node
**/
template <class T>
void Node<T>::setValue(T value) {
	this->value = value;
}

/**
///	gets the internal value of this node
**/
template <class T>
T Node<T>::getValue() {
	return this->value;
}

/**
/// converts the value within this node instance to a string
**/
template <class T>
String Node<T>::toString() {
	std::stringstream retval;
	retval << value;
	return retval.str();
}
#endif