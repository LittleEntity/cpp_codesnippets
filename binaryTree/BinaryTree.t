#ifndef BINARYTREE_T
#define BINARYTREE_T

template<typename T>
BinaryTree<T>::BinaryTree() {
	smallChildPtr = NULL;
	bigChildPtr = NULL;
}

template<typename T>
BinaryTree<T>::BinaryTree(const T & data) {
	dataPtr = &data;
	smallChildPtr = NULL;
	bigChildPtr = NULL;
}

template<typename T>
void BinaryTree<T>::insert(const T & dataToBeInserted) {
	if(this->isEmpty()) {
		dataPtr = &dataToBeInserted;
		return;
	}

	BinaryTree * currentNodePtr = this;
	do {
		if (dataToBeInserted < *dataPtr) {
			if (currentNodePtr->smallChildPtr == NULL) {
				currentNodePtr->smallChildPtr = new BinaryTree(dataToBeInserted);
				return;
			}
			currentNodePtr = currentNodePtr->smallChildPtr;
		} else {
			if (currentNodePtr->bigChildPtr == NULL) {
				currentNodePtr->bigChildPtr = new BinaryTree(dataToBeInserted);
				return;
			}
			currentNodePtr = currentNodePtr->bigChildPtr;
		}
	}while(true); // if inserted: exit with return
}

template<typename T>
bool BinaryTree<T>::isEmpty() const {
	return dataPtr == NULL;
}

template<typename T>
std::string BinaryTree<T>::generateInfixNotation() const {
	using std::stringstream;
	stringstream infixNotation;
	if (smallChildPtr != NULL) { 
		infixNotation << smallChildPtr->generateInfixNotation();
	}
	if (dataPtr == NULL) {
		infixNotation << " empty ";	
	} else {
		infixNotation << " " << *dataPtr << " ";
	}
	if (bigChildPtr != NULL) {
		infixNotation << bigChildPtr->generateInfixNotation();
	}

	return infixNotation.str();
}

template<typename T>
std::string BinaryTree<T>::generatePostfixNotation() const {
	using std::stringstream;
	stringstream postfixNotation;
	if(dataPtr == NULL) {
		postfixNotation << " empty ";
	} else {
		postfixNotation << " " << *dataPtr << " ";
	}
	if (smallChildPtr != NULL) {
		postfixNotation << smallChildPtr->generatePostfixNotation();
	}
	if(bigChildPtr != NULL) {
		postfixNotation << bigChildPtr->generatePostfixNotation();
	}

	return postfixNotation.str();
}

#endif // BINARYTREE_T