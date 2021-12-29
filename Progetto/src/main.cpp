#include <iostream>
#include <vector>
#include "Navi2.h"
#include "Griglia.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	int main()
	{
		Griglia grid(6);
		Navi2 nave(true, 1, 1);
		Navi *nvptr = &nave;
		grid[1, 1] = nvptr;
		grid[1, 2] = nvptr;

		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < d; j++)
			{
				if (grid[i][j])

					grid[i][j]->DrawEnemy();
				else
					cout << ". ";
			}
		}
	}
}
}