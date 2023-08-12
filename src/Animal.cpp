/* This is a cpp file for the Animal abstract base class. */
#include "Animal.h"
#include <string>

// Constructor
Animal::Animal(std::string name, Location loc) :name(name)
{
	this->location.row = loc.row;
	this->location.column = loc.column;

}

/* Returns the location of the animal. */
Location Animal::getLocation() const
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

std::string Animal::toString() const
{
	return type;
}

/* A non-member helper function that checks if the index of moving the animal in the map is valid,
  if not the animal will stop.*/
int checkIsValid(int index, std::string rowOrColumn)
{
	if (index < 0)
		return 0;

	if (index > 39 && rowOrColumn == COLUMNS)
		return 39;

	if (index > 19 && rowOrColumn == ROWS)
		return 19;
	return index;
}