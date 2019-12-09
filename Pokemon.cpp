#include <iostream>
#include <string>
#include <algorithm> 
#include <math.h>
#include <stdlib.h>   
#include <time.h> 
#include "Pokemon.h"
#include "Point2D.h"
#include "Vector2D.h"
using namespace std;

Pokemon::~Pokemon()
{
	cout << "Pokemon destructed.\n";
}

Pokemon::Pokemon()
{
	speed = 5;
	stamina = 20;
	current_arena = NULL;
	current_gym = NULL;
	current_center = NULL;
	cout << "Pokemon default constructed." << endl;
}

Pokemon::Pokemon(char in_code)
{
	speed = 5;
	state = STOPPED;
	display_code = in_code;
	stamina = 20;
	current_arena = NULL;
	current_gym = NULL;
	current_center = NULL;
	cout << "Pokemon constructed.\n";
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
{
	speed = in_speed;
	name = in_name;
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	stamina = 20;
	state = STOPPED;
	current_arena = NULL;
	current_gym = NULL;
	current_center = NULL;
	cout << "Pokemon constructed.\n";
}

void Pokemon::StartMoving(Point2D dest)
{
	SetupDestination(dest);
/* 	if(state!=MOVING_TO_GYM&&state!=MOVING_TO_CENTER)
		state = MOVING; */
	if((this->GetLocation().x==dest.x)&&(this->GetLocation().y==dest.y))
		cout << display_code << id_num << ": I'm already there. See?\n";
	else if(isExhausted())
	{
		cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me.\n";
		state = EXHAUSTED;
	}
	else
	{
		cout << display_code << id_num << ": On my way. ";
		state = MOVING;
	}
}
	
void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
	SetupDestination((*center).location);
	current_center = center;
	//state = MOVING_TO_CENTER;
	if(isExhausted())
	{
		state = EXHAUSTED;
		cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina...\n";
	}
	else if((location.x==(*center).location.x)&&(location.y==(*center).location.y))
		cout << display_code << id_num << ": I'm already at the Pokemon Center!\n";
	else
	{
		cout << display_code << id_num << ": On my way to center " << (*center).id_num << endl;
		state = MOVING_TO_CENTER;
	}
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
	SetupDestination((*gym).location);
	current_gym = gym;
	//state = MOVING_TO_GYM;
	if(isExhausted())
	{
		cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the gym...\n";
		state = EXHAUSTED;
	}
	else if((location.x==(*gym).location.x)&&(location.y==(*gym).location.y))
		cout << display_code << id_num << ": I'm already at the Pokemon Gym!\n";
	else
	{
		cout << display_code << id_num << ": On my way to gym " << (*gym).id_num << endl;
		state = MOVING_TO_GYM;
	}
}

void Pokemon::StartMovingToArena(BattleArena* arena)
{
	SetupDestination((*arena).location);
	current_arena = arena;
	if(isExhausted())
	{
		cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the arena...\n";
		state = EXHAUSTED;
	}
	else if((location.x==(*arena).location.x)&&(location.y==(*arena).location.y))
		cout << display_code << id_num << ": I'm already at the Pokemon Battle Arena!\n";
	else
	{
		cout << display_code << id_num << ": On my way to arena " << (*arena).id_num << endl;
		state = MOVING_TO_ARENA;
	}
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
	if(is_in_gym)
	{
		state = TRAINING_IN_GYM;
		if(!isExhausted() && is_in_gym && (*current_gym).IsAbleToTrain(num_training_units, pokemon_dollars, stamina) && !(*current_gym).IsBeaten())
		{
			cout << display_code << id_num << ": Started to train at Pokemon Gym " << (*current_gym).id_num << " with " << num_training_units << " training units\n";
			training_units_to_buy = min(num_training_units,(*current_gym).num_training_units_remaining);
		}
		else if(isExhausted())
		{
			cout << display_code << id_num << ": I am exhausted so no more training for me...\n";
			state = EXHAUSTED;
		}
		else if(!(*current_gym).IsAbleToTrain(num_training_units, pokemon_dollars, stamina))
			cout << display_code << id_num << ": Not enough stamina and/or money for training\n";
		else if((*current_gym).IsBeaten())
			cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already beaten!\n";
	}
	else
		cout << display_code << id_num << ": I can only train in a Pokemon Gym!\n";
	
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
	if(is_in_center)
	{
		state = RECOVERING_STAMINA;
		
		if((*current_center).CanAffordStaminaPoints(num_stamina_points, pokemon_dollars) && (*current_center).HasStaminaPoints() && is_in_center)
		{
			cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina point(s) " << " at PokemonCenter " << (*current_center).id_num <<endl;
			stamina_points_to_buy = min(num_stamina_points,(*current_center).num_stamina_points_remaining);
		}
		else if(isExhausted())
		{
			cout << display_code << id_num << ": I am too exhausted to even recover...\n";
			state = EXHAUSTED;
		}
		else if(!(*current_center).CanAffordStaminaPoints(num_stamina_points, pokemon_dollars))
			cout << display_code << id_num << ": Not enough money to recover stamina.\n";
	
		else if(!(*current_center).HasStaminaPoints())
			cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center.\n";
	}
	else 
		cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!\n";	
}

void Pokemon::Stop()
{
	state = STOPPED;
	cout << display_code << id_num << ": Stopping...\n";
}

bool Pokemon::isExhausted()
{
	if(stamina==0)
	{
		state = EXHAUSTED;
		return true;
	}
	else
		return false;
}

bool Pokemon::ShouldBeVisible()
{
	if(!isExhausted())
		return true;
	else
		return false;
}

void Pokemon::ShowStatus()
{
	cout << name << " status: \n";
	GameObject::ShowStatus(); 
	switch(state)
	{
		case STOPPED:
			cout << " stopped\n";
			break;
		case MOVING:
			cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta;
			break;
		case MOVING_TO_CENTER:
			cout << " heading to Pokemon Center" << (*current_center).id_num << " at a speed of " << speed << " at each step of " << delta;
			break;
		case MOVING_TO_GYM:
			cout << " heading to Pokemon Gym" << (*current_gym).id_num << " at a speed of " << speed << " at each step of " << delta;
			break;
		case MOVING_TO_ARENA:
			cout << " heading to Battle Arena" << (*current_arena).id_num << " at a speed of " << speed << " at each step of " << delta;
			break;
		case IN_CENTER:
			cout << " inside Pokemon Center " << (*current_center).id_num << endl;
			break;
		case IN_GYM:
			cout << " inside Pokemon Gym " << (*current_gym).id_num << endl;
			break;
		case IN_ARENA:
			cout << " inside Battle Arena " << (*current_arena).id_num << endl;
			break;
		case TRAINING_IN_GYM:
			cout << " training in Pokemon Gym " << (*current_gym).id_num << endl;
			break;
		case RECOVERING_STAMINA:
			cout << " recovering stamina in Pokemon Center " << (*current_center).id_num << endl;
			break;
		case BATTLE:
			cout << " battling in Battle Arena " << (*current_arena).id_num << endl;
			break;
		case FAINTED:
			break;
		case EXHAUSTED:
			break;	
		default:
			cout << "Error" << endl;
			break;
	}
	cout << "    Stamina: " << stamina << endl;
	cout << "    Pokemon Dollars: " << pokemon_dollars << endl;
	cout << "    Experience Points: " << experience_points << endl;
	cout << "    Health: " << health << endl;
	cout << "    Physical Damage: " << physical_damage << endl;
	cout << "    Magical Damage: " << magical_damage << endl;
	cout << "    Defense: " << defense << endl;
}

bool Pokemon::Update()
{
	unsigned int old2;
	unsigned int old;
	if(isExhausted())
		state = EXHAUSTED;
	if(!IsAlive())
		state = FAINTED;
	switch(state)
	{
		case STOPPED:
			return false;
			break;
		case MOVING:
			//UpdateLocation();
			if(UpdateLocation())
			{
				state = STOPPED;
				return true;
			}
			else
			{
				state = MOVING;
				stamina-=1;
				pokemon_dollars+=GetRandomAmountofPokemonDollars();
				if(is_in_center)
				{
					is_in_center = false;
					current_center->RemoveOnePokemon();
				}
				if(is_in_gym)
				{
					is_in_gym = false;
					current_gym->RemoveOnePokemon();
				}
				if(is_in_arena)
				{
					is_in_arena = false;
					current_arena->RemoveOnePokemon();
				}
				return false;				
			}
			break;
		case MOVING_TO_CENTER:
			//UpdateLocation();
			if(UpdateLocation())
			{
				state = IN_CENTER;
				is_in_center = true;
				current_center->AddOnePokemon();
				return true;
			}
			else
			{
				state = MOVING_TO_CENTER;
				stamina-=1;
				pokemon_dollars+=GetRandomAmountofPokemonDollars();
				if(is_in_center)
				{
					is_in_center = false;
					current_center->RemoveOnePokemon();
				}
				if(is_in_gym)
				{
					is_in_gym = false;
					current_gym->RemoveOnePokemon();
				}
				if(is_in_arena)
				{
					is_in_arena = false;
					current_arena->RemoveOnePokemon();
				}
				return false;
			}
			break;
		case MOVING_TO_GYM:
			//UpdateLocation();
			if(UpdateLocation())
			{
				state = IN_GYM;
				is_in_gym = true;
				current_gym->AddOnePokemon();
				return true;
			}
			else
			{	
				state = MOVING_TO_GYM;
				stamina-=1;
				pokemon_dollars+=GetRandomAmountofPokemonDollars();
				if(is_in_center)
				{
					is_in_center = false;
					current_center->RemoveOnePokemon();
				}
				if(is_in_gym)
				{
					is_in_gym = false;
					current_gym->RemoveOnePokemon();
				}
				if(is_in_arena)
				{
					is_in_arena = false;
					current_arena->RemoveOnePokemon();
				}
				return false;
			}
			break;
		case IN_CENTER:
			return false;
			break;
		case IN_GYM:
			return false;
			break;
		case IN_ARENA:
			return false;
			break;
		case TRAINING_IN_GYM:
			old = experience_points;
			stamina -= (*current_gym).GetStaminaCost(training_units_to_buy);
			pokemon_dollars -= (*current_gym).GetDollarCost(training_units_to_buy);
			experience_points += (*current_gym).TrainPokemon(training_units_to_buy);
			cout << "** " << name << " completed " << training_units_to_buy << " training_unit(s)!" << " **\n";
			cout << "** " << name << " gained " << experience_points-old << " experience point(s)!" << " **\n";
			state = IN_GYM;
			return true;
			break;
		case RECOVERING_STAMINA:
			old2 = stamina;
			stamina += (*current_center).DistributeStamina(stamina_points_to_buy);
			pokemon_dollars -= (*current_center).GetDollarCost(stamina_points_to_buy);
			cout << "** " << name << " recovered " << stamina-old2 << " stamina point(s)!" << " **\n";
			state = IN_CENTER;
			return true;
			break;
		case EXHAUSTED:
			cout << name << " is exhausted so you will not see it. \n";
			stamina = 0;
			return false;
			break;
		case FAINTED:
			cout << name << " fainted do you will not see it. \n";
			health = 0;
			state = FAINTED;
			return false;
		case MOVING_TO_ARENA:
			if(UpdateLocation())
			{
				state = IN_ARENA;
				is_in_arena = true;
				current_arena->AddOnePokemon();
				return true;
			}
			else
			{	
				state = MOVING_TO_ARENA;
				stamina-=1;
				pokemon_dollars+=GetRandomAmountofPokemonDollars();
				if(is_in_center)
				{
					is_in_center = false;
					current_center->RemoveOnePokemon();
				}
				if(is_in_gym)
				{
					is_in_gym = false;
					current_gym->RemoveOnePokemon();
				}
				if(is_in_arena)
				{
					is_in_arena = false;
					current_arena->RemoveOnePokemon();
				}
				return false;
			}
			break;
		case BATTLE:
			stamina -= (*current_arena).GetStaminaCost();
			pokemon_dollars -= (*current_arena).GetDollarCost();
			if(StartBattle())
			{
				health = store_health;
				state = IN_ARENA;
				target->IsAlive();
				current_arena->RemoveRival();
				cout << "Congrats Master, you defeated one rival!\n";
				return true;
			}
			else
			{
				state = FAINTED;
				target->IsAlive();
				cout << "What a shame Master, your Pokemon died!\n";
				return false;
			}
			break;
		default:
			cout << "Error" << endl;
			break;
	}
}

bool Pokemon::UpdateLocation()
{
	if(fabs(destination.x-location.x) <= fabs(delta.x) && fabs(destination.y-location.y) <= fabs(delta.y))
	{
		location = destination;
		cout << display_code << id_num << ": I'm there!" << endl;
		return true;
	}
	else
	{
		location = location + delta;
		cout << display_code << id_num << ": step..." << endl;
		return false;
	}
}

void Pokemon::SetupDestination(Point2D dest)
{
	destination = dest;
	delta = (destination-location)*(speed/GetDistanceBetween(destination,location));
	state = MOVING;
}

string Pokemon::GetName()
{
	return name;
}

Pokemon::Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc):GameObject(in_loc,in_id,'P')
{
	this->speed = speed;
	name = in_name;
	//display_code = in_code;
	//id_num = in_id;
	//location = in_loc;
	stamina = 20;
	state = STOPPED;
	this->speed = speed;
	health = hp;
	store_health = health;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	current_arena = NULL;
	current_gym = NULL;
	current_center = NULL;
	cout << "Pokemon constructed.\n";
}

bool Pokemon::IsAlive()
{
	if(state!=FAINTED)
		return true;
	else if(state==FAINTED)
		return false;
}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense)
{
	double choice = rand() % 2 == 0 ? physical_damage : magical_damage;
	if(choice==physical_damage)
		cout << "Physical damage hurts, Master!\n";
	if(choice==magical_damage)
		cout << "It is magic, Master!\n";
	double damage = (100.0 - defense)/100 * choice;
	health = health - damage;
	cout << "Health: " << health <<endl;
	cout << "Damage: " << damage <<endl;
	cout << "***********" << endl <<endl;
}

/* This function will be called from StartBattle() function until either Pokemon
or Rival has 0 or less than 0 health */

void Pokemon::ReadyBattle(Rival *in_target)
{
	if(is_in_arena)
	{
		if(!isExhausted() && IsAlive() && is_in_arena && (*current_arena).IsAbleToFight(pokemon_dollars, stamina) && !(*current_arena).IsBeaten())
		{
			cout << display_code << id_num << ": Started to Battle at Battle Arena " << (*current_arena).id_num << endl;
			target = in_target;
			state = BATTLE;
		}
		else if(isExhausted())
		{
			cout << display_code << id_num << ": I am exhausted so no more battling for me...\n";
			state = EXHAUSTED;
		}
		else if(!(*current_arena).IsAbleToFight(pokemon_dollars, stamina))
			cout << display_code << id_num << ": Not enough stamina and/or money for training\n";
		else if((*current_arena).IsBeaten())
			cout << display_code << id_num << ": Cannot battle! This Battle Arena is already beaten!\n";
	}
	else 
		cout << display_code << id_num << ": I can only battle in a Battle Arena!\n";
}

bool Pokemon::StartBattle()
{
	if(is_in_arena)
		state = BATTLE;
	while(health>0&&target->get_health()>0)
	{
		TakeHit(target->get_phys_dmg(),target->get_magic_dmg(),target->get_defense());
		if(health>0)
			target->TakeHit(physical_damage,magical_damage,defense);
	}
	if(health>0)
		return true;
	if(target->get_health()>0)
		return false;	
}

static double GetRandomAmountofPokemonDollars()
{
	/* srand(time(NULL));
	return (2.0) * ((double)rand()/(double)RAND_MAX); */
	double f_min = 0.0;
    double f_max = 2.0;
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}


