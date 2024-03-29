/* This is a header file for a child class that represents a Clownfish.*/
#include "Animal.h"
#include <string>
class Clownfish : public Animal  {

public:
	Clownfish(const std::string&, const Location&);
	~Clownfish();

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void move() override;
};