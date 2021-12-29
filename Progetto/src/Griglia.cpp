#include <iostream>
#include "Griglia.h"
using namespace std;

Griglia::Griglia(int d)
{

	for (int i = 0; i < d; i++)
	{
		vector<*Navi> temp;
		temp.push_back(NULL);
		for (int j = 0; j < d; j++)
		{

			grid.push_back(temp); //aggiunge una riga
			grid[i].push_back(NULL);
		}
	}
}

void Griglia::DrawEnemy() const
{

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++)
		{
			grid[i][j]->DrawEnemy();
		}
	}
}

void Griglia::DrawAlly() const
{

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++)
		{
			grid[i][j]->DrawAlly();
		}
	}
}
