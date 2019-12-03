#ifndef Model_INCLUDE
#define Model_INCLUDE
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
#include "View.h"
using namespace std;

class Model
{
	private:
 	
	int time;
	
	
	Pokemon * pokemon_ptrs[10];
	int num_pokemon;
	PokemonCenter * center_ptrs[10];
	int num_centers;
	PokemonGym* gym_ptrs[10];
	int num_gyms;
	GameObject * object_ptrs[10];
	int num_objects;
	//Model(const Model& );
	
	public:
	
	
	Model();
	~Model();
	Pokemon * GetPokemonPtr(int id);
	PokemonCenter * GetPokemonCenterPtr(int id);
	PokemonGym * GetPokemonGymPtr(int id);
	bool Update();
	void Display(View& view);
	void ShowStatus();
	bool AllGymsBeaten();
	bool AllPokemonExhausted();

};



#endif