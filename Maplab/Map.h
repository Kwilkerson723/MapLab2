#pragma once
#include <stack>
#include <string>
#include "Location.h"
class Map
{
private:
	std::stack<Location *> _locationsVisited;
	//create another stack for queue later
public:
	Map(std::string startLocationName);
	~Map();
	//std::stack<Location *> _location;
	Location * CurrentLocation = nullptr;
	std::string GetPathBackToHome();
	void Move(Location *newLocation);
};