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

bool Factory::Checkfleet() const{

	vector<Navi *>::const_iterator i;
	for (i = GetFleet().begin(); i != GetFleet().end(); i++)
  	{
    if (!(*i)->Sunk())
      return false;
  	}

  	return true;
}

bool Factory::CheckCell(bool t, int x, int y, int length) const
{
    if (t)
    {
        if (x + length - GetSize() <= 0)
        {

            for (int i = 0; i < length; i++)
            {
                if (GetGrid()[x + i][y])
                    return false;
            }
            if (y < GetSize())
                return true;
        }
        return false;
    }

    else
    {
        if (y + length - GetSize() <= 0)
        {
            for (int i = 0; i < length; i++)
            {
                if (GetGrid()[x][y + i])
                    return false;
            }
            if (x < GetSize())
                return true;
        }
        return false;
    }
    return false;
}