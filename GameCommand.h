#ifndef GameCommand_INCLUDE
#define GameCommand_INCLUDE
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
#include "Model.h"
//#include "View.h"
using namespace std;

void DoMoveCommand(Model& , int , Point2D );
void DoMoveToCenterCommand(Model& , int , int );
void DoMoveToGymCommand(Model& , int , int );
void DoStopCommand(Model& , int );
void DoTrainInGymCommand(Model&, int , unsigned int );
void DoRecoverInCenterCommand(Model& , int , unsigned int );
void DoGoCommand(Model& , View& );
void DoRunCommand(Model& , View& );


#endif