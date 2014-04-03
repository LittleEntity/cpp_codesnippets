#include "BinaryTree.hpp"
#include <cassert>
#include <iostream>
#include <string>

namespace tests_BinaryTree {
	using std::string;
	using std::cout;
	using std::endl;

	void tests_insert() {
		BinaryTree<string> bt;
		bt.insert("c");
		bt.insert("d");
		bt.insert("a");
		bt.insert("b");

		cout << bt.generateInfixNotation() << endl;
		cout << bt.generatePostfixNotation() << endl;

		BinaryTree<int> bti;
		bti.insert(5);
		bti.insert(2);
		bti.insert(1);
		bti.insert(3);
		bti.insert(7);
		bti.insert(6);
		bti.insert(4);
		bti.insert(2);
		bti.insert(5);

		cout << bti.generateInfixNotation() << endl;
		cout << bti.generatePostfixNotation() << endl;
	}

	void tests_remove() {
		BinaryTree<int> bti;
		bti.insert(10);
		bti.remove(10);

		cout << bti.generateInfixNotation() << endl;
		cout << bti.generatePostfixNotation() << endl;	
	}

	void runTests() {
		tests_insert();
		tests_remove();
	}
}

int main() {
	tests_BinaryTree::runTests();
}
