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
#include "Input_Handling.h"
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
	char type;
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
	try
	{
		if(cmd!='m'&&cmd!='g'&&cmd!='c'&&cmd!='a'&&cmd!='s'&&cmd!='t'&&cmd!='r'&&cmd!='q'&&cmd!='v'&&cmd!='x'&&cmd!='b'&&cmd!='n') // do the input, then check: is stream good?
			throw Invalid_Input("Not a valid command"); // throw an exception
		
		switch(cmd)
		{
			case 'm':
			{
				cin >> id1;
				cin >> x;
				cin >> y;
				if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
					throw Invalid_Input("Invalid id number");
				if(!(x>=0)||!(x<=20))
					throw Invalid_Input("Not a valid x coordinate value");
				if(!(y>=0)||!(y<=20))
					throw Invalid_Input("Not a valid y coordinate value");
				Point2D p1(x,y);
				DoMoveCommand(m1,id1,p1);
				m1.Update();
				break;
			}
			case 'g':
			cin >> id1;
			cin >> id2;
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
			if(id2!=0&&id2!=1&&id2!=2&&id2!=3&&id2!=4&&id2!=5&&id2!=6&&id2!=7&&id2!=8&&id2!=9)
				throw Invalid_Input("Invalid id number");
			DoMoveToGymCommand(m1,id1,id2);
			m1.Update();
			break;
			case 'c':
			cin >> id1;
			cin >> id2;
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
			if(id2!=0&&id2!=1&&id2!=2&&id2!=3&&id2!=4&&id2!=5&&id2!=6&&id2!=7&&id2!=8&&id2!=9)
				throw Invalid_Input("Invalid id number");
			DoMoveToCenterCommand(m1,id1,id2);
			m1.Update();
			break;
			case 'a':
			cin >> id1;
			cin >> id2;
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
			if(id2!=0&&id2!=1&&id2!=2&&id2!=3&&id2!=4&&id2!=5&&id2!=6&&id2!=7&&id2!=8&&id2!=9)
				throw Invalid_Input("Invalid id number");
			DoMoveToArenaCommand(m1,id1,id2);
			m1.Update();
			break;
			case 's':
			cin >> id1;
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
			DoStopCommand(m1,id1);
			m1.Update();
			break;
			case 't':
			cin >> id1;
			cin >> unit;
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
			DoTrainInGymCommand(m1,id1,unit);
			m1.Update();
			break;
			case 'r':
			cin >> id1;
			cin >> stamina;
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
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
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
			if(id2!=0&&id2!=1&&id2!=2&&id2!=3&&id2!=4&&id2!=5&&id2!=6&&id2!=7&&id2!=8&&id2!=9)
				throw Invalid_Input("Invalid id number");
			DoBattleCommand(m1,id1,id2);
			m1.Update();
			break;
			case 'n':
			cin >> type;
			cin >> id1;
			cin >> x;
			cin >> y;
			if(type!='g'&&type!='c'&&type!='p'&&type!='r')
				throw Invalid_Input("Not a valid type name");
			if(id1!=0&&id1!=1&&id1!=2&&id1!=3&&id1!=4&&id1!=5&&id1!=6&&id1!=7&&id1!=8&&id1!=9)
				throw Invalid_Input("Invalid id number");
			if(!(x>=0)||!(x<=20))
				throw Invalid_Input("Not a valid x coordinate value");
			if(!(y>=0)||!(y<=20))
				throw Invalid_Input("Not a valid y coordinate value");
			if(m1.CheckDupID(type,id1))
				throw Invalid_Input("Duplicate id num use a different value");
			m1.NewCommand(type,id1,x,y);
			m1.Update();
			default:
			cout << "Error";
		}
	counter++;
	}
	catch (Invalid_Input& except)
	{
		cout << "Invalid input - " << except.msg_ptr << endl;
		continue;
		// actions to be taken if the input is wrong
	}
	
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

