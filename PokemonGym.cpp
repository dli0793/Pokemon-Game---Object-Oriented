#include <iostream>
#include "PokemonGym.h"
using namespace std;

PokemonGym::~PokemonGym()
{
	cout << "PokemonGym destructed.\n";
}

PokemonGym::PokemonGym()
{
	display_code = 'G';
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1.0;
	experience_points_per_training_unit = 2;
	state = NOT_BEATEN;
	cout << "PokemonGym default constructed." << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc)
{
	display_code = 'G';
	max_number_of_training_units = max_training_units;
	num_training_units_remaining = max_training_units;	
	stamina_cost_per_training_unit = stamina_cost;
	experience_points_per_training_unit = exp_points_per_unit;
	dollar_cost_per_training_unit = dollar_cost; 
	location = in_loc;
	id_num = in_id;
	cout << "PokemonGym constructed.\n";
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
	return unit_qty*dollar_cost_per_training_unit;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
	return unit_qty*stamina_cost_per_training_unit;
}
	
unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
	return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
	if(GetDollarCost(unit_qty)<=budget&&GetStaminaCost(unit_qty)<=stamina)
		return true;
	else
		return false;
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
	if((num_training_units_remaining-training_units)>=0)
	{
		num_training_units_remaining-=training_units;
		return training_units*experience_points_per_training_unit;
	}		
	
	if((num_training_units_remaining-training_units)<0)
	{	
		num_training_units_remaining = 0;
		return num_training_units_remaining*experience_points_per_training_unit;
	}
}

bool PokemonGym::Update()
{
	if(num_training_units_remaining==0)
	{
		state = BEATEN;
		display_code = 'g'; 
		cout << display_code << id_num << " has been beaten.\n"; 
		return true; 
	}
	else
		return false;
}

bool PokemonGym::IsBeaten()
{
	if(num_training_units_remaining==0)
		return true;
	else
		return false;
}

void PokemonGym::ShowStatus()
{
	cout << "Pokemon Gym Status: ";
	Building::ShowStatus(); 
	cout << "    Max number of training units: " << max_number_of_training_units << endl;
	cout << "    Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
	cout << "    Pokemon dollar cost per training unit: " << dollar_cost_per_training_unit << endl;
	cout << "    Experience points per training unit: " << experience_points_per_training_unit << endl;
	cout << "    " << num_training_units_remaining << " training units are remaining for this gym" <<endl;
}