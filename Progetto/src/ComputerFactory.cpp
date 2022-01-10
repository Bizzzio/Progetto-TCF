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

void ComputerFactory::Turn(Griglia EnemyGrid, int NumGiocatore){
  	
  	int x,y;
    bool sparato=false;
  	cout << "Turno giocatore" << NumGiocatore <<  endl;
  	for(unsigned int i=0;i<EnemyGrid.GetSize();i++ ){
      for(unsigned int j=0;j<EnemyGrid.GetSize();j++){
        if(EnemyGrid.IsHit(i,j))
        {
          if(!CheckSurroundings(Enemygrid,i,j))
          {
          	sparato=true;
          	break;
          }
        }
      }
    }
    if(!sparato)
    {
      for(unsigned int i=0;i<EnemyGrid.GetSize();i++ )
      {
        for(unsigned int j=0;j<EnemyGrid.GetSize();j++)
        {
          if(EnemyGrid.IsHit(i,j))
          {
              if(Check(i+1,j,EnemyGrid))
              { 
                  EnemyGrid.Strike(i+1,j);
                  sparato=true;
                  break;
              }
            else if(Check(i-1,j,EnemyGrid))
            {
              EnemyGrid.Strike(i-1,j);
              sparato=true;
              break;
            }
            else if(Check(i,j+1,EnemyGrid))
            {
              EnemyGrid.Strike(i,j+1);
              sparato=true;
              break;
            }
            else if(Check(i,j-1,EnemyGrid))
            {
              EnemyGrid.Strike(i,j-1);
              sparato=true;
              break;
          	}
          }
        }
      }
    }
        
          
          if(!sparato){
          do{
            x = rand()%10;
            y = rand()%10;
            }while(!Check(x,y,EnemyGrid));
            EnemyGrid.Strike(x,y);
        
          }
	
  
}


  
bool ComputerFactory::CheckSurroundings(Griglia EnemyGrid, int i,int j)
{
				if(EnemyGrid.IsHit(i+1,j) && Check(i-1,j,EnemyGrid) && !EnemyGrid[i+1][j]->Sunk()){ 
            EnemyGrid.Strike(i-1,j);
          	return 0;
          }
          else if(EnemyGrid.IsHit(i-1,j) && Check(i+1,j,EnemyGrid) && !EnemyGrid[i-1][j]->Sunk()){ 
            EnemyGrid.Strike(i+1,j);
          	return 0;
          }
          else if(EnemyGrid.IsHit(i,j+1) && Check(i,j-1,EnemyGrid) && !EnemyGrid[i][j+1]->Sunk()){ 
            EnemyGrid.Strike(i,j-1);
          	return 0;
          }
          else if(EnemyGrid.IsHit(i,j-1) && Check(i,j+1,EnemyGrid) && !EnemyGrid[i][j-1]->Sunk()){ 
            EnemyGrid.Strike(i,j+1);
          	return 0;
          return 1;
}
 