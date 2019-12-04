#include <iostream>
#include "Model.h"
#include <string>
#include <iterator>
using namespace std;

Model::Model()
{
	time = 0;
	Pokemon* Pokemon1 = new Pokemon("Pikachu",2.0,23.0,3.0,6.0,12.0,1,'P',Point2D(5,1));
	object_ptrs.push_back(Pokemon1);
	active_ptrs.push_back(Pokemon1);
	pokemon_ptrs.push_back(Pokemon1);
	
	Pokemon* Pokemon2 = new Pokemon("Bulbasaur",1.0,26.0,4.0,3.7,16.0,2,'P',Point2D(10, 1));
	object_ptrs.push_back(Pokemon2);
	active_ptrs.push_back(Pokemon2);
	pokemon_ptrs.push_back(Pokemon2);
	
	PokemonCenter* PokemonCenter1 = new PokemonCenter(1,1,100,Point2D(1, 20));
	object_ptrs.push_back(PokemonCenter1);
	active_ptrs.push_back(PokemonCenter1);
	center_ptrs.push_back(PokemonCenter1);

	PokemonCenter* PokemonCenter2 = new PokemonCenter(2,2,200,Point2D(10, 20));
	object_ptrs.push_back(PokemonCenter2);
	active_ptrs.push_back(PokemonCenter2);
	center_ptrs.push_back(PokemonCenter2);
	
	PokemonGym* PokemonGym1 = new PokemonGym(10,1,2,3,1,Point2D(0,0));
	object_ptrs.push_back(PokemonGym1);
	active_ptrs.push_back(PokemonGym1);
	gym_ptrs.push_back(PokemonGym1);
	
	PokemonGym* PokemonGym2 = new PokemonGym(20,5,7.5,8,2,Point2D(5,5));
	object_ptrs.push_back(PokemonGym2);
	active_ptrs.push_back(PokemonGym2);
	gym_ptrs.push_back(PokemonGym2);
	
	Rival* Rival1 = new Rival("burhack",1.0,16.0,3.0,7.2,20.0,1,Point2D(15,12)); //battlearena location
	object_ptrs.push_back(Rival1);
	active_ptrs.push_back(Rival1);
	rival_ptrs.push_back(Rival1);
	
	Rival* Rival2 = new Rival("mmark9",2.0,29.0,4.0,5.2,12.0,2,Point2D(15,12));
	object_ptrs.push_back(Rival2);
	active_ptrs.push_back(Rival2);
	rival_ptrs.push_back(Rival2);
	
	Rival* Rival3 = new Rival("Densmore(aka BigBoss)",2.0,41.0,6.0,8.2,18.0,3,Point2D(15,12));
	object_ptrs.push_back(Rival3);
	active_ptrs.push_back(Rival3);
	rival_ptrs.push_back(Rival3);
	
	BattleArena* BattleArena1 = new BattleArena(3,3,2.5,1,Point2D(15,12));
	object_ptrs.push_back(BattleArena1);
	active_ptrs.push_back(BattleArena1);
	arena_ptrs.push_back(BattleArena1);
	
	/* num_objects = 8;
	num_pokemon = 2; 
	num_centers = 2; 
	num_gyms = 2;
	num_arenas = 1;
	num_rivals = 3; */
	cout << "Model default constructed.\n";
}

Model::~Model()
{
	/* for(int i=0;i<6 this->num_objects ;i++)
	{
		delete object_ptrs[i];
	} 
	*/
	list <GameObject*> :: iterator it; 
    for(it=object_ptrs.begin();it!=object_ptrs.end();++it) 
    {
		delete *it; 
	}
	cout << "Model destructed.\n";
}

Pokemon* Model::GetPokemonPtr(int id)
{
	/* for(int i=0;i<2/* this->num_pokemon ;i++)
	{
		if(pokemon_ptrs[i]->GetId()==id)
			return pokemon_ptrs[i];
	} */
	list <Pokemon*> :: iterator it; 
    for(it=pokemon_ptrs.begin();it!=pokemon_ptrs.end();++it) 
    {
		if((*it)->GetId()==id)
			return *it;		
	}
	return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	/* for(int i=0;i<2/* this->num_centers ;i++)
	{
		if((*center_ptrs[i]).GetId()==id)
			return center_ptrs[i];
	} */
	list <PokemonCenter*> :: iterator it; 
    for(it=center_ptrs.begin();it!=center_ptrs.end();++it) 
    {
		if((*it)->GetId()==id)
			return *it;		
	}
	return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
	/* for(int i=0;i<2/* this->num_gyms ;i++)
	{
		if((*gym_ptrs[i]).GetId()==id)
			return gym_ptrs[i];
	} */
	list <PokemonGym*> :: iterator it; 
    for(it=gym_ptrs.begin();it!=gym_ptrs.end();++it) 
    {
		if((*it)->GetId()==id)
			return *it;		
	}
	return 0;
}

BattleArena* Model::GetArenaPtr(int id)
{
	/* for(int i=0;i<1;i++)
	{
		if((*arena_ptrs[i]).GetId()==id)
			return arena_ptrs[i];
	} */
	list <BattleArena*> :: iterator it; 
    for(it=arena_ptrs.begin();it!=arena_ptrs.end();++it) 
    {
		if((*it)->GetId()==id)
			return *it;		
	}
	return 0;
}

Rival* Model::GetRivalPtr(int id)
{
	/* for(int i=0;i<2;i++)
	{
		if((*rival_ptrs[i]).GetId()==id)
			return rival_ptrs[i];
	} */
	list <Rival*> :: iterator it; 
    for(it=rival_ptrs.begin();it!=rival_ptrs.end();++it) 
    {
		if((*it)->GetId()==id)
			return *it;		
	}
	return 0;
}

bool Model::Update()
{
	time++;
	/* for(int i=0;i<6/* this->num_objects ;i++)
	{
		if((*object_ptrs[i]).Update())
			return true;
	} */
	list <GameObject*> :: iterator it; 
    for(it=active_ptrs.begin();it!=active_ptrs.end();++it) 
    {
		if((*it)->Update())
			return true;
		if(dynamic_cast<Pokemon*>(*it)!=nullptr||dynamic_cast<Rival*>(*it)!=nullptr)
		{
			if(dynamic_cast<Pokemon*>(*it)!=nullptr)
			{
				if(!(dynamic_cast<Pokemon*>(*it))->IsAlive())
				{
					active_ptrs.remove((*it));
					cout << "Dead object removed.\n";
				}
			}
			if(dynamic_cast<Rival*>(*it)!=nullptr)
			{
				if(!(dynamic_cast<Rival*>(*it))->IsAlive())
				{
					active_ptrs.remove((*it));
					cout << "Dead object removed.\n";
				}
			}
		}
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
	/* for(int i=0;i<6/* this->num_objects ;i++)
	{
		(this->object_ptrs[i])->ShowStatus();
	} */
	list <GameObject*> :: iterator it; 
    for(it=object_ptrs.begin();it!=object_ptrs.end();++it) 
    {
		(*it)->ShowStatus();
	}
}

void Model::Display(View& view)
{
	/* for(int i = 0;i<6;i++)
	{
		view.Plot(object_ptrs[i]);
	} */
	list <GameObject*> :: iterator it; 
    for(it=active_ptrs.begin();it!=active_ptrs.end();++it) 
    {
		view.Plot(*it);	
	}
} 

bool Model::AllGymsBeaten()
{
	/* for(int i=0;i<2/* this->num_gyms ;i++)
	{
		if(!(this->gym_ptrs[i])->IsBeaten())
			return false;
	} */
	list <PokemonGym*> :: iterator it; 
    for(it=gym_ptrs.begin();it!=gym_ptrs.end();++it) 
    {
		if(!(*it)->IsBeaten())
			return false;		
	}
	return true;
}

bool Model::AllPokemonExhausted()
{
	/* for(int i=0;i<2/* this->num_pokemon ;i++)
	{
		if(!(this->pokemon_ptrs[i])->isExhausted())
			return false;
	} */
	list <Pokemon*> :: iterator it; 
    for(it=pokemon_ptrs.begin();it!=pokemon_ptrs.end();++it) 
    {
		if(!(*it)->isExhausted())
			return false;		
	}
	return true;
}
