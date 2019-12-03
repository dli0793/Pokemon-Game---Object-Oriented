#ifndef GameObject_INCLUDE
#define GameObject_INCLUDE
#include <iostream>
#include "Point2D.h"
using namespace std;

class GameObject
{
	protected:
 	
	Point2D location; 
 	int id_num;
 	char display_code;
	char state;

	public:
	
	virtual ~GameObject();
	
	GameObject();
		
	GameObject(char );

	GameObject(Point2D , int , char );
	
 	Point2D GetLocation();

 	int GetId();

	char GetState();

	virtual void ShowStatus();
	
	virtual bool Update() = 0;
	
	virtual bool ShouldBeVisible() = 0;
	
	void DrawSelf(char * ptr);
};
#endif