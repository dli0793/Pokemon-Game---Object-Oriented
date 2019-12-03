#include <iostream>
#include "Model.h"
#include <string>
using namespace std;

Model::Model()
{
	time = 0;
	Pokemon* Pokemon1 = new Pokemon("Pikachu",1,20,5,4,15,2,'P',Point2D(5,1));
	object_ptrs[0] = Pokemon1;
	pokemon_ptrs[0] = Pokemon1;
	
	Pokemon* Pokemon2 = new Pokemon("Bulbasaur",2,20,5,4,15,1,'P',Point2D(10, 1));
	object_ptrs[1] = Pokemon2;
	pokemon_ptrs[1] = Pokemon2;
	
	PokemonCenter* PokemonCenter1 = new PokemonCenter(1,1,100,Point2D(1, 20));
	object_ptrs[2] = PokemonCenter1;
	center_ptrs[0] = PokemonCenter1;

	PokemonCenter* PokemonCenter2 = new PokemonCenter(2,2,200,Point2D(10, 20));
	object_ptrs[3] = PokemonCenter2;
	center_ptrs[1] = PokemonCenter2;
	
	PokemonGym* PokemonGym1 = new PokemonGym(10,1,2,3,1,Point2D(0,0));
	object_ptrs[4] = PokemonGym1;
	gym_ptrs[0] = PokemonGym1;
	
	PokemonGym* PokemonGym2 = new PokemonGym(20,5,7.5,8,2,Point2D(5,5));
	object_ptrs[5] = PokemonGym2;
	gym_ptrs[1] = PokemonGym2;
	
	num_objects = 6;
	num_pokemon = 2; 
	num_centers = 2; 
	num_gyms = 2;
	cout << "Model default constructed.\n";
}

Model::~Model()
{
	for(int i=0;i<6/* this->num_objects */;i++)
	{
		delete object_ptrs[i];
	}
	cout << "Model destructed.\n";
}

Pokemon* Model::GetPokemonPtr(int id)
{
	for(int i=0;i<2/* this->num_pokemon */;i++)
	{
		if(pokemon_ptrs[i]->GetId()==id)
			return pokemon_ptrs[i];
	}
	return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	for(int i=0;i<2/* this->num_centers */;i++)
	{
		if((*center_ptrs[i]).GetId()==id)
			return center_ptrs[i];
	}
	return 0;
}
PokemonGym* Model::GetPokemonGymPtr(int id)
{
	for(int i=0;i<2/* this->num_gyms */;i++)
	{
		if((*gym_ptrs[i]).GetId()==id)
			return gym_ptrs[i];
	}
	return 0;
}

bool Model::Update()
{
	time++;
	for(int i=0;i<6/* this->num_objects */;i++)
	{
		if((*object_ptrs[i]).Update())
			return true;
	}
	
	
	if(AllGymsBeaten())
	{
		cout << "GAME OVER: You win! All Pokemon Gyms beaten!\n";
		exit(0);
	}
	
	if(AllPokemonExhausted())
	{
		cout << "GAME OVER: You lose! All of your Pokemon are tired!\n";
		exit(0);
	}
	
	return false;
}

void Model::ShowStatus()
{
	cout << "Time: " << time <<endl;
	for(int i=0;i<6/* this->num_objects */;i++)
	{
		(this->object_ptrs[i])->ShowStatus();
	}
}

void Model::Display(View& view)
{
	for(int i = 0;i<6;i++)
	{
		view.Plot(object_ptrs[i]);
	}
} 

bool Model::AllGymsBeaten()
{
	for(int i=0;i<2/* this->num_gyms */;i++)
	{
		if(!(this->gym_ptrs[i])->IsBeaten())
			return false;
	}
	return true;
}

bool Model::AllPokemonExhausted()
{
	for(int i=0;i<2/* this->num_pokemon */;i++)
	{
		if(!(this->pokemon_ptrs[i])->isExhausted())
			return false;
	}
	return true;
}
