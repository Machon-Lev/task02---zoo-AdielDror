/* This is a cpp file for struct location containing row and column and supporting operations. */
#include <iostream>
#include "Location.h"

// Operator << (print)
std::ostream& operator<<(std::ostream& os, const Location& loc)
{
	os << loc.row << "," << loc.column << std::endl;
	return os;
}


// Operator ==
bool Location::operator==(Location const& rhs) const
{
	return (this->row == rhs.row) && (this->column == rhs.column);
}

// Operator !=
bool Location::operator!=(Location const& rhs) const
{
	return !(*this == rhs);
}

// Operator + 
Location Location::operator+(const Location& rhs) const
{
	return Location(rhs.row + row, rhs.column + column);
}
//Operator +=
Location& Location::operator+=(const Location& rhs)
{
	this->row += rhs.row;
	this->column += rhs.column;
	return *this;
}
