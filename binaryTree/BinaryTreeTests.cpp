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

		assert(bt.generateInfixNotation() == " a  b  c  d ");		
		assert(bt.generatePostfixNotation() == " c  a  b  d ");

		BinaryTree<int> bti;
		assert(bti.insert(5) == true);
		assert(bti.insert(2) == true);
		assert(bti.insert(1) == true);
		assert(bti.insert(3) == true);
		assert(bti.insert(7) == true);
		assert(bti.insert(6) == true);
		assert(bti.insert(4) == true);
		assert(bti.insert(2) == false);
		assert(bti.insert(5) == false);

		assert(bti.generateInfixNotation() == " 1  2  3  4  5  6  7 ");
		assert(bti.generatePostfixNotation() == " 5  2  1  3  4  7  6 ");
	}

	void tests_remove() {
		BinaryTree<int> bti;
		bti.insert(10);
		assert(bti.remove(10) == true);

		assert(bti.generateInfixNotation() == "emptyTree");
		assert(bti.generatePostfixNotation() == "emptyTree");

		bti.insert(10);
		bti.insert(6);
		bti.insert(4);
		bti.insert(9);
		assert(bti.remove(99) == false);
		assert(bti.generateInfixNotation() == " 4  6  9  10 ");
		assert(bti.generatePostfixNotation() == " 10  6  4  9 ");
		assert(bti.remove(4) == true);
		assert(bti.generateInfixNotation() == " 6  9  10 ");
		assert(bti.generatePostfixNotation() == " 10  6  9 ");
		assert(bti.remove(6) == true);
		assert(bti.generateInfixNotation() == " 9  10 ");
		assert(bti.generatePostfixNotation() == " 10  9 ");
		assert(bti.remove(9) == true);
		assert(bti.generateInfixNotation() == " 10 ");
		assert(bti.generatePostfixNotation() == " 10 ");
		assert(bti.remove(10) == true);
		assert(bti.generateInfixNotation() == "emptyTree");
		assert(bti.generatePostfixNotation() == "emptyTree");
		bti.insert(14);
		bti.insert(7);
		bti.insert(21);
		bti.insert(11);
		bti.insert(16);
		assert(bti.generateInfixNotation() == " 7  11  14  16  21 ");
		assert(bti.generatePostfixNotation() == " 14  7  11  21  16 ");
		assert(bti.remove(7) == true);
		assert(bti.generateInfixNotation() == " 11  14  16  21 ");
		assert(bti.generatePostfixNotation() == " 14  11  21  16 ");
		assert(bti.remove(21) == true);
		assert(bti.generateInfixNotation() == " 11  14  16 ");
		assert(bti.generatePostfixNotation() == " 14  11  16 ");
	}

	void runTests() {
		tests_insert();
		tests_remove();
	}
}

int main() {
	tests_BinaryTree::runTests();
}
