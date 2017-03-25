#include <iostream>
#include <unordered_map>
#include "Map.h"
//
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
void PathHome(Map &map);

int main()
{
	//unordered_map<string, string> worldMap; //example
	//store x and y in a string with a comma
	//second string should be the name of the location
	// check to see if locations exist if it doesnt exist add it to the hash table 
	/*table.insert("0,0", myLocPointer);
	table.insert("0,1", myLocPointer); ect 	*/
	//worldMap.

	auto map = Map("Home");
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go west" << endl;
		cout << "6) Path To Home" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo(); break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: system("cls");  cout << PathHome << endl;  break;
		default: cout << "Enter a valid option"; break;
		}
		system("pause");
	}

	return 0;
}

void GoNorth(Map &map)
{
	auto newLocation = map.CurrentLocation->North;
	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin.ignore();
		getline(cin, name);
		//cin >> name;
		newLocation = new Location(name,map.CurrentLocation->x,map.CurrentLocation->y+1); //figure out how to add this to a unordered map,key and value
		cout << "This place is now called: " + name << endl;

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->South = map.CurrentLocation;
	map.Move(newLocation);
	return;
}

void GoEast(Map &map)
{
	auto newLocation = map.CurrentLocation->East;
	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin.ignore();
		getline(cin, name);
		//cin >> name;
		newLocation = new Location(name, map.CurrentLocation->x+1, map.CurrentLocation->y);
		cout << "This place is now called: " + name << endl;

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->West = map.CurrentLocation;
	map.Move(newLocation);
	return;
	//TODO: Implement This
}

void GoSouth(Map &map)
{
	auto newLocation = map.CurrentLocation->South;
	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin.ignore();
		getline(cin, name);
		//cin >> name;
		newLocation = new Location(name, map.CurrentLocation->x, map.CurrentLocation->y-1);
		cout << "This place is now called: " + name << endl;

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->North = map.CurrentLocation;
	map.Move(newLocation);
	return;
	//TODO: Implement This
}

void GoWest(Map &map)
{
	auto newLocation = map.CurrentLocation->West;
	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin.ignore();
		getline(cin, name);
		//cin >> name;
		newLocation = new Location(name, map.CurrentLocation->x-1, map.CurrentLocation->y);
		cout << "This place is now called: " + name << endl;

	}
	else
	{
		cout << "You are at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->East = map.CurrentLocation;
	map.Move(newLocation);
	return;
	//TODO: Implement This
}

void PathHome(Map &map)
{
	
	while (!map.path.empty())
	{
		
		cout << map.path.top()->DisplayLocationInfo() << endl; 
		map.path.pop();
	
	
	}

	return;
}