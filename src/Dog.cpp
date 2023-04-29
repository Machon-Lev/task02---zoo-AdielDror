#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name, const Location& _location) : Animal(name)
{
	location.row = _location.row;
	location.column = _location.column;

	direction = (rand() % 2) + 1;
}

Dog::~Dog()
{
}

void Dog::printDetails() const
{
	std::cout << name << " Dog " << location;
}

char Dog::getInitial() const
{
	return 'D';
}

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

void Dog::move()
{
	if (state == "stop")
	{
		state = "move";
		direction = (rand() % 2) + 1;
	}

}
