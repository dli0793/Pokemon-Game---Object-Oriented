#include <iostream>
#include "Building.h"
//#include "GameObject.h"
using namespace std;

Building::~Building()
{
	cout << "Building destructed.\n";
}

Building::Building()
{
	//GameObject('B');
	display_code = 'B';
	cout << "Building default constructed.\n";
}

Building::Building(char in_code, int in_id, Point2D in_loc)
{
	id_num = in_id;
	display_code = in_code;
	location = in_loc; 
	cout << "Building constructed.\n";
}  

void Building::AddOnePokemon()
{
	pokemon_count+=1;
}

void Building::RemoveOnePokemon()
{
	pokemon_count-=1;
}
	
void Building::ShowStatus()
{
	cout << display_code << id_num << " located at " << location <<endl;
	cout << "    " << pokemon_count << " pokemon(s) located in this building" << endl;
}

bool Building::ShouldBeVisible()
{
	return true;
}
