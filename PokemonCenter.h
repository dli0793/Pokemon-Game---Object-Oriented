#ifndef PokemonCenter_INCLUDE
#define PokemonCenter_INCLUDE
#include <iostream>
#include "Point2D.h"
#include "Building.h"
#include "GameObject.h"
using namespace std;

enum PokemonCenterStates 
{
	STAMINA_POINTS_AVAILABLE = 0,
	NO_STAMINA_POINTS_AVAILABLE = 1
};

class PokemonCenter:public Building
{
	friend class Pokemon;
	//friend class Model;
	
	private:
 	
	unsigned int stamina_capacity;
	unsigned int num_stamina_points_remaining = stamina_capacity;
	double dollar_cost_per_stamina_point;
	
	public:
	
	~PokemonCenter();
	PokemonCenter();
 	PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc);
		
	bool HasStaminaPoints();

	unsigned int GetNumStaminaPointsRemaining();
	
	bool CanAffordStaminaPoints(unsigned int , double );
	
	double GetDollarCost(unsigned int );
	
	unsigned int DistributeStamina(unsigned int );
	
	bool Update();
	
	void ShowStatus();
	
};
#endif