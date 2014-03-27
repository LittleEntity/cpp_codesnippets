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
void BinaryTree<T>::insert(const T & dataToBeInserted) {

	BinaryTreeNode<T> ** insertionPointPtr = &rootPtr;
	
	while (*insertionPointPtr != nullptr) {
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