#include "Factory.h"

bool Factory::Check(int x, int y, Griglia &grid)
{
	cout << "sono quaa";
	int s = grid.GetSize();
	cout << endl
		 << x << " " << y;
	if ((x >= s || x < 0) || (y >= s || y < 0))
	{
		cout << "output";
		cout << "Coordinate fuori target. Riprovare." << endl;
		return false;
	}

	else
	{
		if (!grid[x][y])
		{
			cout << "output";
			return true;
		}
		else
		{

			if (!(grid[x][y]->IsHit(x, y)))
			{
				cout << "output";
				return true;
			}
			else
			{
				cout << "output";
				cout << "Coordinate già colpite. Riprovare." << endl;
				return false;
			}
		}
	}
}