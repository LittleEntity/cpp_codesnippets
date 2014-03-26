#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <cstddef>
#include <string>
#include <sstream>
#include "BinaryTreeNode.hpp"

template<typename T>
class BinaryTree {
public:
//# public constructors and destructors #//
	BinaryTree();
	// BinaryTree(BinaryTree & bt);
	//~BinaryTree();
//# public methods #//
	void insert(const T & data);
	//void remove(const T & data);
	//void find(const T & data) const;
	bool isEmpty() const;
	//const T & getData() const;
	std::string generateInfixNotation() const;
	std::string generatePostfixNotation() const;

private:
//# private constructors #//
	BinaryTree(const T & data);

//# private attributes #//
	const T * dataPtr;
	BinaryTree * smallChildPtr;
	BinaryTree * bigChildPtr;
};

#include "BinaryTree.t"

#endif // BINARYTREE_HPP
