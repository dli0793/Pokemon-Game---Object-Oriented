#ifndef Rival_INCLUDE
#define Rival_INCLUDE
#include <iostream>
#include <string>
#include "Point2D.h"
#include "Vector2D.h"
#include "Building.h"
#include "GameObject.h"
#include "BattleArena.h"
using namespace std;

enum RivalStates 
{
	ALIVE_RIVAL = 0,
	FAINTED_RIVAL = 1
};

class Rival:public GameObject
{
	
	private:
 	
	double speed;
	string name;
	
	protected:
	
	double health = 20;
	double physical_damage = 5;
	double magical_damage = 4;
	double defense = 15;
	bool is_in_arena;
	BattleArena* current_arena;

	public:
	
	Rival(string , double , double , double ,double , double , int id, Point2D in_loc);//:GameObject(in_loc,id,'R'));
	void TakeHit(double , double , double );
	double get_phys_dmg();
	double get_magic_dmg();
	double get_defense();
	double get_health();
	bool Update(); 
	void ShowStatus();
	bool IsAlive();
	bool ShouldBeVisible();

};

#endif