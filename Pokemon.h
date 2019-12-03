#ifndef Pokemon_INCLUDE
#define Pokemon_INCLUDE
#include <algorithm> 
#include <iostream>
#include <string>
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Building.h"
#include "GameObject.h"
using namespace std;

enum PokemonStates 
{
	STOPPED = 0,
	MOVING = 1,
	EXHAUSTED = 2,
	IN_GYM = 3,
	IN_CENTER = 4,
	MOVING_TO_GYM = 5,
	MOVING_TO_CENTER = 6,
	TRAINING_IN_GYM = 7,
	RECOVERING_STAMINA = 8,
	IN_ARENA = 9,
	MOVING_TO_ARENA = 10,
	BATTLE = 11,
	FAINTED = 12
};

class Pokemon:public GameObject
{
	
	private:
 	
	double speed;
	bool is_in_gym = false;
	bool is_in_center = false;;
	unsigned int stamina;
	unsigned int experience_points = 0;
	double pokemon_dollars = 0;
	unsigned int training_units_to_buy = 0;
	unsigned int stamina_points_to_buy = 0;
	string name;
	PokemonCenter* current_center = NULL;
	PokemonGym* current_gym = NULL;
	Point2D destination;
	Vector2D delta;
	
	protected:
	bool UpdateLocation();
	void SetupDestination(Point2D );
	double health = 20;
	double store_health = health;
	double physical_damage = 5;
	double magical_damage = 4;
	double defense = 15;
	Rival* target;
	bool is_in_arena;
	BattleArena * current_arena;

	public:
	
	virtual ~Pokemon();
	Pokemon();
	Pokemon(char in_code);
 	Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
	void StartMoving(Point2D dest);
	void StartMovingToCenter(PokemonCenter* center);
	void StartMovingToGym(PokemonGym* gym);
	void StartTraining(unsigned int num_training_units);
	void StartRecoveringStamina(unsigned int num_stamina_points);
 	void Stop();
	bool isExhausted();
	bool ShouldBeVisible();
	void ShowStatus();
	bool Update();
	string GetName();
	Pokemon(string , double , double , double , double , double , int in_id, char , Point2D in_loc ):GameObject(in_loc,in_id,'P');
	bool IsAlive();
	void TakeHit(double , double , double );
	void ReadyBattle(Rival *in_target);
	bool StartBattle();

};

static double GetRandomAmountofPokemonDollars();

#endif