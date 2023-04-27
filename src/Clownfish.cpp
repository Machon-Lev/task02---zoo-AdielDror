#include "Clownfish.h"
#include <iostream>

Clownfish::Clownfish(const std::string& name, const Location& _location) :Animal(name) {

	location.column = _location.column;
	location.row = _location.row;

	direction = (rand() % 8) + 1;
}

Clownfish::Clownfish(std::string state) : Animal(state)
{
}

Clownfish::Clownfish()
{
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
				
				location.column = checkIsValid(location.column - 1);
				map[location.row][location.column] = "C";
				//location.column -= 1;
			}
			else
			{
				
				location.column = checkIsValid(location.column + 1);
				map[location.row][location.column] = "C";
				//location.column += 1;
			}


		}
		if (direction == 2) {
			if (vertical)
			{
				location.row = checkIsValid(location.row - 1);
				
				map[location.row][location.column] = "C";
				//location.row -= 1;
			}
			else
			{
				location.row = checkIsValid(location.row + 1);
			
				map[location.row][location.column] = "C";
				//location.row += 1;
			}


		}
		if (direction == 3) {
			if (vertical)
			{
				location.row = checkIsValid(location.row + 1);
		
				map[location.row][location.column] = "C";
				//location.row += 1;
			}
			else
			{
				location.row = checkIsValid(location.row - 1);
				
				map[location.row][location.column] = "C";
				//location.row -= 1;

			}


		}
		if (direction == 4) {
			if (horizontal)
			{
			
				location.column = checkIsValid(location.column +1);

				map[location.row][location.column] = "C";
				//location.column += 1;
			}
			else
			{
				
				location.column = checkIsValid(location.column - 1);
				map[location.row][location.column] = "C";
				//location.column -= 1;
			}


		}
		if (direction == 5) {
			location.row = checkIsValid(location.row + 1);
			location.column = checkIsValid(location.column + 1);

			map[location.row][location.column] = "C";
			//location.row += 1;
			//location.column += 1;
		}
		if (direction == 6) {
			location.row = checkIsValid(location.row - 1);
			location.column = checkIsValid(location.column - 1);

			map[location.row][location.column] = "C";
			//location.row -= 1;
			//location.column -= 1;

		}
		if (direction == 7) {
			location.row = checkIsValid(location.row + 1);
			location.column = checkIsValid(location.column - 1);

			map[location.row][location.column] = "C";
			//location.row += 1;
			//location.column -= 1;
		}
		if (direction == 8) {
			location.row = checkIsValid(location.row - 1);
			location.column = checkIsValid(location.column + 1);

			map[location.row][location.column] = "C";
			//location.row -= 1;
			//location.column += 1;
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
