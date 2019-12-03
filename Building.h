#ifndef Building_INCLUDE
#define Building_INCLUDE
#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
using namespace std;

class Building:public GameObject
{
	private:
 	
	unsigned int pokemon_count = 0;
	
	public:
	
	~Building();
	Building();
 	Building(char in_code, int in_id, Point2D in_loc);
		
	void AddOnePokemon();

	void RemoveOnePokemon();
	
 	void ShowStatus();

 	bool ShouldBeVisible();

};
#endif