#include <iostream>
#include "BattleArena.h"
using namespace std;

BattleArena::BattleArena()
{
	display_code = 'A';
	pokemon_count = 0;
	max_num_rivals = 3;
	num_rivals_remaining = max_num_rivals;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;
	cout << "BattleArena default constructed.\n";
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc):Building('A', in_id, in_loc)
{
	/* id_num = in_id;
	location = in_loc;  */
	max_num_rivals = max_rivals;
	num_rivals_remaining = max_num_rivals;
	stamina_cost_per_fight = stamina_cost;
	dollar_cost_per_fight = dollar_cost;
	cout << "BattleArena constructed.\n";
	state = RIVALS_AVAILABLE;
}

unsigned int BattleArena::GetNumRivalsRemaining()
{
	return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
	if(GetNumRivalsRemaining()>=1)
		return true;
	else
		return false;
}

double BattleArena::GetDollarCost()
{
	return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
	return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
	if(GetDollarCost()<=budget&&GetStaminaCost()<=stamina)
		return true;
	else
		return false;
}

void BattleArena::RemoveRival()
{
	num_rivals_remaining--;
}

bool BattleArena::Update()
{
	int counter = 0;
	if(GetNumRivalsRemaining()>0)
		return false;
	else if(GetNumRivalsRemaining()==0&&counter==0)
	{
		counter++;
		return true;
	}
	else
		return false;
}

bool BattleArena::IsBeaten()
{
	if(num_rivals_remaining == 0)
		return true;
	else 
		return false;
}

void BattleArena::ShowStatus()
{
	cout << "BattleArena Status: ";
	Building::ShowStatus(); 
	cout << "    Max number of rivals: " << max_num_rivals << endl;
	cout << "    Stamina cost per fight: " << stamina_cost_per_fight << endl;
	cout << "    Pokemon dollar cost per fight: " << dollar_cost_per_fight << endl;
	cout << "    " << num_rivals_remaining << " rival(s) are remaining for this arena" <<endl;
}