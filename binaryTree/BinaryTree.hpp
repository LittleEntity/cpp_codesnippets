#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <string>
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
	//# private attributes #//
	BinaryTreeNode<T> * rootPtr;
};

#include "BinaryTree.t"

#endif // BINARYTREE_HPP
