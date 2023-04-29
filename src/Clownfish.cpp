#include "Clownfish.h"
#include <iostream>

Clownfish::Clownfish(const std::string& name, const Location& _location) :Animal(name) {

	location.column = _location.column;
	location.row = _location.row;

	direction = (rand() % 8) + 1;
}

Clownfish::~Clownfish()
{
}

void Clownfish::printDetails() const
{
	std::cout << name << " Clownfish " << location;
}

char Clownfish::getInitial()  const 
{
	return 'C';
}

void Clownfish::step()
{
	if (state == "move") {
		if (direction == 1) {
			if (horizontal)
			{
				
				location.column = checkIsValid(location.column - 1, "column");
				
			}
			else
			{
				
				location.column = checkIsValid(location.column + 1, "column");
				
			}


		}
		if (direction == 2) {
			if (vertical)
			{
				location.row = checkIsValid(location.row - 1, "row");
			
			}
			else
			{
				location.row = checkIsValid(location.row + 1, "row");
			
			}


		}
		if (direction == 3) {
			if (vertical)
			{
				location.row = checkIsValid(location.row + 1, "row");
		
			
			}
			else
			{
				location.row = checkIsValid(location.row - 1, "row");
			

			}


		}
		if (direction == 4) {
			if (horizontal)
			{
			
				location.column = checkIsValid(location.column +1, "column");

			}
			else
			{
				
				location.column = checkIsValid(location.column - 1, "column");
		
			}


		}
		if (direction == 5) {
			location.row = checkIsValid(location.row + 1, "row");
			location.column = checkIsValid(location.column + 1, "column");

		}
		if (direction == 6) {
			location.row = checkIsValid(location.row - 1, "row");
			location.column = checkIsValid(location.column - 1, "column");


		}
		if (direction == 7) {
			location.row = checkIsValid(location.row + 1, "row");
			location.column = checkIsValid(location.column - 1, "column");
	
		}
		if (direction == 8) {
			location.row = checkIsValid(location.row - 1, "row");
			location.column = checkIsValid(location.column + 1, "column");

		}
	}
}

void Clownfish::move()
{
	if (state == "stop")
	{
	state = "move";
	direction = (rand() % 8) + 1;
	}
}
