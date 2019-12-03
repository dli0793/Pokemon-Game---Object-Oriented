#ifndef View_INCLUDE
#define View_INCLUDE
#include <algorithm> 
#include <iostream>
#include <string>
#include "Point2D.h"
#include "Vector2D.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Building.h"
#include "GameObject.h"
//#include "Model.h"
//#include "GameCommand.h"
using namespace std;


const int view_maxsize = 20;
class View
{
	private:
 	
	int size;
	double scale;
	Point2D origin;
	char grid[view_maxsize][view_maxsize][2];
	bool GetSubscripts(int& , int& , Point2D );
	
	public:
	
	View();
	void Clear();
	void Plot(GameObject * ptr);
	void Draw();

};



#endif