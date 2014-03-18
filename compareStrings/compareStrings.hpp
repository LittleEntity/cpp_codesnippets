#ifndef COMPARABLE_HPP
#define COMPARABLE_HPP

#include <string>

bool operator<(const std::string & a, const std::string & b);
bool operator>(const std::string & a, const std::string & b);
bool operator>=(const std::string & a, const std::string & b);
bool operator<=(const std::string & a, const std::string & b);
bool isEqual(const std::string & a, const std::string & b);
bool isUnequal(const std::string & a, const std::string & b);

#endif // COMPARABLE_HPP
