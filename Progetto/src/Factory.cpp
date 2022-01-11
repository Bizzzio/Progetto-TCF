#include "Factory.h"

bool Factory::Check(int x, int y, Griglia &grid)
{
	//cout << "check di" << x << " " << y;
	int s = grid.GetSize();
	cout << endl;
	if ((x >= s || x < 0) || (y >= s || y < 0))
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
			{

				return true;
			}
			else
			{

				cout << "Coordinate già colpite. Riprovare." << endl;
				return false;
			}
		}
	}
}

bool Factory::IsNave(int x, int y, Griglia &grid)
{
	int s = grid.GetSize();
	cout << endl;
	if ((x >= s || x < 0) || (y >= s || y < 0))
	{

		cout << "Coordinate fuori target. Riprovare." << endl;
		return false;
	}

	else
	{
		return true;
	}
}