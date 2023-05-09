/* This is a header file for struct location containing row and column and supporting operations. */
#ifndef LOCATION_HEADER
#define LOCATION_HEADER
#pragma once

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

};

#endif