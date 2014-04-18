/**
	graph.h
	this file specifies a list-based Graph ADT using
	std::vector<T> as the backend
	
	author: zeph|nzer aka Joseph Matthias Goh
	website: http://zephinzer.sg
	github: https://github.com/zephinzer
**/
#ifndef Z_GRAPH_H
#define Z_GRAPH_H

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

typedef std::string String;

#include "node.h"
#include "edge.h"

template <class T>
class Graph {
	std::vector<Edge<T>*>	data;
public:
	Graph();
	void addEdge(Edge<T> *input);
	void clear();
	std::vector<unsigned int> getDuplicates(Edge<T> *input);
	std::vector<unsigned int> getSimilar(Edge<T> *input);
	String toString();
};

/**
/// base constructor of the Graph ADT
**/
template <class T>
Graph<T>::Graph() {}

/**
/// adds an edge to the graph
/// @author zeph|nzer
/// @usage [GraphVarName].addEdge(&[EdgeVarName]);
/// @param input : pointer to an Edge structure
**/
template <class T>
void Graph<T>::addEdge(Edge<T> *input) {
	data.push_back(input);
}

/**
/// clears the graph of all edges
/// @author zeph|nzer
/// @usage [GraphVarName].clear();
**/
template <class T>
void Graph<T>::clear() {
	data.clear();
}

/**
/// searches for the instance of input within this
/// Graph instance using the memory address (instance search)
/// @author zeph|nzer
/// @usage std::vector<unsigned int> res = [GraphVarName].findDuplicates(&[EdgeVarName]);
/// @returns an std::vector<unsigned int> structure containing a list
///				of indices where [EdgeVarName] is repeated
**/
template <class T>
std::vector<unsigned int> Graph<T>::getDuplicates(Edge<T> *input) {
	unsigned int sizeData = data.size();
	std::vector<unsigned int> retval;
	for(unsigned int i = 0; i < sizeData; ++i) {
		if(data[i] == input) {
			retval.push_back(i);
		}
	}
	return retval;
}

/**
/// searches for the instance of input within this
/// Graph instance using the memory address (values search)
/// @author zeph|nzer
/// @usage std::vector<unsigned int> res = [GraphVarName].findDuplicates(&[EdgeVarName]);
/// @returns an std::vector<unsigned int> structure containing a list
///				of indices where [EdgeVarName] is repeated
**/
template <class T>
std::vector<unsigned int> Graph<T>::getSimilar(Edge<T> *input) {
	unsigned int sizeData = data.size();
	std::vector<unsigned int> retval;
	for(unsigned int i = 0; i < sizeData; ++i) {
		if( ( data[i]->getNode1Value() == input->getNode1Value() ) &&
			( data[i]->getNode2Value() == input->getNode2Value() ) &&
			( data[i]->getWeight() == input->getWeight() ) &&
			( data[i]->isDirected() == input->isDirected() ) &&
			( data[i]->getDirection() == input->getDirection() ) ) {
			retval.push_back(i);
		}
	}
	return retval;
}

/**
/// converts the graph to a string
/// example output:
/// {
/// 	[123 < 444]
/// 	[41 > 194]
/// 	[99 < 2994]
/// }
/// @author zeph|nzer
/// @return std::string structure containing graph edges
**/
template <class T>
String Graph<T>::toString() {
	std::stringstream retval;
	retval << "{\n";
	unsigned int size = data.size();
	for(unsigned int i = 0; i < size; ++i) {
		retval << "\t" << data[i]->toString() << "\n";
	}
	retval << "}";
	return retval.str();
}


#endif