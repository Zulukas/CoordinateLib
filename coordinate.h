#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate {
public:
	Coordinate();
	Coordinate(int, int);
	Coordinate(const Coordinate&);

	void setX(int);
	void setY(int);

	int getX() const;
	int getY() const;

private:
	int x, y;
};

std::ostream& operator << (std::ostream&, Coordinate&);
std::istream& operator >> (std::istream&, Coordinate&) throw (const char*);

#endif