#include <iostream>
#include <vector>
#ifdef _WIN32
#include <conio.h>
#define CLEAR "cls"
#else
#define CLEAR "clear"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
int getchp(void)
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
using std::vector;
using std::cin;
using std::cout;
using std::endl;
#include "PlayerFactory.h"
// abbiamo creato la griglia da 10
// le regole sono che si possono usare 1 nave da 4, 1 da 5, 3 da 3, 3 da 2

PlayerFactory::PlayerFactory(int dim, int n2, int n3, int n4, int n5, int n6) : grid(dim)
{ //PlayerFactory::PlayerFactory(int dim, int n2,int n3, int n4, int n5, int n6)

  SetFleet(n2, n3, n4, n5, n6); //SetFleet(n2,n3,n4,n5,n6)
}

int PlayerFactory::GetSize() const
{
  return grid.GetSize();
}

void PlayerFactory::SetFleet(int n2, int n3, int n4, int n5, int n6)
{
  // dò in input il numero di navi da 2,3,4,5,6
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
      } while (!CheckCell(h, x, y, z)); 
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
      system(CLEAR);
      //fleet.DrawAlly(x,y);
    }
    z++;
  }
  grid.DrawAlly();
  cout << "Premi un tasto per oscurare" << endl;
  #ifdef _WIN32
  getch();
  #else
  getchp();
  #endif
  system(CLEAR);
  //system(CLEAR);
}

vector<Navi *> PlayerFactory::GetFleet() const
{
  return fleet;
}

Griglia PlayerFactory::GetGrid() const
{
  return grid;
}

PlayerFactory::~PlayerFactory()
{
  vector<Navi *>::iterator i;
  for (i = fleet.begin(); i != fleet.end(); i++)
    delete *i;
}

bool PlayerFactory::EndGame() const
{

  unsigned int count = 0;
  vector<Navi *>::const_iterator i;

  // La funzione si potrebbe scrivere così

  /*for (i = fleet.begin(); i != fleet.end(); i++)
  {
    if (!(*i)->Sunk())
      return false;
  }
  return true;*/

  // L'abbiamo scritta uguale nelle due Factories, a sto punto potremmo metterla nell'abstract
  // magari chiamandola checkfleet perchè una funzione endgame nell'abstract factory pare 
  // brutto mentre le funzioni check ci stanno sempre bene e in play facciamo una funzione 
  // endgame che per una certa factory chiama il suo checkfleet

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

void PlayerFactory::Turn(Griglia &EnemyGrid, int NumGiocatore)
{

  int x, y;
  cout << "Premi un tasto per mostrare la griglia";
#ifdef _WIN32
  getch();
  #else
  getchp();
  #endif  
  system(CLEAR);
  cout << "Turno giocatore" << NumGiocatore << endl;
  EnemyGrid.DrawEnemy();
  do
  {
    cout << "\nDimmi le coordinate che vuoi colpire " << endl;
    cin >> x >> y;

  } while (!Check(x, y, EnemyGrid));  // controllo coordinate appartenenti alla griglia
  EnemyGrid.Strike(x, y);             // e non ancora colpite, in tal caso chiamo Strike
  system(CLEAR);
  //grid1.DrawAlly();
  EnemyGrid.DrawEnemy();
  cout << "Premi un tasto per oscurare" << endl;
#ifdef _WIN32
  getch();
  #else
  getchp();
  #endif
  system(CLEAR);
}
