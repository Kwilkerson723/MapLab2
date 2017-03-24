#include "Map.h"
#include <iostream>
using namespace std;


Map::Map(string startLocationName)
{
	CurrentLocation = new Location(startLocationName,0,0);
	path.push(CurrentLocation);
	string hash = "(0,0)";
	_mapHash[hash] = CurrentLocation;
}


Map::~Map()
{
}

void Map::Move(Location *newLocation)
{
	_locationsVisited.push(newLocation);
	CurrentLocation = newLocation;
}

Location * Map::LocationLookUp(int x, int y)
{
	std::string hash = "(" + to_string(x) + "," + to_string(y) + ")";
	return _mapHash[hash];
}

/*std::string Map::GetPathBackToHome()
{
	path.push(CurrentLocation);
	
	return path.top()->DisplayLocationInfo; //"TODO: Implement this"
}*/