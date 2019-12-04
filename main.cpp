#include <iostream>
#include <fstream>
#include <string>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
using namespace std;

string getFileContents(ifstream&);
int main()
{
    cout << "EC327: Introduction to Software Engineering\n";
	cout << "Fall 2019\n";
	cout << "Programming Assignment 3\n";
	ifstream Reader("Art.txt");             
	string Art = getFileContents(Reader);       
    cout << Art << endl;               
    Reader.close();                           

	Model m1 = Model();
	View v = View();
	
 	char cmd;
	int id1;
	int id2;
	int x;
	int y;
	unsigned int unit;
	unsigned int stamina;
	int counter = 0;
	
	while(cmd!='q')
	{
	v.Clear();
	m1.ShowStatus();
	m1.Display(v);
	v.Draw();
	
	cout << "Enter command: ";
	cin >> cmd;
	switch(cmd)
	{
		case 'm':
		{
			cin >> id1;
			cin >> x;
			cin >> y;
			Point2D p1(x,y);
			DoMoveCommand(m1,id1,p1);
			m1.Update();
			break;
		}
		case 'g':
		cin >> id1;
		cin >> id2;
		DoMoveToGymCommand(m1,id1,id2);
		m1.Update();
		break;
		case 'c':
		cin >> id1;
		cin >> id2;
		DoMoveToCenterCommand(m1,id1,id2);
		m1.Update();
		break;
		case 'a':
		cin >> id1;
		cin >> id2;
		DoMoveToArenaCommand(m1,id1,id2);
		m1.Update();
		break;
		case 's':
		cin >> id1;
		DoStopCommand(m1,id1);
		m1.Update();
		break;
		case 't':
		cin >> id1;
		cin >> unit;
		DoTrainInGymCommand(m1,id1,unit);
		m1.Update();
		break;
		case 'r':
		cin >> id1;
		cin >> stamina;
		DoRecoverInCenterCommand(m1,id1,stamina);
		m1.Update();
		break;
		case 'q':
		cout << "Game session ended. Thanks for playing. \n";
		return 0;
		break;
		case 'v':
		DoGoCommand(m1, v);
		break;
		case 'x':
		DoRunCommand(m1, v);
		break;
		case 'b':
		cin >> id1;
		cin >> id2;
		DoBattleCommand(m1,id1,id2);
		break;
		default:
		cout << "Error";
	}
	counter++;
	}
	
	return 0;
	
}

string getFileContents(ifstream& File)
{
    string Lines = "";        
    if(File)                      
    {
		while(File.good())
		{
			string TempLine;                  
			getline (File , TempLine);        
			TempLine += "\n";                      
			Lines += TempLine;                     
		}
		return Lines;
    }
    else                           
    {
		return "ERROR File does not exist.";
    }
}

