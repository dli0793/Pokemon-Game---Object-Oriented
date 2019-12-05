#include <iostream>
#include "Rival.h"
using namespace std;

Rival::Rival(string name, double speed, double hp, double phys_dmg,double magic_dmg, double def, int id, Point2D in_loc):GameObject(in_loc,id,'R')
{
	this->name = name;
	this->speed = speed;
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	state = ALIVE_RIVAL;
	cout << "Rival constructed.\n";
}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense)
{
	double choice = rand() % 2 == 0 ? physical_damage : magical_damage;
	if(choice==physical_damage)
		cout << "Aaagh, no physical pain no gain!\n";
	if(choice==magical_damage)
		cout << "Ouch, I do not believe magic!\n";
	double damage = (100.0 - defense)/100 * choice;
	health = health - damage;
	cout << "Health: " << health <<endl;
	cout << "Damage: " << damage <<endl;
	cout << "***********" << endl <<endl;
}

double Rival::get_phys_dmg()
{
	return physical_damage;
}

double Rival::get_magic_dmg()
{
	return magical_damage;
}

double Rival::get_defense()
{
	return defense;
}

double Rival::get_health()
{
	return health;
}

string Rival::GetName()
{
	return name;
}


bool Rival::IsAlive() 
{
    if(health < 0)
	{
		state = FAINTED_RIVAL;
		return false;
	}
    else
    {
		state = ALIVE_RIVAL;
		return true;
	}
}

bool Rival::Update()
{
	if(health<=0)
		state = FAINTED_RIVAL;
	if(state==ALIVE_RIVAL)
		return false;
	if(state==FAINTED_RIVAL)
	{
		state = FAINTED_RIVAL;
		return false;
	}
}

void Rival::ShowStatus()
{
	cout << name << " status: \n";
	GameObject::ShowStatus(); 
	switch(state)
	{
		case ALIVE_RIVAL:
			cout << " is alive\n";
			break;
		case FAINTED_RIVAL:
			cout << " has fainted\n" ;
			break;
		default:
			cout << "Error" << endl;
			break;
	}
	cout << "    Health: " << health << endl;
	cout << "    Physical Damage: " << physical_damage << endl;
	cout << "    Magical Damage: " << magical_damage << endl;
	cout << "    Defense: " << defense << endl;
}

bool Rival::ShouldBeVisible()
{
	if(IsAlive())
		return true;
	else
		return false;
}
