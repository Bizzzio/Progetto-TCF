#include <iostream>
#include "Griglia.h"
using namespace std;

Griglia::Griglia(int d) : Water(false,-1,-1,-1)
{
	size = d;

	for (int i = 0; i < size; i++)
	{
		vector<Navi*> temp;
		temp.push_back(NULL);
		for (int j = 0; j < size; j++)
		{

			grid.push_back(temp); //aggiunge una riga
			grid[i].push_back(NULL);
			//cout<<". "; 
		}
		//cout<<endl;
	}

}

void Griglia::DrawEnemy() const
{
	cout<<"    ";
	for (int i = 0; i < size; i++)
		cout<<i<<" ";
	cout<<endl<<"   ";
	for (int i = 0; i < size; i++)
		cout<<"--";
	cout<<endl;
	for (int i = 0; i < size; i++)
		{
			cout<<i<<" | ";
			for (int j = 0; j < size; j++)
			{
				if (grid[j][i])

					grid[j][i]->DrawEnemy(j, i);
				else
					cout << ". ";
			}
			cout << endl;
		}
	cout << endl;
}

void Griglia::DrawAlly() const
{
	cout<<"    ";
	for (int i = 0; i < size; i++)
		cout<<i<<" ";
	cout<<endl<<"   ";
	for (int i = 0; i < size; i++)
		cout<<"--";
	cout<<endl;
	for (int i = 0; i < size; i++)
		{
			cout<<i<<" | ";
			for (int j = 0; j < size; j++)
			{
				if (grid[j][i])

					grid[j][i]->DrawAlly(j, i);
				else
					cout << ". ";
			}
			cout <<"| "<< i << endl;
		}
	cout<<"   ";
	for (int i = 0; i < size; i++)
		cout<<"--";
	cout << endl;
	cout<<"    ";
	for (int i = 0; i < size; i++)
	cout<<i<<" ";
	cout<<endl<<endl;

}


void Griglia::SetGriglia(int i, int j, Navi* nave)
{
	this->grid[i][j] = nave;
}


void Griglia::Strike(int x, int y)
{
	if (!grid[x][y])
		grid[x][y] = &Water;
	else  
		grid[x][y]->Strike(x, y);
}


vector<Navi*> Griglia::operator[] (int i) {
	return this->grid[i];
}
