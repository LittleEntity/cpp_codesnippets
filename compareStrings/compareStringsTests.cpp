#include "compareStrings.hpp"
#include <iostream>
#include <cassert>
#include <string>
using std::cout;
using std::endl;
using std::string;

namespace tests_compareStrings {
	void tests_lessThan() {
		string a = "xyz";
		string b = "abc";
		assert(!(a < b));
		assert(b < a);

		string c = "asdf";
		string d = "asdfa";
		assert(c < d);
		assert(!(d < c));

		string e = "asdfx";
		string f = "sdfx";
		assert(e < f);
		assert(!(f < e));

		string g = "asdf";
		string h = "asdh";
		assert(g < h);
		assert(!(h < g));

		string i = "wagataga";
		string j = "wagataga";
		assert(!(i < j));
		assert(!(i < i));

		cout << "OK -- tests_lessThan" << endl;
	}

	void tests_lessOrEqualThan() {
		string a = "xyz";
		string b = "abc";
		assert(!(a <= b));
		assert(b <= a);

		string c = "asdf";
		string d = "asdfa";
		assert(c <= d);
		assert(!(d <= c));

		string e = "asdfx";
		string f = "sdfx";
		assert(e <= f);
		assert(!(f <= e));

		string g = "asdf";
		string h = "asdh";
		assert(g <= h);
		assert(!(h <= g));

		string i = "wagataga";
		string j = "wagataga";
		assert(i <= j);
		assert(i <= i);

		cout << "OK -- tests_lessOrEqualThan" << endl;
	}	

	void tests_greaterThan() {
		string a = "xyz";
		string b = "abc";
		assert(a > b);
		assert(!(b > a));

		string c = "asdf";
		string d = "asdfa";
		assert(!(c > d));
		assert(d > c);

		string e = "asdfx";
		string f = "sdfx";
		assert(!(e > f));
		assert(f > e);

		string g = "asdf";
		string h = "asdh";
		assert(!(g > h));
		assert(h > g);

		string i = "wagataga";
		string j = "wagataga";
		assert(!(i > j));
		assert(!(i > i));

		cout << "OK -- tests_greaterThan" << endl;
	}

	void tests_greaterOrEqualThan() {
		string a = "xyz";
		string b = "abc";
		assert(a >= b);
		assert(!(b >= a));

		string c = "asdf";
		string d = "asdfa";
		assert(!(c >= d));
		assert(d >= c);

		string e = "asdfx";
		string f = "sdfx";
		assert(!(e >= f));
		assert(f >= e);

		string g = "asdf";
		string h = "asdh";
		assert(!(g >= h));
		assert(h >= g);

		string i = "wagataga";
		string j = "wagataga";
		assert(i >= j);
		assert(i >= i);

		cout << "OK -- tests_greaterOrEqualThan" << endl;
	}

	void tests_isEqual() {
		string a = "xyz";
		string b = "abc";
		assert(!isEqual(a, b));

		string c = "asdf";
		string d = "asdfa";
		assert(!isEqual(c, d));

		string e = "asdfx";
		string f = "sdfx";
		assert(!isEqual(e, f));

		string g = "asdf";
		string h = "asdh";
		assert(!isEqual(g, h));

		string i = "wagataga";
		string j = "wagataga";
		assert(isEqual(i, j));
		assert(isEqual(i, i));

		cout << "OK -- tests_isEqual" << endl;
	}

	void tests_isUnequal() {
		string a = "xyz";
		string b = "abc";
		assert(isUnequal(a, b));

		string c = "asdf";
		string d = "asdfa";
		assert(isUnequal(c, d));

		string e = "asdfx";
		string f = "sdfx";
		assert(isUnequal(e, f));

		string g = "asdf";
		string h = "asdh";
		assert(isUnequal(g, h));

		string i = "wagataga";
		string j = "wagataga";
		assert(!(isUnequal(i, j)));
		assert(!(isUnequal(i, i)));

		cout << "OK -- tests_isUnequal" << endl;
	}

	void runTests() {
		tests_lessThan();
		tests_lessOrEqualThan();
		tests_greaterThan();
		tests_greaterOrEqualThan();
		tests_isEqual();
		tests_isUnequal();

		cout << "#-----------------------#" << endl;
		cout << "| OK -- all tests valid |" << endl;
		cout << "#-----------------------#" << endl;
	}
}

int main() {
	tests_compareStrings::runTests();
}
