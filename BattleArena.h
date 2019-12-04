#ifndef BattleArena_INCLUDE
#define BattleArena_INCLUDE
#include <iostream>
#include <string>
#include "Point2D.h"
#include "Vector2D.h"
#include "Building.h"
#include "GameObject.h"
using namespace std;

enum BattleArenaStates {
	RIVALS_AVAILABLE = 0,
	NO_RIVALS_AVAILABLE = 1
};


class BattleArena:public Building
{
	friend class Pokemon;
	
	private:
 	
	unsigned int max_num_rivals = 3;
	unsigned int num_rivals_remaining;
	double dollar_cost_per_fight;
	unsigned int stamina_cost_per_fight;
	unsigned int pokemon_count;

	public:
	
	BattleArena();
	BattleArena(unsigned int , unsigned int , double , int in_id, Point2D in_loc);//Building('A', in_id, in_loc);
	unsigned int GetNumRivalsRemaining();
	bool HasEnoughRivals();
	double GetDollarCost();
	unsigned int GetStaminaCost();
	bool IsAbleToFight(double , unsigned int );
	bool Update();
	bool IsBeaten();
	void ShowStatus();
	void RemoveRival();
};

#endif