/* This is a cpp file for a child class that represents a Dog*/
#include "Dog.h"
#include <iostream>

// Constructor
Dog::Dog(const std::string& name, const Location& _location) : Animal(name)
{
	location.row = _location.row;
	location.column = _location.column;

	direction = (rand() % 2) + 1;
}

// Destructor
Dog::~Dog()
{
}

/* Prints the name of the animal, its type and location. */
void Dog::printDetails() const
{
	std::cout << name << " Dog " << location;
}

/* Returns the first letter of the class name. */
char Dog::getInitial() const
{
	return 'D';
}

/* Causes the animal to advance a step (according to the rules), provided the animal is currently moving.*/
void Dog::step()
{
	if (state == "move")
	{
		if (status == "run") {

			if (direction == 1) {
				if (horizontal) {
					location.column = checkIsValid(location.column - 3, "column");
		
					dir = "col";
				}
				else
				{
					location.column = checkIsValid(location.column + 3, "column");
		
					dir = "col";
				}

			}
			else {
				if (vertical)
				{
					location.row = checkIsValid(location.row - 3, "row");
			
					dir = "row";
				}
				else
				{
					location.row = checkIsValid(location.row + 3, "row");
					
					dir = "row";
				}
			}

			status = "back";
		}

		else {
			if (dir == "col") {
				location.column -= 1;
			}
			else {
				
				location.row -= 1;
			}
			status = "run";
		}

	}
}

/* Causes the animal to go into movement mode, meaning that if we now call step() it will indeed move. */
void Dog::move()
{
	if (state == "stop")
	{
		state = "move";
		direction = (rand() % 2) + 1;
	}

}
