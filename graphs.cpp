#include <iostream>
#include <string>
#include <vector>

typedef std::string String;

#include "graph.h"

void testGraphADT();
void printLine();

int main(int argc, char** argv) {
	testGraphADT();
	return 0;
}

void printLine() {
	std::cout << "/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / " << std::endl <<
			"/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / " << std::endl;
}

void testGraphADT() {
	printLine();
	std::cout << "Unit test for Node, Edge and Graph ADTs initializing..." << std::endl << std::endl;
	String lastResult;
	
	
	
	printLine();
	std::cout << "[Node construction]" << std::endl;
	Node<int> testNode1;
	if(testNode1.toString().compare("0") == 0) { 
		lastResult = "PASSED";
	} else lastResult = "FAILED";
	std::cout <<lastResult << " for Node<T>()" << std::endl;
	Node<int> testNode2(9154812);
	if(testNode2.toString().compare("9154812") == 0) { 
		lastResult = "PASSED";
	} else lastResult = "FAILED";
	std::cout << lastResult << " for Node<T>(T value)" << std::endl;
	
	std::cout << "Constructing other Nodes for Edge testing..." << std::endl;
	// 18x Node creation
	Node<int> testNode3(41233);
	Node<int> testNode4(150);
	Node<int> testNode5(91438);
	Node<int> testNode6(3);
	
	Node<int> testNode7(3483);
	Node<int> testNode8(26234);
	Node<int> testNode9(55);
	Node<int> testNode10(234235);
	
	Node<int> testNode11(55);
	Node<int> testNode12(3);
	Node<int> testNode13(3567);
	Node<int> testNode14(34562);
	
	Node<int> testNode15(55);
	Node<int> testNode16(83345);
	Node<int> testNode17(44);
	Node<int> testNode18(5624743);
	
	Node<int> testNode19(232326);
	Node<int> testNode20(5816);
	Node<int> testNode21(817);
	
	// break point //
	
	std::cout << std::endl;
	
	// break point //
	
	printLine();
	std::cout << "[Edge construction]" << std::endl;
	Edge<int> testEdge1(&testNode1, &testNode2, -1, FORWARD);
	if(testEdge1.toString().compare("[0 > 9154812]") == 0) { 
		lastResult = "PASSED";
	} else lastResult = "FAILED";
	std::cout << lastResult << " for Edge<T>(Node<T>*, Node<T>*, int, Direction) [variant 1]" << std::endl;
	std::cout << lastResult << " for -1, Direction::FORWARD" << std::endl;

	Edge<int> testEdge2(&testNode2, &testNode3, 3, BACKWARD);
	if(testEdge2.toString().compare("[9154812 < 41233]") == 0) { 
		lastResult = "PASSED";
	} else lastResult = "FAILED";
	std::cout << lastResult << " for Edge<T>(Node<T>*, Node<T>*, int, Direction) [variant 2]" << std::endl;
	std::cout << lastResult << " for 3, Direction::BACKWARD" << std::endl;
	Edge<int> testEdge3(&testNode3, &testNode4, 5, UNDIRECTED);
	if(testEdge3.toString().compare("[41233 - 150]") == 0) { 
		std::cout << lastResult << " for Edge<T>(Node<T>*, Node<T>*, int, Direction) [variant 3]" << std::endl;
		std::cout << lastResult << " for 5, Direction::UNDIRECTED" << std::endl;
	}
	
	std::cout << "Constructing other Edges for Graph testing..." << std::endl;
	// 17x Edge creation
	Edge<int> testEdge4(&testNode4, &testNode5, 3, FORWARD);
	Edge<int> testEdge5(&testNode5, &testNode6, 7, FORWARD);
	Edge<int> testEdge6(&testNode6, &testNode7, 41, FORWARD);
	Edge<int> testEdge7(&testNode7, &testNode8, 3, FORWARD);
	
	Edge<int> testEdge8(&testNode8, &testNode9, 2, FORWARD);
	Edge<int> testEdge9(&testNode9, &testNode10, 53, FORWARD);
	Edge<int> testEdge10(&testNode10, &testNode11, 16, FORWARD);
	Edge<int> testEdge11(&testNode11, &testNode12, 55, FORWARD);
	
	Edge<int> testEdge12(&testNode12, &testNode13, 12, FORWARD);
	Edge<int> testEdge13(&testNode13, &testNode14, 41, FORWARD);
	Edge<int> testEdge14(&testNode14, &testNode15, 8, FORWARD);
	Edge<int> testEdge15(&testNode15, &testNode16, 6, FORWARD);
	
	Edge<int> testEdge16(&testNode16, &testNode17, 41, FORWARD);
	Edge<int> testEdge17(&testNode17, &testNode18, 17, FORWARD);
	Edge<int> testEdge18(&testNode18, &testNode19, 12, FORWARD);
	Edge<int> testEdge19(&testNode19, &testNode20, 35, FORWARD);
	
	Edge<int> testEdge20(&testNode20, &testNode21, 32, FORWARD);
	
	// values duplicate of 20 used later for duplicate testing
	Edge<int> testEdge21(&testNode20, &testNode21, 32, FORWARD);
	
	// fail cases for Graph.getDuplicates/getSimilar
	// all are variants of 21 with differences in 1 property
	Edge<int> testEdge22(&testNode20, &testNode21, 33, FORWARD);
	Edge<int> testEdge23(&testNode20, &testNode21, 32, BACKWARD);
	Edge<int> testEdge24(&testNode20, &testNode21, 32, UNDIRECTED);
	Edge<int> testEdge25(&testNode20, &testNode1, 32, FORWARD);
	Edge<int> testEdge26(&testNode1, &testNode21, 32, FORWARD);
	
	// break point //
	
	std::cout << std::endl;
	
	// break point //

	printLine();
	std::cout << "[Graph construction]" << std::endl;
	Graph<int> testGraph;
	std::cout << "PASSED for Graph<T>()" << std::endl;
	testGraph.addEdge(&testEdge4);
	testGraph.addEdge(&testEdge5);
	testGraph.addEdge(&testEdge6);
	testGraph.addEdge(&testEdge7);
	testGraph.addEdge(&testEdge8);
	testGraph.addEdge(&testEdge9);
	testGraph.addEdge(&testEdge10);
	testGraph.addEdge(&testEdge11);
	testGraph.addEdge(&testEdge12);
	testGraph.addEdge(&testEdge13);
	testGraph.addEdge(&testEdge14);
	testGraph.addEdge(&testEdge15);
	testGraph.addEdge(&testEdge16);
	testGraph.addEdge(&testEdge17);
	testGraph.addEdge(&testEdge18);
	testGraph.addEdge(&testEdge19);
	testGraph.addEdge(&testEdge20);
	if(testGraph.toString().compare(
		"{\n\t[150 > 91438]\n\t[91438 > 3]\n\t[3 > 3483]\n\t[3483 > 26234]\n\t[26234 > 55]\n\t[55 > 234235]\n\t[234235 > 55]\n\t[55 > 3]\n\t[3 > 3567]\n\t[3567 > 34562]\n\t[34562 > 55]\n\t[55 > 83345]\n\t[83345 > 44]\n\t[44 > 5624743]\n\t[5624743 > 232326]\n\t[232326 > 5816]\n\t[5816 > 817]\n}"
		) == 0) {
		lastResult = "PASSED";
	} else lastResult = "FAILED";
	std::cout << lastResult << " for Graph<T>::addEdge(Edge<T>*)" << std::endl;

	int option = 0;
	std::vector<unsigned int> fDresult;
	unsigned int fDresultSize = 0;
	
	testGraph.clear();
	testGraph.addEdge(&testEdge20); // <- memory address same as...
	testGraph.addEdge(&testEdge20); // memory address same as...
	testGraph.addEdge(&testEdge20); // memory address NOT same as...
	testGraph.addEdge(&testEdge21); // (this is a values duplicate)
	testGraph.addEdge(&testEdge22); // should not have effect
	testGraph.addEdge(&testEdge23); // should not have effect
	testGraph.addEdge(&testEdge24); // should not have effect
	testGraph.addEdge(&testEdge25); // should not have effect
	testGraph.addEdge(&testEdge26); // should not have effect
	
	/*
	std::cout << testGraph.toString();
	*/
	
	REINIT:
	if(!fDresult.empty()) {
		fDresult.clear();
		fDresultSize = 0;
	}
	
	switch(option) {
		case 0:
			goto GET_DUPLICATES;
			break;
		case 1:
			goto GET_SIMILAR;
			break;
		default:
			goto COMPLETE;
	}
	
	// testing for getDuplicates
	
	GET_DUPLICATES:
	fDresult = testGraph.getDuplicates(&testEdge20);
	fDresultSize = fDresult.size();
	if( (fDresultSize == 3) ) {
		lastResult = "PASSED";
		for(unsigned int i = 0; i < fDresultSize; ++i) {
			if(fDresult[i] != i) {
				lastResult = "FAILED";
			}
		}
	} else lastResult = "FAILED";
	std::cout << lastResult << " for Graph<T>::getDuplicates(Edge<T>*)" << std::endl;
	++option;
	goto REINIT;
	
	// testing for getSimilar
	
	GET_SIMILAR:
	fDresult = testGraph.getSimilar(&testEdge20);
	fDresultSize = fDresult.size();
	if( (fDresultSize == 4) ) {
		lastResult = "PASSED";
		for(unsigned int i = 0; i < fDresultSize; ++i) {
			if(fDresult[i] != i) {
				lastResult = "FAILED";
			}
		}
	} else lastResult = "FAILED";
	std::cout << lastResult << " for Graph<T>::getSimilar(Edge<T>*)" << std::endl;
	++option;
	goto REINIT;
	
	COMPLETE:;
}