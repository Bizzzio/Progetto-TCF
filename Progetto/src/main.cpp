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
	Navi2 nave(false, 1, 1);
	Navi *nvptr = &nave;
	Navi2 nave1(true, 3, 4);
	Navi *nvptr1 = &nave1;
	griglia.SetGriglia(1,1,nvptr);
	griglia.SetGriglia(1,2,nvptr);
	griglia.SetGriglia(3,4,nvptr1);
	griglia.SetGriglia(4,4,nvptr1);
	cout<<"ciao"<<endl;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[i][j])

				griglia[i][j]->DrawAlly(i,j);
			else
				cout << ". ";
		}
		cout<<endl;
	}

	cout<<griglia[1][1]<<endl<<&nave;
	return 0;
}
