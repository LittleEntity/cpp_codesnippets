#ifndef BINARYTREENODE_HPP
#define BINARYTREENODE_HPP

template<typename T>
class BinaryTreeNode {
public:
	//# public constructors and destructors #//
	BinaryTreeNode(const T data);

	//# public attributes #//
	const T data;
	BinaryTreeNode * smallChildPtr;
	BinaryTreeNode * bigChildPtr;
};

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T data) 
	: data(data), smallChildPtr(NULL), bigChildPtr(NULL) {}

#endif // BINARYTREENODE_HPP