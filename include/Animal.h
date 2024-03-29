#ifndef Animal_HEADER
#define Animal_HEADER

/* This is a header file for the Animal abstract base class. */
#include <iostream>
#include <Location.h>

const std::string ROWS = "rows";
const std::string COLUMNS = "columns";

class Animal {

protected:
    std::string name;
	std::string state = "move";
	int direction = 0;
	std::string dir;
	bool vertical = false;
	bool horizontal =  false;
	bool flag =  false;
	Location location;
	std::string type;

public:
	// Constructor and destructor
	Animal(std::string name, Location loc);
	virtual ~Animal()=default;

	inline virtual void printDetails() const = 0;
	inline virtual char getInitial() const = 0;
	virtual Location getLocation() const;
	inline virtual void step() = 0;
	void stop();
	inline virtual void move() = 0;
	inline virtual void turnVertically();
	inline virtual void turnHorizontally();	

	std::string toString() const;
	
};

int checkIsValid(int index, std::string rowOrColumn);
#endif