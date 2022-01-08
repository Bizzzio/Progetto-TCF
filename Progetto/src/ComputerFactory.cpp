#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
#include "ComputerFactory.h"
// abbiamo creato la griglia da 10
// le regole sono che si possono usare 1 nave da 4, 1 da 5, 3 da 3, 3 da 2

ComputerFactory::ComputerFactory(int dim, int n2, int n3, int n4, int n5, int n6) : grid(dim)
{ //PlayerFactory::PlayerFactory(int dim, int n2,int n3, int n4, int n5, int n6)

  SetFleet(n2, n3, n4, n5, n6); //SetFleet(n2,n3,n4,n5,n6)
}

int ComputerFactory::GetSize() const
{
  return grid.GetSize();
}

void ComputerFactory::SetFleet(int n2, int n3, int n4, int n5, int n6)
{

  int numbers[5] = {n2, n3, n4, n5, n6};

  for (int i = 0, z = 2; i < 5; i++)
  {

    for (int j = 0; j < numbers[i]; j++)
    {
      int x, y, n;
      bool h;
      do
      {
        do
        {
			n = rand()%2;
        } while (n != 1 && n != 0);
        h = n;
        x = rand()%10;
        y = rand()%10;
      } while (!grid.CheckCell(h, x, y, z));
      fleet.push_back(new Navi(h, x, y, z));
      if (h)
      {
        for (int i = 0; i < z; i++)
          grid.SetGriglia(x + i, y, fleet.back());
      }
      else
      {
        for (int i = 0; i < z; i++)
          grid.SetGriglia(x, y + i, fleet.back());
      }
    }
    z++;
  }
}


vector<Navi *> PlayerFactory::GetFleet() const
{
  return fleet;
}

Griglia ComputerFactory::GetGrid() const
{
  return grid;
}

ComputerFactory::~ComputerFactory()
{
  vector<Navi *>::iterator i;
  for (i = fleet.begin(); i != fleet.end(); i++)
    delete *i;
}

bool ComputerFactory::EndGame() const
{

  unsigned int count = 0;
  vector<Navi *>::const_iterator i;
  for (i = fleet.begin(); i != fleet.end(); i++)
  {
    //cout << "count:" << count << " size:" << fleet.size() << " ";
    if ((*i)->Sunk())
      count++;
    else
      return false;
  }

  if (count == fleet.size())
  {

    return true;
  }
  else
    return false;
}