/* This is a cpp file for a child class that represents a Shark. */
#include "Shark.h"
#include <iostream>

// Constructor
Shark::Shark(const std::string& name, const Location& _location) : Animal(name, _location)
{
	direction = (rand() % 8) + 1;
	type = "Shark";
}

// Destructor
Shark::~Shark()
{
}

/* Prints the name of the animal, its type and location. */
void Shark::printDetails() const
{
	std::cout << name << " Shark " << location;
}

/* Returns the first letter of the class name. */
char Shark::getInitial() const
{
	return 'S';
}

/* Causes the animal to advance a step (according to the rules), provided the animal is currently moving. */
void Shark::step()
{
	if (state == "move") {

		if (direction == 1) {
			if (horizontal)
			{
				location.column = checkIsValid(location.column - 5, "columns");
			}
			else
			{
				location.column = checkIsValid(location.column + 5, "columns");
			}
		}
		if (direction == 2) {
			if (vertical)
			{
				location.row = checkIsValid(location.row - 5, "rows");
			}
			else
			{
				location.row = checkIsValid(location.row + 5, "rows");
			}
		}
		if (direction == 3) {
			if (vertical)
			{
				location.row = checkIsValid(location.row + 5, "rows");
			}
			else
			{
				location.row = checkIsValid(location.row - 5, "rows");
			}
		}
		if (direction == 4) {
			if (horizontal)
			{
				location.column = checkIsValid(location.column + 5, "columns");
			}
			else
			{
				location.column = checkIsValid(location.column - 5, "columns");
			}
		}
		if (direction == 5) {
			location.row = checkIsValid(location.row + 5, "rows");
			location.column = checkIsValid(location.column + 5, "columns");		
		}
		if (direction == 6) {
			location.row = checkIsValid(location.row - 5, "rows");
			location.column = checkIsValid(location.column - 5, "columns");
		}
		if (direction == 7) {
			location.row = checkIsValid(location.row + 5, "rows");
			location.column = checkIsValid(location.column - 5, "columns");
		}
		if (direction == 8) {
			location.row = checkIsValid(location.row - 5, "rows");
			location.column = checkIsValid(location.column + 5, "columns");
		}
	}
}

/* Causes the animal to go into movement mode, meaning that if we now call step() it will indeed move. */
void Shark::move()
{
	if (state == "stop")
	{
		state = "move";
		direction = (rand() % 8) + 1;
	}
}
