/* This is a header file for the zoo class that runs the game. */
#include <vector>
#include "Animal.h"
#include <string>

const int MAP_ROWS = 20;
const int MAP_COLS = 40;

class Zoo {

public:
	// Constructor
	Zoo();
	void run();

private:
	// A list that will contain the animal instances
	std::vector<Animal*> animalList;
	
	char map[20][40] = {};
	
	// The commands
	void stop(int numOfAnimal) const;
	void move(int numOfAnimal) const;
	void create(std::string name, std::string type);
	void del(int numOfAnimal);
	void delAll(std::string type);
	void help() const;
	void step();

	// Auxiliary functions
	Animal* factory(std::string, std::string, Location);
	Location randLocation();

	void printListAndMap();

	void stopCase();
	void moveCase();
	void createCase();
	void delCase();
	void delAllCase();
};
