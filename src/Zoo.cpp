/* This is a cpp file for the zoo class that runs the game.*/
#include "Zoo.h"
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <Dog.h>
#include <Shark.h>
#include <Clownfish.h>
#include <sstream>
#include <list>

// Constructor
Zoo::Zoo()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			map[i][j] = '-';
		}
	}

	// Initialize animal list
	std::vector<std::string> animalTypes = { "Dog", "Shark", "Clownfish" };

	for (int i = 0; i < animalTypes.size(); i++)
	{
	
		Location loc = randLocation();

		switch (i)
		{
		case 0:
			map[loc.row][loc.column] = 'D';
			animalList.push_back(new Dog("Toto", loc));
			break;
		case 1:
			map[loc.row][loc.column] = 'S';
			animalList.push_back(new Shark("Jaws", loc));
			break;
		case 2:
			map[loc.row][loc.column] = 'C';
			animalList.push_back(new Clownfish("Nemo", loc));
			break;
		}
	}
}

/* The main function that is activated from the main. */
void Zoo::run()
{

	std::list<std::string> classes = { "Dog", "Shark", "Clownfish" };

	printListAndMap();

	int choice;
	do
	{
		std::cout << std::endl;
		std::cout << "0 - Exit." << std::endl;
		std::cout << "1 - Stop." << std::endl;
		std::cout << "2 - Move." << std::endl;
		std::cout << "3 - Create." << std::endl;
		std::cout << "4 - Del." << std::endl;
		std::cout << "5 - DelAll." << std::endl;
		std::cout << "6 - Help." << std::endl;
		std::cout << "7 - ." << std::endl;

		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 0: break;
		case 1:
			stopCase();
			break;
		case 2:
			moveCase();
			break;
		case 3:
			createCase();
			break;
		case 4:
			delCase();
			break;
		case 5:
			delAllCase();
			break;
		case 6:
			help();
			printListAndMap();
			break;
		case 7:
			step();
			printListAndMap();
			break;

		default:
			std::cout << "The command does not exist, try again!\n";
			break;
		}

	} while (choice != 0);
}

/* Accepts as a parameter the number of the animal.
   This animal will not move from here on out, unless the move command is applied to it again */
void Zoo::stop(int numOfAnimal) const
{
	Animal* animal;

	for (int i = 0; i < animalList.size(); ++i)
	{
		if (numOfAnimal == i + 1)
		{
			animal = animalList[i];
			animal->stop();
			break;

		}
	}
}

/* Accepts as a parameter the number of the animal.
   The command has meaning only if the animal has stopped before. When the animal starts to move, it resets its direction.*/
void Zoo::move(int numOfAnimal) const
{
	Animal* animal;

	for (int i = 0; i < animalList.size(); ++i)
	{
		if (numOfAnimal == i + 1)
		{
			animal = animalList[i];
			animal->move();
			break;
		}
	}
}

/* Creating another animal. Accepts as parameters the type of animal and a name for it.
   The location of the animal will be randomly drawn.*/
void Zoo::create(std::string  name, std::string type)
{
	Animal* animal;
	Location loc = randLocation();

	animal = factory(type, name, loc);
	map[loc.row][loc.column] = animal->getInitial();

}

/* Deleting an animal from the list. Accepts as a parameter the number of the animal. */
void Zoo::del(int numOfAnimal)
{
	Animal* animal;

	for (int i = 0; i < animalList.size(); i++)
	{
		if (numOfAnimal == i + 1)
		{
			map[animalList[i]->getLocation().row][animalList[i]->getLocation().column] = '-';
			animal = animalList[i];
			animalList.erase(animalList.begin() + i);
			delete animal;
			break;
		}
	}
}

/* Deleting all animals of a certain type.
   Accepts as a parameter the type of animal and will delete from the list all animals of this type. */
void Zoo::delAll(std::string type)
{
	int i = 0;
	while (i < animalList.size())
	{

		if (animalList[i]->toString() == type)
		{
			del(i + 1);
			i -= 1;
		}
		i += 1;
	}
}

/* Printing help text that explains what the possible commands are, what their parameters are and what they do. */
void Zoo::help() const
{
	const char* text = "\nstop - make the animal stop. The command will receive as a parameter the number of the animal."
		"\n       This animal will not move from here on, unless the move command is applied to it again.\n"

		"\nmove - make the animal move.The command will receive as a parameter the number of the animal."
		"\n       The command has meaning only if the animal has stopped before. When the animal starts moving,"
		"\n       it reset its direction.\n"

		"\ncreate - creating another animal. The command will receive as parameters the type of animal and a name for it."
		"\n         The location of the animal will be randomly drawn.\n"

		"\ndel - deleting an animal from the list. The command will receive as a parameter the number of the animal.\n"

		"\ndelAll - deleting all animals of a certain type. The command will receive as a parameter the type of animal"
		"\n         and will delete from the list all animals of this type(if they exist).\n"

		"\n. - this command will be used to make the program advance to the next queue, without changing anything."
		"\n   That is, all animals in motion continue to move according to the rules.\n"

		"\nexit - leaving the program.\n";
	std::cout << text << std::endl;

}

/* Used to make the program advance to the next turn, without changing anything.
   That is, all animals in motion continue to move according to the rules. */
void Zoo::step()
{
	Animal* animal;
	Location loc;

	for (int i = 0; i < animalList.size(); ++i)
	{
		animal = animalList[i];
		loc.row = animal->getLocation().row;
		loc.column = animal->getLocation().column;
		map[loc.row][loc.column] = '-';
		animal->step();
		loc = animal->getLocation();
		map[loc.row][loc.column] = animal->getInitial();
	}
}

/* A helper function that receives the number of the animal, its name, the type and the location
  and checks according to the number of the animal if its instance exists, if not creates it, and in any case returns it.*/
Animal* Zoo::factory(std::string name, std::string type, Location newLocation)
{
	if (type == "Dog")
		animalList.push_back(new Dog(name, newLocation));
	if (type == "Shark")
		animalList.push_back(new Shark(name, newLocation));
	if (type == "Clownfish")
		animalList.push_back(new Clownfish(name, newLocation));
	return animalList.back();
}

/* Helper function that returns location, row and column number, random .*/
Location Zoo::randLocation()
{
	Location loc;

	int row = rand() % MAP_ROWS;
	int column = rand() % MAP_COLS;

	loc.column = column;
	loc.row = row;

	return loc;
}

/* Printing the list and the map. */
void Zoo::printListAndMap()
{
	// Print the map
	std::cout << "                                 Welcome to the Zoo!  " << std::endl;
	std::cout << "   +-------------------------------------------------------------------------------+" << std::endl;

	for (int i = 0; i < 20; i++) {
		// Print the first character as part of the opener.
		if (i < 10)
			std::cout << " " << i << " |" << map[i][0];
		else
			std::cout << " " << i << "|" << map[i][0];
		for (int j = 1; j < 40; j++) {
			// Only add spaces for subsequent characters.
			std::cout << " " << map[i][j];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "   +-------------------------------------------------------------------------------+" << std::endl;


	// Print the list
	for (int i = 0; i < animalList.size(); i++)
	{
		std::cout << i + 1 << " ";
		animalList[i]->printDetails();
	}
}

/* Helper function for case of stop. */
void Zoo::stopCase()
{
	int numOfAnimal;
	bool found;
	try
	{
		found = false;
		std::cout << "Enter number of animal: ";
		std::cin >> numOfAnimal;

		for (int i = 0; i < animalList.size(); i++)
		{
			if (i + 1 == numOfAnimal)
			{
				found = true;
				stop(numOfAnimal);
				break;
			}
		}
		if (!found)
			throw numOfAnimal;
	}
	catch (const int number)
	{
		std::cout << "Animal number " << number << " does not exist!\n\n";
	}
	step();
	printListAndMap();
}

/* Helper function for case of move. */
void Zoo::moveCase()
{
	int numOfAnimal;
	bool found;
	try
	{
		found = false;
		std::cout << "Enter number of animal: ";
		std::cin >> numOfAnimal;

		for (int i = 0; i < animalList.size(); i++)
		{
			if (i + 1 == numOfAnimal)
			{
				found = true;
				move(numOfAnimal);
				break;
			}
		}
		if (!found)
			throw numOfAnimal;
	}
	catch (const int number)
	{
		std::cout << "Animal number " << number << " does not exist!\n\n";
	}
	step();
	printListAndMap();
}

/* Helper function for case of create. */
void Zoo::createCase()
{
	std::string type;
	std::string name;
	bool found;
	std::list<std::string> classes = { "Dog", "Shark", "Clownfish" };
	try
	{
		std::cout << "Enter type of animal: ";
		std::cin >> type;
		found = (std::find(classes.begin(), classes.end(), type) != classes.end());
		if (found)
		{
			std::cout << "Enter name of animal: ";
			std::cin >> name;
			create(type, name);
		}
		else
		{
			throw (type);
		}
	}
	catch (const std::string type)
	{
		std::cout << "Invalid " << type << " type, try again!\n\n";
	}
	step();
	printListAndMap();
}

/* Helper function for case of delete. */
void Zoo::delCase()
{
	int numOfAnimal;
	bool found;
	try
	{
		found = false;
		std::cout << "Enter number of animal: ";
		std::cin >> numOfAnimal;

		for (int i = 0; i < animalList.size(); i++)
		{
			if (i + 1 == numOfAnimal)
			{
				found = true;
				del(numOfAnimal);
				break;
			}
		}
		if (!found)
			throw numOfAnimal;
	}
	catch (const int number)
	{
		std::cout << "Animal number " << number << " does not exist!\n\n";
	}
	step();
	printListAndMap();
}

/* Helper function for case of delete all. */
void Zoo::delAllCase()
{
	std::string type;
	bool found;
	std::list<std::string> classes = { "Dog", "Shark", "Clownfish" };

	try
	{
		std::cout << "Enter type of animal: ";
		std::cin >> type;
		found = (std::find(classes.begin(), classes.end(), type) != classes.end());
		if (found)
		{
			delAll(type);
		}
		else
		{
			throw (type);
		}
	}
	catch (const std::string type)
	{
		std::cout << "Invalid " << type << " type, try again!\n\n";
	}
	step();
	printListAndMap();
}



