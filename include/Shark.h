#include "Animal.h" 
#include <string>
class Shark : public Animal {

public:
	Shark(const std::string&, const Location&);
	Shark(std::string);
	~Shark();

	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void move() override;



};

