#pragma once
#include <stack>
#include <string>
#include "Location.h"
#include <unordered_map>



class Map
{
private:
	std::stack<Location *> _locationsVisited;
	std::unordered_map<std::string, Location *> _mapHash;
	//create another stack for queue later
public:
	Map(std::string startLocationName);
	~Map();
	std::stack<Location *> path;
	Location *CurrentLocation = nullptr;
	
	//std::string GetPathBackToHome();  
	
	void Move(Location *newLocation);
	Location * LocationLookUp(int x, int y);
	
};