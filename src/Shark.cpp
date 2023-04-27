#include "Shark.h"
#include <iostream>

Shark::Shark(const std::string& name, const Location& _location) : Animal(name)
{
	location.row = _location.row;
	location.column = _location.column;

	direction = (rand() % 8) + 1;

}

Shark::Shark(std::string state) :Animal(state)
{
}

Shark::Shark()
{
}

Shark::~Shark()
{
}


void Shark::printDetails() const
{
	std::cout << name << " Shark " << location;
}

char Shark::getInitial() const
{
	return 'S';
}

void Shark::step()
{
	if (state == "move") {

		if (direction == 1) {
			if (horizontal)
			{
				location.column = checkIsValid(location.column - 5);
				map[location.row][location.column] = "S";
				//location.column -= 5;
			}
			else
			{
				location.column = checkIsValid(location.column + 5);
				map[location.row][location.column] = "S";
				//location.column += 5;
			}

			//map[location.row][location.column + 5] = "S";
			//location.column += 5;

		}
		if (direction == 2) {
			if (vertical)
			{
				location.row = checkIsValid(location.row - 5);
				map[location.row][location.column] = "S";
				//location.row -= 5;
			}
			else
			{
				location.row = checkIsValid(location.row + 5);
				map[location.row][location.column] = "S";
				//location.row += 5;
			}
			//map[location.row + 5][location.column] = "S";
			//location.row += 5;

		}
		if (direction == 3) {
			if (vertical)
			{
				location.row = checkIsValid(location.row + 5);
				map[location.row][location.column] = "S";
				//location.row += 5;
			}
			else
			{
				location.row = checkIsValid(location.row - 5);
				map[location.row][location.column] = "S";
				//location.row -= 5;

			}
			//map[location.row - 5][location.column] = "S";
			//location.row -= 5;
		}
		if (direction == 4) {
			if (horizontal)
			{
				location.column = checkIsValid(location.column + 5);
				map[location.row][location.column] = "S";
				//location.column += 5;
			}
			else
			{
				location.column = checkIsValid(location.column - 5);
				map[location.row][location.column] = "S";
				//location.column -= 5;
			}
			//map[location.row][location.column - 5] = "S";
			//location.column -= 5;
		}
		if (direction == 5) {
			location.row = checkIsValid(location.row + 5);
			location.column = checkIsValid(location.column + 5);

			map[location.row][location.column] = "S";
			//location.row += 5;
			//location.column += 5;
		}
		if (direction == 6) {
			location.row = checkIsValid(location.row - 5);
			location.column = checkIsValid(location.column - 5);

			map[location.row][location.column] = "S";
			//location.row -= 5;
			//location.column -= 5;
		}
		if (direction == 7) {
			location.row = checkIsValid(location.row + 5);
			location.column = checkIsValid(location.column - 5);

			map[location.row][location.column] = "S";
			//location.row += 5;
			//location.column -= 5;
		}
		if (direction == 8) {
			location.row = checkIsValid(location.row - 5);
			location.column = checkIsValid(location.column + 5);

			map[location.row][location.column] = "S";
			//location.row -= 5;
			//location.column += 5;
		}
	}
}

void Shark::move()
{
	if (state == "stop")
	{
		state = "move";
		direction = (rand() % 8) + 1;
	}
}
