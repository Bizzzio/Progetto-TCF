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
int getch(void)
{
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
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
  // dò in input il numero di navi da 2,3,4,5,6
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
          n = rand() % 2;           // Il % ci dà il resto di una divisione
        } while (n != 1 && n != 0); // Esco solo se n=0 o n=1 e n determinerà l'orientazione della nave
        h = n;
        x = rand() % 10; // con %10 mi restringo ai numeri tra 0 e 9, che poi vengono controllati
        y = rand() % 10; // da CheckCell
      } while (!CheckCell(h, x, y, z));
      fleet.push_back(new Navi(h, x, y, z));
      if (h)
      {
        // Per questa parte forse è più carino creare una funzione "MettiNave" in Factory
        // che prende come argomenti questi più un bool e la lunghezza e richiamarla
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

void ComputerFactory::Turn(Griglia &EnemyGrid, int NumGiocatore)
{

  int x, y;
  bool sparato = false;
  for (int i = 0; i < EnemyGrid.GetSize() && !sparato; i++)
  {
    for (int j = 0; j < EnemyGrid.GetSize() && !sparato; j++)
    {
      if (EnemyGrid.IsHit(i, j) && !EnemyGrid[i][j]->Sunk()) // Controllo se c'è una casella colpita
      {                                                      // di una nave non affondata
        // cout << "sono in" << i << j;
        if (!CheckSurroundings(EnemyGrid, i, j)) // CheckSurroundings ritorna false se spara ad una casella,
        {                                        // quindi in tal caso dobbiamo aggiornare sparato
          //cout << "ho sparato in" << i << j;
          sparato = true; // Appena sparo esco dai cicli for
          break;
        }
      }
    }
  }
  // Se non ho sparato in CheckSurroundings

  vector<int> Choices;
  if (!sparato)
  {
    for (int i = 0; i < EnemyGrid.GetSize() && !sparato; i++)
    {
      for (int j = 0; j < EnemyGrid.GetSize() && !sparato; j++)
      {
        if (EnemyGrid.IsHit(i, j) && !EnemyGrid[i][j]->Sunk())
        {
          //cout << "ishit va bene";
          if (Check(i + 1, j, EnemyGrid))                   // i,j a questo punto indicano una casella colpita di una nave non
          {                                                 // ancora affondata, con Check controllo se le ho già colpite, se
            //cout << "ho sparato in" << i + 1 << j;        // mi viene restituito true non le ho ancora colpite e le inserisco
            Choices.push_back(i + 1);                       // tra le possibilità in Choices
            Choices.push_back(j);
          }
          if (Check(i - 1, j, EnemyGrid))
          {
            //cout << "ho sparato in" << i - 1 << j;
            Choices.push_back(i - 1);
            Choices.push_back(j);
          }
          if (Check(i, j + 1, EnemyGrid))
          {
            //cout << "ho sparato in" << i << j + 1;
            Choices.push_back(i); 
            Choices.push_back(j + 1);
          }
          if (Check(i, j - 1, EnemyGrid))
          {
            //cout << "ho sparato in" << i << j - 1;
            Choices.push_back(i);
            Choices.push_back(j - 1);
          }
        }
      }
    }
  }

  if (Choices.size() > 0)
  {
    system(CLEAR);
    int d = rand() % (Choices.size() / 2);
    EnemyGrid.Strike(Choices[2 * d], Choices[2 * d + 1]);
    sparato = true;
  }
  //
  // a caso
  if (!sparato)
  {    // Se a questo punto non ho ancora sparato sparo alla
       // cella [x][y] purchè stia nella griglia e non sia già
    do // stata colpita
    {
      x = rand() % 10;
      y = rand() % 10;
      //cout << "ho sparato in" << x << y;
    } while (!Check(x, y, EnemyGrid));
    system(CLEAR);
    cout << "Turno giocatore " << NumGiocatore << endl;
    EnemyGrid.Strike(x, y);
  }
  EnemyGrid.DrawAlly();
}

bool ComputerFactory::CheckSurroundings(Griglia &EnemyGrid, int i, int j)
{
  vector<int> Choices;
  //cout << "CheckSurroundings";
  if (IsNave(i + 1, j, EnemyGrid) && Check(i - 1, j, EnemyGrid))   // Se la casella [i+1][j] appartiene alla griglia e [i-1][j] non è
  {                                                                // ancora stata colpita
    //cout << "ho sparato in" << i - 1 << j << "1";
    if (EnemyGrid.IsHit(i + 1, j) && !EnemyGrid[i + 1][j]->Sunk()) // Se c'è una nave non affondata in [i+1][j], [i][j] (sennò non sa-
    {                                                              // rei entrato nella funzione) allora carica tra le possibilità 
      //cout << "Carico " << i - 1 << j << "1";                    // [i-1][j], codice riconosce l'orientazione della nave
      Choices.push_back(i - 1);
      Choices.push_back(j);
    }
  }
  if (Check(i + 1, j, EnemyGrid) && IsNave(i - 1, j, EnemyGrid))
  {
    // cout << "ho sparato in" << i + 1 << j << "2";
    if (EnemyGrid.IsHit(i - 1, j) && !EnemyGrid[i - 1][j]->Sunk())
    {
      //cout << "Carico " << i + 1 << j << "2";
      Choices.push_back(i + 1);
      Choices.push_back(j);
    }
  }
  if (Check(i, j - 1, EnemyGrid) && IsNave(i, j + 1, EnemyGrid))
  {
    //cout << "ho sparato in" << i << j - 1 << "3";
    if (EnemyGrid.IsHit(i, j + 1) && !EnemyGrid[i][j + 1]->Sunk())
    {
      //cout << "Carico " << i << j - 1 << "3";
      Choices.push_back(i);
      Choices.push_back(j - 1);
    }
  }
  if (IsNave(i, j - 1, EnemyGrid) && Check(i, j + 1, EnemyGrid))
  {
    if (EnemyGrid.IsHit(i, j - 1) && !EnemyGrid[i][j - 1]->Sunk())
    {
      //cout << "Carico " << i << j + 1 << "4";
      //cout << "ho sparato in" << i << j + 1 << "4";
      Choices.push_back(i);
      Choices.push_back(j + 1);
    }
  }

  int d;
  if (Choices.size() > 0)
  {
    system(CLEAR);
    d = rand() % (Choices.size() / 2);
    EnemyGrid.Strike(Choices[2 * d], Choices[2 * d + 1]);

    return 0;
  }
  else
    return 1;
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
