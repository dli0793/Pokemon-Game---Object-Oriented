#include <iostream>
#include "GameCommand.h"
using namespace std;

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
	Pokemon* pkptr = model.GetPokemonPtr(pokemon_id);
	
	if(pkptr!=0)
	{
		(*pkptr).StartMoving(p1);
		cout << "Moving " << (*pkptr).GetName() << " to " << p1 << endl;
	}
	else
		cout << "Error: Please enter a valid command!\n";
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id)
{
	Pokemon* pkptr = model.GetPokemonPtr(pokemon_id);
	PokemonCenter* ctptr = model.GetPokemonCenterPtr(center_id);
	if(ctptr!=0&&pkptr!=0)
	{
		(*pkptr).StartMovingToCenter(ctptr);
		cout << "Moving " << (*pkptr).GetName() << " to center " << center_id << endl;
	}
	else
		cout << "Error: Please enter a valid command!\n";
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)
{
	Pokemon* pkptr = model.GetPokemonPtr(pokemon_id);
	PokemonGym* gymptr = model.GetPokemonGymPtr(gym_id);
	if(gymptr!=0&&pkptr!=0)
	{
		(*pkptr).StartMovingToGym(gymptr);
		cout << "Moving " << (*pkptr).GetName() << " to gym " << gym_id << endl;
	}
	else
		cout << "Error: Please enter a valid command!\n";
}

void DoStopCommand(Model& model, int pokemon_id)
{
	Pokemon* pkptr = model.GetPokemonPtr(pokemon_id);
	if(pkptr!=0)
	{
		(*pkptr).Stop();
		cout << "Stopping " << (*pkptr).GetName() << endl;
	}
	else
		cout << "Error: Please enter a valid command!\n";
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)
{
	Pokemon* pkptr = model.GetPokemonPtr(pokemon_id);
	if(pkptr!=0)
	{
		(*pkptr).StartTraining(training_units);
		cout << "Training " << (*pkptr).GetName() << endl;
	}
	else
		cout << "Error: Please enter a valid command!\n";
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points)
{
	Pokemon* pkptr = model.GetPokemonPtr(pokemon_id);
	if(pkptr!=0)
	{
		(*pkptr).StartRecoveringStamina(stamina_points);
		cout << "Recovering " << (*pkptr).GetName() << "'s stamina" << endl;
	}
	else
		cout << "Error: Please enter a valid command!\n"; 
}

void DoGoCommand(Model& model, View& view)
{
	cout << "Advancing one tick.\n";
	model.Update();
	model.Display(view);
}
	

void DoRunCommand(Model& model, View& view)
{
	cout << "Advancing to next event.\n";
	int counter = 1;
	while(model.Update()||counter<5)
	{
		counter++;
	}
	model.Display(view);
}  