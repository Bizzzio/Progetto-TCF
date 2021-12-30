#include <iostream>
#include <vector>
#include "Griglia.h"

using std::cout;
using std::endl;
using std::vector;


int main()
{
	Griglia griglia(6);

	Navi nave(true, 1, 1,2);
	Navi* nvptr = &nave;
	griglia.SetGriglia(1, 1, nvptr);
	griglia.SetGriglia(2, 1, nvptr);

	Navi nave1(false, 3, 3, 2);
	Navi* nvptr1 = &nave1;
	griglia.SetGriglia(3, 3, nvptr1);
	griglia.SetGriglia(3, 4, nvptr1);

	Navi nave2(true, 0, 5,5);
	Navi* nvptr2 = &nave2;
	griglia.SetGriglia(0, 5, nvptr2);
	griglia.SetGriglia(1, 5, nvptr2);
	griglia.SetGriglia(2, 5, nvptr2);
	griglia.SetGriglia(3, 5, nvptr2);
	griglia.SetGriglia(4, 5, nvptr2);

	Navi nave3(false, 3, 0,3);
	Navi* nvptr3 = &nave3;
	griglia.SetGriglia(3, 0, nvptr3);
	griglia.SetGriglia(3, 1, nvptr3);
	griglia.SetGriglia(3, 2, nvptr3);
	
	Navi nave4(false, 5, 0,4);
	Navi* nvptr4 = &nave4;
	griglia.SetGriglia(5, 0, nvptr4);
	griglia.SetGriglia(5, 1, nvptr4);
	griglia.SetGriglia(5, 2, nvptr4);
	griglia.SetGriglia(5, 3, nvptr4);
	
	Navi nave5(true, 0, 0, 2);
	Navi* nvptr5 = &nave5;
	griglia.SetGriglia(0, 0, nvptr5);
	griglia.SetGriglia(1, 0, nvptr5);
	
	// Stampo tutte le griglie non colpite

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawEnemy(j, i);
			else
				cout << ". ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawAlly(j, i);
			else
				cout << ". ";
		}
		cout << endl;
	}

	cout << endl;

	// Colpisco mezza griglia

	for (int z = 0; z < 3; z++)
		for (int j = 0; j < 6; j++)
			griglia.Strike(z, j);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawEnemy(j, i);
			else
				cout << ". ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawAlly(j, i);
			else
				cout << ". ";
		}
		cout << endl;
	}

	cout << endl;

	// Stampo le griglie colpite

	for (int z = 3; z < 6; z++)
		for (int j = 0; j < 6; j++)
			griglia.Strike(z, j);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawEnemy(j, i);
			else
				cout << ". ";
		}
		cout << endl;
	}
	
	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawAlly(j, i);
			else
				cout << ". ";
		}
		cout << endl;
	}

	return 0;
}
