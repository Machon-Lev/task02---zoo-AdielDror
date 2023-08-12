/* This is a header file for a child class that represents a Dog. */
#include "Animal.h"
#include <string>
class Dog : public Animal{

public:
	Dog(const std::string&, const Location&);
	~Dog();

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void move() override;

private:
 std::string status = "run";

};