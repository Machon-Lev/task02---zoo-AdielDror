#include "Animal.h"
#include <string>


Animal::Animal(std::string name) :name(name)
{
}

Animal::Location Animal::getLocation() const
{
	return location;
}



void Animal::stop()
{
	state = "stop";
}



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


std::ostream& operator<<(std::ostream& os, const Animal::Location& loc)
{

	os << loc.row << "," << loc.column << std::endl;
	return os;
}


bool Animal::Location::operator==(Location const& rhs) const
{
	return (this->row == rhs.row) && (this->column == rhs.column);
}

bool Animal::Location::operator!=(Location const& rhs) const
{
	return !(*this == rhs);
}

Animal::Location Animal::Location::operator+(const Location& rhs) const
{
	return Location(rhs.row+row, rhs.column+column);
}

Animal::Location& Animal::Location::operator+=(const Location& rhs)
{
	this->row += rhs.row;
	this->column += rhs.column;
	return *this;
}

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