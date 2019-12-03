#include <iostream>
#include "View.h"
using namespace std;

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	out_x = ((location-origin)/scale).x;
	out_y = ((location-origin)/scale).y;
	
	if(out_x<size&&out_y<size)
		return true;
	else
	{
		cout << "An object is outside the display.\n";
		return false;
	}
}

View::View()
{
	size = 11;
	scale = 2;
	origin = Point2D(0,0);
}

void View::Clear()
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			{
				grid[i][j][0] = '.';
				grid[i][j][1] = ' ';
			}
	}
}


void View::Plot(GameObject* ptr)
{
	int x = 0;
	int y = 0;
	if(GetSubscripts(x,y,ptr->GetLocation())&&ptr->ShouldBeVisible())
	{
		if(grid[10-y][x][0]!='.')
		{
			grid[10-y][x][0] = '*';
			grid[10-y][x][1] = ' ';
		}
		else
		{
			char* z = &grid[10-y][x][0];
			ptr->DrawSelf(z);
		}
	}
}

void View::Draw()
{
	int x = (size - 1) * 2;
	for(int i=0;i<size;i++)
	{
		cout << endl;
		if(i%2==0)
		{
			if(x<10)
				cout << x << " ";
			else
				cout << x;
			x-=4;
		}
		else
			cout << "  ";
		for(int j=0;j<size;j++)
			{
				cout << grid[i][j][0];
				cout << grid[i][j][1];
			}
	}
	cout << endl;
	cout << "  ";
	for(int i=0;i<=(size-1)*2;i+=4)
	{
		if(i<10)
			cout << i << "   ";
		else
			cout << i << "  ";
	}	
	cout << endl;
}