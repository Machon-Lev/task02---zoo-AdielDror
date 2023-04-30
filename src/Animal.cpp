/* This is a cpp file for the Animal abstract base class. */
#include "Animal.h"
#include <string>

// Constructor
Animal::Animal(std::string name) :name(name)
{
}

/* Returns the location of the animal. */
Animal::Location Animal::getLocation() const
{
	return location;
}

/* Causes the animal to stop, so that further calls to step() will not cause it to move. */
void Animal::stop()
{
	state = "stop";
}

/* Causes the animal to change vertical direction 
  (ie, if it was moving up, start moving down, and vice versa), without changing speed.*/
void Animal::turnVertically()
{
	if (!flag)
	{
		vertical = true;
		flag = true;
	}
	else
	{
		vertical = false;
		flag = false;
	}
}

/* Causes the animal to change horizontal direction (ie, if it was moving to the right, start moving to the left, and vice versa), without changing speed. */
void Animal::turnHorizontally()
{
	if (!flag)
	{
		horizontal = true;
		flag = true;
	}
	else
	{
		horizontal = false;
		flag = false;
	}
}

// Operator << (print)
std::ostream& operator<<(std::ostream& os, const Animal::Location& loc)
{
	os << loc.row << "," << loc.column << std::endl;
	return os;
}

// Operator ==
bool Animal::Location::operator==(Location const& rhs) const
{
	return (this->row == rhs.row) && (this->column == rhs.column);
}

// Operator !=
bool Animal::Location::operator!=(Location const& rhs) const
{
	return !(*this == rhs);
}

// Operator + 
Animal::Location Animal::Location::operator+(const Location& rhs) const
{
	return Location(rhs.row+row, rhs.column+column);
}
 //Operator +=
Animal::Location& Animal::Location::operator+=(const Location& rhs)
{
	this->row += rhs.row;
	this->column += rhs.column;
	return *this;
}

/* A non-member helper function that checks if the index of moving the animal in the map is valid,
  if not the animal will stop.*/
int checkIsValid(int index, std::string rowOrColumn)
{
	if (index < 0)
		return 0;

	if (index > 39 && rowOrColumn == "column")
		return 39;

	if (index > 19 && rowOrColumn == "row")
		return 19;
	return index;
}