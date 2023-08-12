/* This is a cpp file for a child class that represents a Clownfish. */
#include "Clownfish.h"
#include <iostream>

// Constructor
Clownfish::Clownfish(const std::string& name, const Location& _location) :Animal(name, _location) {

	direction = (rand() % 8) + 1;
	type = "Clownfish";
}

// Destructor
Clownfish::~Clownfish()
{
}

/* Prints the name of the animal, its typeand location. */
void Clownfish::printDetails() const
{
	std::cout << name << " Clownfish " << location;
}

/* Returns the first letter of the class name. */
char Clownfish::getInitial()  const 
{
	return 'C';
}

/* Causes the animal to advance a step (according to the rules), provided the animal is currently moving. */
void Clownfish::step()
{
	if (state == "move") {
		if (direction == 1) {
			if (horizontal)
			{	
				location.column = checkIsValid(location.column - 1, "columns");	
			}
			else
			{
				location.column = checkIsValid(location.column + 1, "columns");	
			}
		}
		if (direction == 2) {
			if (vertical)
			{
				location.row = checkIsValid(location.row - 1, "rows");
			}
			else
			{
				location.row = checkIsValid(location.row + 1, "rows");
			}
		}
		if (direction == 3) {
			if (vertical)
			{
				location.row = checkIsValid(location.row + 1, "rows");
			}
			else
			{
				location.row = checkIsValid(location.row - 1, "rows");
			}
		}
		if (direction == 4) {
			if (horizontal)
			{
				location.column = checkIsValid(location.column +1, "columns");
			}
			else
			{
				location.column = checkIsValid(location.column - 1, "columns");
			}
		}
		if (direction == 5) {
			location.row = checkIsValid(location.row + 1, "rows");
			location.column = checkIsValid(location.column + 1, "columns");
		}
		if (direction == 6) {
			location.row = checkIsValid(location.row - 1, "rows");
			location.column = checkIsValid(location.column - 1, "columns");
		}
		if (direction == 7) {
			location.row = checkIsValid(location.row + 1, "rows");
			location.column = checkIsValid(location.column - 1, "columns");
		}
		if (direction == 8) {
			location.row = checkIsValid(location.row - 1, "rows");
			location.column = checkIsValid(location.column + 1, "columns");
		}
	}
}

/* Causes the animal to go into movement mode, meaning that if we now call step() it will indeed move. */
void Clownfish::move()
{
	if (state == "stop")
	{
	state = "move";
	direction = (rand() % 8) + 1;
	}
}
