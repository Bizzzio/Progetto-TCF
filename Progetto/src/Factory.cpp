#include "Factory.h"

bool Factory::Check(int x, int y, Griglia grid)
{

	int s = grid.GetSize();
	if (x >= s || y >= s)
	{
		cout << "Coordinate fuori target. Riprovare." << endl;
		return false;
	}

	else
	{
		if (!grid[x][y])
		{
			return true;
		}
		else
		{
			if (!(grid[x][y]->IsHit(x, y)))
				return true;
			else
			{
				cout << "Coordinate già colpite. Riprovare." << endl;
				return false;
			}
		}
	}
}