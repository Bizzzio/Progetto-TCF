#include "Factory.h"

bool Factory::Check(int x, int y, Griglia &grid)
{
	//cout << "check di" << x << " " << y;
	
	// controllo coordinate: per prima cosa verifico che stiano dentro la griglia,
	// poi che non siano già state colpite
	
	int s = grid.GetSize();
	cout << endl;
	if ((x >= s || x < 0) || (y >= s || y < 0))
	{

		cout << "Coordinate fuori target. Riprovare." << endl;
		return false;
	}

	else
	{
		// Se il puntatore grid[x][y] è nullo vuol dire che punta ad acqua non 
		// colpita e quindi va bene 
		if (!grid[x][y])
		{

			return true;
		}
		else
		{
			// IsHit ritorna vero se la casella è stata colpita
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
	// Guardo se x,y stanno dentro la griglia oppure no
	// (forse ridondante con una parte di Check)
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

bool Factory::CheckCell(bool t, int x, int y, int length) const
{
	// Controllo se tutte le celle che una nave andrà ad occupare sono
	// libere avendo nota la sua lunghezza e orientazione con t e length
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

bool Factory::EndGame() const{

	vector<Navi *>::const_iterator i;
  for (i = GetFleet().begin(); i != GetFleet().end(); i++)
  {
    if (!(*i)->Sunk())
      return false;
  }
  return true;
}