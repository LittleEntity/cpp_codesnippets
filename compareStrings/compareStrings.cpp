#include "compareStrings.hpp"
#include <string>

using std::string;

bool isEqual(const string & a, const string & b) {
	// strings are unequal if they differ in length
	if(a.length() != b.length()) { return false; }

	// strings are unequal if they differ in a character at the same position
	for(int i = 0, j = 0; (i < a.length()) && (j < b.length()); ++i, ++j) {
		if(a[i] != b[j]) { return false; }
	}

	// strings are equal if top cases do not apply
	return true;
}

bool isUnequal(const string & a, const string & b) {
	return !isEqual(a, b);
}

bool operator<(const string & a, const string & b) {
	/* for each position compare the characters.
	If the strings differ in a position, lexicographic order is decidable. */
	for(int i = 0, j = 0; (i < a.length()) && (j < b.length()); ++i, ++j) {
		if(a[i] < b[j]) { return true; }
		else if(a[i] > b[i]) { return false; }
	}
	
	/* If the following is executed if a is a substing of b.
	a is less than b if the length of a is less than length of b. */
	if(a.length() < b.length()) { return true; }
	
	return false;
}

bool operator>(const string & a, const string & b) {
	/* for each position compare the characters.
	If the strings differ in a position, lexicographic order is decidable. */
	for(int i = 0, j = 0; (i < a.length()) && (j < b.length()); ++i, ++j) {
		if(a[i] > b[j]) { return true; }
		else if(a[i] < b[j]) { return false; }
	}
	
	/* If the following is executed if a is a substing of b.
	a is greater than b if the length of a is greater than length of b. */
	if(a.length() > b.length()) { return true; }
	
	return false;	
}

bool operator>=(const string & a, const string & b) {
	return !(a < b);
}

bool operator<=(const string & a, const string & b) {
	return !(a > b);
}
