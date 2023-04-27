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

Animal* animal;

Zoo::Zoo()
{


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			map[i][j] = 'x';
		}
	}

	Animal::Location loc;
	int rows = 20;
	int columns = 40;

	for (int i = 0; i < 3; i++)
	{
		int row = rand() % rows;
		int column = rand() % columns;
		loc.row = row;
		loc.column = column;

		if (i == 0)
		{
			map[row][column] = 'D';
			std::string location = std::to_string(row) + "," + std::to_string(column);
			lst[i].push_back(location);
			animalList.push_back(new Dog("Toto", loc));
		}

		if (i == 1)
		{
			map[row][column] = 'S';
			std::string location = std::to_string(row) + "," + std::to_string(column);
			lst[i].push_back(location);
			animalList.push_back(new Shark("Jaws", loc));
		}

		if (i == 2)
		{
			map[row][column] = 'C';
			std::string location = std::to_string(row) + "," + std::to_string(column);
			lst[i].push_back(location);
			animalList.push_back(new Clownfish("Nemo", loc));
		}

	}



}

void Zoo::run()
{
	std::string type;
	std::string name;
	int numOfAnimal;
	Animal::Location loc;
	bool found;
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
			try
			{
				found = false;
				std::cout << "Enter number of animal: ";
				std::cin >> numOfAnimal;
				std::string number = std::to_string(numOfAnimal);
				for (int i = 0; i < lst.size(); i++)
				{
					if (lst[i][0] == number)
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

			printListAndMap();
			break;
		case 2:
			try
			{
				found = false;
				std::cout << "Enter number of animal: ";
				std::cin >> numOfAnimal;
				std::string number = std::to_string(numOfAnimal);
				for (int i = 0; i < lst.size(); i++)
				{
					if (lst[i][0] == number)
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
			//std::cout << "Enter number of animal: ";
			//std::cin >> numOfAnimal;
			//move(numOfAnimal);
			printListAndMap();
			break;
		case 3:
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



			printListAndMap();
			break;
		case 4:
			try
			{
				found = false;
				std::cout << "Enter number of animal: ";
				std::cin >> numOfAnimal;
				std::string number = std::to_string(numOfAnimal);
				for (int i = 0; i < lst.size(); i++)
				{
					if (lst[i][0] == number)
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
			///*std::cout << "Enter number of animal: ";
			//std::cin >> numOfAnimal;
			//del(numOfAnimal);*/
			printListAndMap();
			break;
		case 5:
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

			printListAndMap();
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

void Zoo::stop(int numOfAnimal) const
{
	Animal* animal;
	std::string animalNum = std::to_string(numOfAnimal);
	int index;

	for (int i = 0; i < lst.size(); i++)
	{

		if (lst[i][0] == animalNum)
		{
			index = numOfAnimal - 1;
			animal = animalList[index];
			animal->stop();
			break;
			
		}

	}
}

void Zoo::move(int numOfAnimal) const
{

	Animal* animal;
	std::string animalNum = std::to_string(numOfAnimal);
	int index;

	for (int i = 0; i < lst.size(); i++)
	{

		if (lst[i][0] == animalNum)
		{
			index = numOfAnimal - 1;
			animal = animalList[index];
			animal->move();
			break;
			

		}
	}
}

void Zoo::create(std::string  name, std::string type)
{

	Animal::Location loc;
	Animal* animal;


	int rows = 20;
	int columns = 40;

	int row = rand() % rows;
	int column = rand() % columns;

	std::string location = std::to_string(row) + "," + std::to_string(column);

	size_t num = lst.size() + 1;
	std::stringstream ss;
	ss << num;
	std::vector<std::string> newAnimal = { ss.str(), type,name, location };

	lst.push_back(newAnimal);
	loc.column = column;
	loc.row = row;
	animal = factory(ss.str(), type, name, loc);
	map[row][column] = animal->getInitial();

}

void Zoo::del(int numOfAnimal)
{
	Animal* animal;
	bool flag = false;
	int number;
	int index;

	std::vector<std::string> out;
	std::string animalNum = std::to_string(numOfAnimal);
	for (int i = 0; i < lst.size(); i++)
	{
		if (lst[i][0] == animalNum)
		{

			tokenizer(lst[i][3], ',', out);
			map[stoi(out[0])][stoi(out[1])] = 'x';
			lst.erase(lst.begin() + i);
			index = numOfAnimal - 1;
			animal = animalList[index];
			animalList.erase(animalList.begin() + index);
			delete animal;
			flag = true;
		}

		if (flag && i < lst.size())
		{
			number = stoi(lst[i][0]);
			number -= 1;
			lst[i][0] = std::to_string(number);
		}

	}

}

void Zoo::delAll(std::string type)
{
	std::vector<std::string> out;
	bool flag = false;

	int i = 0;
	while (i < lst.size())
	{

		if (lst[i][2] == type)
		{
			del(stoi(lst[i][0]));
			i -= 1;
		}
		i += 1;
	}

}

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

//
void Zoo::step()
{
	Animal::Location loc;
	std::vector<std::string> out;
	std::string location;

	for (int i = 0; i < lst.size(); i++)
	{

		tokenizer(lst[i][3], ',', out);
		loc.row = stoi(out[0]);
		loc.column = stoi(out[1]);
		map[loc.row][loc.column] = 'x';
		animal = factory(lst[i][0], lst[i][1], lst[i][2], loc);
		animal->step();
		loc = animal->getLocation();
		map[loc.row][loc.column] = animal->getInitial();
		location = std::to_string(loc.row) + "," + std::to_string(loc.column);
		lst[i].pop_back();
		lst[i].push_back(location);
		out.clear();


	}
}

Animal* Zoo::factory(std::string number, std::string name, std::string type, Animal::Location location)
{
	int numberOfAnimal = stoi(number);
	int index;

	if (numberOfAnimal > animalList.size())
	{
		if (type == "Dog")
			animalList.push_back(new Dog(name, location));
		if (type == "Shark")
			animalList.push_back(new Shark(name, location));
		if (type == "Clownfish")
			animalList.push_back(new Clownfish(name, location));
		return animalList.back();
	}

	index = numberOfAnimal - 1;
	return animalList[index];

}

Animal::Location Zoo::randLocation()
{
	Animal::Location loc;
	int rows = 20;
	int columns = 40;

	int row = rand() % rows;
	int column = rand() % columns;

	loc.column = column;
	loc.row = row;

	return loc;
}
void Zoo::printListAndMap()
{

	std::cout << "                                 Welcome to the Zoo!  " << std::endl;
	std::cout << "   +-------------------------------------------------------------------------------+" << std::endl;

	for (int i = 0; i < 20; i++) {
		// print the first character as part of the opener.
		if (i < 10)
			std::cout << " " << i << " |" << map[i][0];
		else
			std::cout << " " << i << "|" << map[i][0];
		for (int j = 1; j < 40; j++) {
			// only add spaces for subsequent characters.

			std::cout << " " << map[i][j];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "   +-------------------------------------------------------------------------------+" << std::endl;


	//print the list
	for (int i = 0; i < lst.size(); i++)
	{
		std::cout << lst[i][0] << " ";
		animalList[i]->printDetails();


	}
}

void Zoo::tokenizer(std::string str, const char delim, std::vector<std::string>& out)
{
	// construct a stream from the string
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}



