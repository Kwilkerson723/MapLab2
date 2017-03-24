#include "Location.h"
#include <iostream>

using namespace std;


Location::Location(std::string name, int x, int y) : _name(name), x(x), y(y)
{
}


Location::~Location()
{
}

std::string Location::DisplayLocationInfo()
{
	return "Location is " + _name + " (" + to_string(x) + "," + to_string(y) + ")" + "\n";
}