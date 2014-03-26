#ifndef BINARYTREENODE_HPP
#define BINARYTREENODE_HPP

#include <cstddef>
#include <string>
#include <sstream>

template<typename T>
class BinaryTreeNode {
public:
	//# public attributes #//
	const T data;
	BinaryTreeNode * smallChildPtr;
	BinaryTreeNode * bigChildPtr;

	//# public constructors and destructors #//
	BinaryTreeNode(const T data);

	//# public methods #//
	std::string generateInfixNotation() const;
	std::string generatePostfixNotation() const;
};

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T data) 
	: data(data), smallChildPtr(NULL), bigChildPtr(NULL) {}

template<typename T>
std::string BinaryTreeNode<T>::generateInfixNotation() const {
	using std::stringstream;
	stringstream infixNotation;
	
	if (smallChildPtr != NULL) { 
		infixNotation << smallChildPtr->generateInfixNotation();
	}
	
	infixNotation << " " << data << " ";

	if (bigChildPtr != NULL) {
		infixNotation << bigChildPtr->generateInfixNotation();
	}

	return infixNotation.str();
}

template<typename T>
std::string BinaryTreeNode<T>::generatePostfixNotation() const {
	using std::stringstream;
	stringstream postfixNotation;
	postfixNotation << " " << data << " ";

	if (smallChildPtr != NULL) {
		postfixNotation << smallChildPtr->generatePostfixNotation();
	}

	if(bigChildPtr != NULL) {
		postfixNotation << bigChildPtr->generatePostfixNotation();
	}

	return postfixNotation.str();
}

#endif // BINARYTREENODE_HPP