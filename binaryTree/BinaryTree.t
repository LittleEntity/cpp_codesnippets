#ifndef BINARYTREE_T
#define BINARYTREE_T

/* for those who did not know what "nullptr" is: 
"nullptr is a literal denoting the null pointer; it is not an integer"
quote of "http://www.stroustrup.com/C++11FAQ.html#nullptr" */

using std::string;

template<typename T>
BinaryTree<T>::BinaryTree() {
	rootPtr = nullptr;
}

template<typename T>
bool BinaryTree<T>::insert(const T & dataToBeInserted) {

	BinaryTreeNode<T> ** insertionPointPtr = &rootPtr;
	
	while (*insertionPointPtr != nullptr) {
		BinaryTreeNode<T> & currentNode = **insertionPointPtr;
		if (dataToBeInserted < currentNode.data) {
			insertionPointPtr = &(currentNode.smallChildPtr);
		} else if(dataToBeInserted > currentNode.data) {
			insertionPointPtr = &(currentNode.bigChildPtr);
		} else {
			// dataToBeInserted == (**insertionPointPtr).data
			return false; // insertion failed cause of duplicate
		}
	}

	*insertionPointPtr = new BinaryTreeNode<T>(dataToBeInserted);
	return true; // insertion completed
}

#include <iostream>
using std::cout;
using std::endl;
template<typename T>
bool BinaryTree<T>::remove(const T & dataToBeDeleted) {
	if (isEmpty()) { return false; }
	// find matching node and remember parent
	BinaryTreeNode<T> ** parentToChildPtrPtr = &rootPtr;
	BinaryTreeNode<T> ** removalPtr = &rootPtr;

	cout << "data" << (**removalPtr).data << endl;
	cout << "dataToBeDeleted" << dataToBeDeleted << endl;
	while ((**removalPtr).data != dataToBeDeleted) {
		BinaryTreeNode<T> & currentNode = **removalPtr;
		if (dataToBeDeleted < currentNode.data) {
			removalPtr = &(currentNode.smallChildPtr);
		} else if (dataToBeDeleted > currentNode.data) {
			removalPtr = &(currentNode.bigChildPtr);
		}

		if (*removalPtr == nullptr) {
			return false; // deletion failed because dataToBeDeleted could not be found
		}
	}

	BinaryTreeNode<T> & currentNode = **removalPtr;
	// case: node has no children
	const bool hasNoChildren = (currentNode.smallChildPtr == nullptr) && (currentNode.bigChildPtr == nullptr);
	if (hasNoChildren) {
		delete *removalPtr;
		*removalPtr = nullptr;
		return true;
	}

	// case: node has small child and no big child
	const bool hasSmallChild = (currentNode.smallChildPtr != nullptr) && (currentNode.bigChildPtr == nullptr);
	if (hasSmallChild) {
		BinaryTreeNode<T> * smallChildPtr = currentNode.smallChildPtr;
		delete *removalPtr;
		*removalPtr = smallChildPtr;
		return true;
	} 

	// case: node has big child and no small child
	const bool hasBigChild = (currentNode.bigChildPtr != nullptr) && (currentNode.smallChildPtr == nullptr);
	if (hasBigChild) {
		BinaryTreeNode<T> * bigChildPtr = currentNode.bigChildPtr;
		delete *removalPtr;
		*removalPtr = bigChildPtr;
		return true;
	}

	// case: node has two children
	// decision: take left neighbour
	return false; // needs to be implemented!
}

template<typename T>
bool BinaryTree<T>::isEmpty() const {
	return rootPtr == nullptr;
}

template<typename T>
string BinaryTree<T>::generateInfixNotation() const {
	return rootPtr->generateInfixNotation();
}

template<typename T>
string BinaryTree<T>::generatePostfixNotation() const {
	return rootPtr->generatePostfixNotation();
}

#endif // BINARYTREE_T