#include <iostream>
#include <vector>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#endif
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
          n = rand() % 2;      // Il % ci dà il resto di una divisione
        } while (n != 1 && n != 0);     // Esco solo se n=0 o n=1 e n determinerà l'orientazione della nave
        h = n;
        x = rand() % 10;  // con %10 mi restringo ai numeri tra 0 e 9, che poi vengono controllati
        y = rand() % 10;  // da CheckCell
      } while (!CheckCell(h, x, y, z));  // CheckCell può andare nella Factory?
      fleet.push_back(new Navi(h, x, y, z));
      if (h)
      {
        // più carino se mettiamo questo for direttamente in Griglia dandogli anche come
        // argomento un bool e la lunghezza
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

vector<Navi *> ComputerFactory::GetFleet() const
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

/*bool ComputerFactory::EndGame() const
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
}*/

void ComputerFactory::Turn(Griglia &EnemyGrid, int NumGiocatore)
{

  int x, y;
  bool sparato = false;
  //cout << "Turno giocatore" << NumGiocatore << endl;
  for (int i = 0; i < EnemyGrid.GetSize() && !sparato; i++)
  {
    for (int j = 0; j < EnemyGrid.GetSize() && !sparato; j++)
    {
      //cout << "ciaone";
      if (EnemyGrid.IsHit(i, j) && !EnemyGrid[i][j]->Sunk())
      {
        // cout << "sono in" << i << j;
        if (!CheckSurroundings(EnemyGrid, i, j))
        {
          //cout << "ho sparato in" << i << j;
          sparato = true;
          break;
        }
      }
    }
  }
  if (!sparato)
  {
    //cout << "ciaone2";
    for (int i = 0; i < EnemyGrid.GetSize() && !sparato; i++)
    {
      for (int j = 0; j < EnemyGrid.GetSize() && !sparato; j++)
      {
        if (EnemyGrid.IsHit(i, j) && !EnemyGrid[i][j]->Sunk())
        {
          //cout << "ishit va bene";
          if (Check(i + 1, j, EnemyGrid))
          {
            //cout << "ho sparato in" << i + 1 << j;
            EnemyGrid.Strike(i + 1, j);
            sparato = true;
            break;
          }
          else if (Check(i - 1, j, EnemyGrid))
          {
            //cout << "ho sparato in" << i - 1 << j;
            EnemyGrid.Strike(i - 1, j);
            sparato = true;
            break;
          }
          else if (Check(i, j + 1, EnemyGrid))
          {
            //cout << "ho sparato in" << i << j + 1;
            EnemyGrid.Strike(i, j + 1);
            sparato = true;
            break;
          }
          else if (Check(i, j - 1, EnemyGrid))
          {
            //cout << "ho sparato in" << i << j - 1;
            EnemyGrid.Strike(i, j - 1);
            sparato = true;
            break;
          }
        }
      }
    }
  }
  if (!sparato)
  {

    do
    {
      x = rand() % 10;
      y = rand() % 10;
      //cout << "ho sparato in" << x << y;
    } while (!Check(x, y, EnemyGrid));
    EnemyGrid.Strike(x, y);
  }
  EnemyGrid.DrawAlly();
}

bool ComputerFactory::CheckSurroundings(Griglia &EnemyGrid, int i, int j)
{
  //cout << "CheckSurroundings";
  if (IsNave(i + 1, j, EnemyGrid) && Check(i - 1, j, EnemyGrid))
  {
    //cout << "ho sparato in" << i - 1 << j << "1";
    if (EnemyGrid.IsHit(i + 1, j) && !EnemyGrid[i + 1][j]->Sunk())
    {
      //cout << "ho sparato in" << i - 1 << j << "1";
      EnemyGrid.Strike(i - 1, j);
      return 0;
    }
  }
  if (Check(i + 1, j, EnemyGrid) && IsNave(i - 1, j, EnemyGrid))
  {
    //cout << "ho sparato in" << i + 1 << j << "2";
    if (EnemyGrid.IsHit(i - 1, j) && !EnemyGrid[i - 1][j]->Sunk())
    {
      //cout << "ho sparato in" << i + 1 << j << "2";
      EnemyGrid.Strike(i + 1, j);
      return 0;
    }
  }
  if (Check(i, j - 1, EnemyGrid) && IsNave(i, j + 1, EnemyGrid))
  {
    //cout << "ho sparato in" << i << j - 1 << "3";
    if (EnemyGrid.IsHit(i, j + 1) && !EnemyGrid[i][j + 1]->Sunk())
    {
      // cout << "ho sparato in" << i << j - 1 << "3";
      EnemyGrid.Strike(i, j - 1);
      return 0;
    }
  }
  if (IsNave(i, j - 1, EnemyGrid) && Check(i, j + 1, EnemyGrid))
  {
    //cout << "ho sparato in" << i << j + 1 << "4";
    if (EnemyGrid.IsHit(i, j - 1) && !EnemyGrid[i][j - 1]->Sunk())
    {
      //cout << "ho sparato in" << i << j + 1 << "4";
      EnemyGrid.Strike(i, j + 1);
      return 0;
    }
  }
  //cout << "im here";
  return 1;
}

