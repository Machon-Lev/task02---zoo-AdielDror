#include "Animal.h"
#include <string>
class Dog : public Animal{
public:
	Dog(const std::string&, const Location&);
	Dog(std::string);
	Dog();

	~Dog();

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void move() override;

private:
 std::string status = "run";
	


};