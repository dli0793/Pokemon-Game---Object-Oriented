#ifndef Model_INCLUDE
#define Model_INCLUDE
#include <algorithm> 
#include <iostream>
#include <list>
#include <string>
#include "Point2D.h"
#include "Vector2D.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Building.h"
#include "GameObject.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
using namespace std;

class Model
{
	private:
 	
	int time;
	
	list <Pokemon*> pokemon_ptrs;
	//int num_pokemon;
	list <PokemonCenter*> center_ptrs;
	//int num_centers;
	list <PokemonGym*> gym_ptrs;
	//int num_gyms;
	list <Rival*> rival_ptrs;
	//int num_rivals;
	list <GameObject*> object_ptrs;
	list <GameObject*> active_ptrs;
	//int num_objects;
	list <BattleArena*> arena_ptrs;
	//int num_arenas;
	//Model(const Model& );
	
	public:
	
	Model();
	~Model();
	Pokemon * GetPokemonPtr(int id);
	PokemonCenter * GetPokemonCenterPtr(int id);
	PokemonGym * GetPokemonGymPtr(int id);
	Rival * GetRivalPtr(int id);
	BattleArena * GetArenaPtr(int id);
	bool Update();
	void Display(View& view);
	void ShowStatus();
	bool AllGymsBeaten();
	bool AllPokemonExhausted();

};



#endif