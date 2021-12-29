#include <iostream>
#include <vector>
#include "Navi2.h"
#include "Griglia.h"

using std::cout;
using std::endl;
using std::vector;


int main()
{
	Griglia griglia(6);
	Navi2 nave(true, 1, 1);
	Navi *nvptr = &nave;
	griglia.grid[1][1] = nvptr;
	cout<<"ciao"<<endl;
	griglia.grid[1][2] = nvptr;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia.grid[i][j])

				griglia.grid[i][j]->DrawAlly(i,j);
			else
				cout << ". ";
		}
		cout<<endl;
	}
	return 0;
}
