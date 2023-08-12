/* This is a header file for a child class that represents a Shark.*/
#include "Animal.h" 
#include <string>
class Shark : public Animal {

public:
	Shark(const std::string&, const Location&);
	~Shark();

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void move() override;
};

