#ifndef BINARYTREE_T
#define BINARYTREE_T

#include <cstddef>

using std::string;

template<typename T>
BinaryTree<T>::BinaryTree() {
	rootPtr = NULL;
}

template<typename T>
void BinaryTree<T>::insert(const T & dataToBeInserted) {

	BinaryTreeNode<T> ** insertionPointPtr = &rootPtr;
	
	while (*insertionPointPtr != NULL) {
		BinaryTreeNode<T> & currentNode = **insertionPointPtr;
		if (dataToBeInserted < currentNode.data) {
			insertionPointPtr = &(currentNode.smallChildPtr);
		} else {
			insertionPointPtr = &(currentNode.bigChildPtr);
		}
	}

	*insertionPointPtr = new BinaryTreeNode<T>(dataToBeInserted);
}

template<typename T>
bool BinaryTree<T>::isEmpty() const {
	return rootPtr == NULL;
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