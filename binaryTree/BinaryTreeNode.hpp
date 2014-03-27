#ifndef BINARYTREENODE_HPP
#define BINARYTREENODE_HPP

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
	BinaryTreeNode(const T & data);

	//# public methods #//
	std::string generateInfixNotation() const;
	std::string generatePostfixNotation() const;
};

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T & data) 
	: data(data), smallChildPtr(nullptr), bigChildPtr(nullptr) {}

template<typename T>
std::string BinaryTreeNode<T>::generateInfixNotation() const {
	using std::stringstream;
	stringstream infixNotation;
	
	if (smallChildPtr != nullptr) { 
		infixNotation << smallChildPtr->generateInfixNotation();
	}
	
	infixNotation << " " << data << " ";

	if (bigChildPtr != nullptr) {
		infixNotation << bigChildPtr->generateInfixNotation();
	}

	return infixNotation.str();
}

template<typename T>
std::string BinaryTreeNode<T>::generatePostfixNotation() const {
	using std::stringstream;
	stringstream postfixNotation;
	postfixNotation << " " << data << " ";

	if (smallChildPtr != nullptr) {
		postfixNotation << smallChildPtr->generatePostfixNotation();
	}

	if(bigChildPtr != nullptr) {
		postfixNotation << bigChildPtr->generatePostfixNotation();
	}

	return postfixNotation.str();
}

#endif // BINARYTREENODE_HPP