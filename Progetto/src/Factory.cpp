#include <iostream>
#include <vector>
using namespace std;
#include "Factory.h"
// abbiamo creato la griglia da 10
// le regole sono che si possono usare 1 nave da 4, 1 da 5, 3 da 3, 3 da 2

Factory::Factory(int dim, int n2, int n3, int n4, int n5, int n6) : grid(dim)
{ //Factory::Factory(int dim, int n2,int n3, int n4, int n5, int n6)

  SetFleet(n2, n3, n4, n5, n6); //SetFleet(n2,n3,n4,n5,n6)
}

int Factory::GetSize() const
{
  return grid.GetSize();
}

void Factory::SetFleet(int n2, int n3, int n4, int n5, int n6)
{

  int numbers[5] = {n2, n3, n4, n5, n6};

  for (int i = 0, z = 2; i < 5; i++)
  {

    for (int j = 0; j < numbers[i]; j++)
    {
      int x, y, n;
      bool h;
      grid.DrawAlly();
      do
      {
        do
        {
          cout << "\nVuoi la " << j + 1 << "a nave, da " << z << " caselle, orizzontale(=1) o verticale(=0)?" << endl;
          cin >> n;
        } while (n != 1 && n != 0);
        h = n;
        cout << "\nDammi una x e una y per posizionare la nave sulla griglia" << endl;
        cin >> x >> y;
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

      //fleet.DrawAlly(x,y);
    }
    z++;
  }
  grid.DrawAlly();
  //cin.ignore();
  //system("cls");
}

vector<Navi *> Factory::GetFleet() const
{
  return fleet;
}

Griglia Factory::GetGrid() const
{
  return grid;
}

Factory::~Factory()
{
  vector<Navi *>::iterator i;
  for (i = fleet.begin(); i != fleet.end(); i++)
    delete *i;
}

bool Factory::EndGame() const
{

  int count = 0;
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
