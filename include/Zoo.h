/* This is a header file for the zoo class that runs the game. */
#include <vector>
#include "Animal.h"
#include <string>

class Zoo {

public:
	// Constructor
	Zoo();
	void run();

private:
	// A list that will contain the animal instances
	std::vector<Animal*> animalList;
	
	char map[20][40] = {};
	
	// The initial list
	std::vector<std::vector<std::string>> lst{
		std::vector<std::string>{"1","Toto", "Dog"},
		std::vector<std::string>{"2","Jaws", "Shark"},
		std::vector<std::string>{"3","Nemo", "Clownfish"}};

	// The commands
	void stop(int numOfAnimal) const;
	void move(int numOfAnimal) const;
	void create(std::string name, std::string type);
	void del(int numOfAnimal);
	void delAll(std::string type);
	void help() const;
	void step();

	// Auxiliary functions
	Animal* factory(std::string, std::string, std::string, Animal::Location);
	Animal::Location randLocation();

	void printListAndMap();
	void tokenizer(std::string str, const char delim, std::vector<std::string>& out);
};
