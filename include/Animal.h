#ifndef Animal_HEADER
#define Animal_HEADER

/* This is a header file for the Animal abstract base class. */
#include <iostream>


class Animal {

protected:
    std::string name;
	std::string state = "move";
	int direction = 0;
	std::string dir;
	bool vertical = false;
	bool horizontal =  false;
	bool flag =  false;


public:
	// Constructor and destructor
	Animal(std::string name);
	virtual ~Animal()=default;

	struct Location
	{
		int row;
		int column;

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const Location& loc);
		bool operator==(Location const& rhs) const;
		bool operator!=(Location const& rhs) const;
		Location operator+(const Location& rhs) const;
		Location& operator+=(const Location& rhs);

	}location = { 0 ,0 };

	inline virtual void printDetails() const = 0;
	inline virtual char getInitial() const = 0;
	virtual Location getLocation() const;
	inline virtual void step() = 0;
	void stop();
	inline virtual void move() = 0;
	inline virtual void turnVertically();
	inline virtual void turnHorizontally();	
};

int checkIsValid(int index, std::string rowOrColumn);
#endif