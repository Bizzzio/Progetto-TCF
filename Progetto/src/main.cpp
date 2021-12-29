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
	Navi2 nave1(false, 3, 4);
	Navi *nvptr1 = &nave1;
	Navi5 nave2(true,0,5);
	Navi *nvptr2 = &nave2;
	Navi3 nave3(false, 3, 0);
	Navi *nvptr3 = &nave3;
	Navi4 nave4(false, 5, 0);
	Navi *nvptr4 = &nave4;
	griglia.SetGriglia(1,1,nvptr);
	griglia.SetGriglia(2,1,nvptr);
	griglia.SetGriglia(3,4,nvptr1);
	griglia.SetGriglia(4,4,nvptr1);
	griglia.SetGriglia(0,5,nvptr2);
	griglia.SetGriglia(1,5,nvptr2);
	griglia.SetGriglia(2,5,nvptr2);
	griglia.SetGriglia(3,5,nvptr2);
	griglia.SetGriglia(4,5,nvptr2);
	griglia.SetGriglia(3,0,nvptr3);
	griglia.SetGriglia(3,1,nvptr3);
	griglia.SetGriglia(3,2,nvptr3);
	griglia.SetGriglia(5,0,nvptr4);
	griglia.SetGriglia(5,1,nvptr4);
	griglia.SetGriglia(5,2,nvptr4);
	griglia.SetGriglia(5,3,nvptr4);



	griglia.Strike(2,1);
	griglia.Strike(1,1);

	

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawAlly(j,i);
			else
				cout << ". ";
		}
		cout<<endl;
	}

	griglia.Strike(0,5);
	griglia.Strike(1,5);
	griglia.Strike(2,5);
	griglia.Strike(3,5);
	griglia.Strike(4,5);

	cout<<endl;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawAlly(j,i);
			else
				cout << ". ";
		}
		cout<<endl;
	}

	cout<<endl;

		for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (griglia[j][i])

				griglia[j][i]->DrawEnemy(j,i);
			else
				cout << ". ";
		}
		cout<<endl;
	}
	//cout<<griglia[1][1]<<endl<<&nave;
	return 0;
}
