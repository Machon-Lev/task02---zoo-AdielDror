#include <vector>
#include "Animal.h"
#include <string>

class Zoo {

public:
	Zoo();
	void run();

private:
	std::vector<Animal*> animalList;
	char map[20][40] = {};
	std::vector<std::vector<std::string>> lst{
		std::vector<std::string>{"1","Toto", "Dog"},
		std::vector<std::string>{"2","Jaws", "Shark"},
		std::vector<std::string>{"3","Nemo", "Clownfish"}};

	void stop(int numOfAnimal) const;
	void move(int numOfAnimal) const;
	void create(std::string name, std::string type);
	void del(int numOfAnimal);
	void delAll(std::string type);
	void help() const;
	void step();



	Animal* factory(std::string, std::string, std::string, Animal::Location);
	Animal::Location randLocation();

	void printListAndMap();
	void tokenizer(std::string str, const char delim, std::vector<std::string>& out);
};
