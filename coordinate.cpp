#include "coordinate.h"

#include <string>
#include <algorithm>
#include <sstream>

Coordinate::Coordinate()
{
	x = y = 0;
}

Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}

Coordinate::Coordinate(const Coordinate& c)
{
	this->x = c.getX();
	this->y = c.getY();
}

void Coordinate::setX(int x)
{
	this->x = x;
}

void Coordinate::setY(int y)
{
	this->y = y;
}

int Coordinate::getX() const
{
	return x;
}

int Coordinate::getY() const
{
	return y;
}

std::ostream& operator << (std::ostream& out, Coordinate& c)
{
	out << "(" << c.getX() << ", " << c.getY() << ")";

	return out;
}

std::istream& operator >> (std::istream& in, Coordinate& c) throw (const char*)
{
	std::string line;
	std::getline(in, line);

	const char* ERROR = "Invalid coordinate input, must be '(x, y)' format where x and y are legal integers";

	int end = line.size() - 1;

	//Remove the parentheses and comma leaving a format of 'x y'
	if (line[0] == '(' && line[end] == ')' && line.find(',') != std::string::npos)
	{
		line.erase(end, 1);
		line.erase(0, 1);

		int pos = 0;

		for (pos; pos < line.size(); pos++)
		{
			if (line[pos] == ',')
				break;
		}

		line.erase(pos, 1);
	}
	else
		throw ERROR;

	//Check the coordinates...
	end = line.size() - 1;
	for (int i = 0; i < line.size(); i++)
	{
		if (!(isdigit(line[i]) || 
			 (line[i] == ' ')  || 
			 (line[i] == '-' && i != end && isdigit(line[i + 1]))))
		{
			throw ERROR;
		}
			
	}

	//parse with string stream
	std::stringstream ss(line);
	int x, y;
	ss >> x >> y;

	//set the retrieved values
	c.setX(x);
	c.setY(y);

	return in;
}