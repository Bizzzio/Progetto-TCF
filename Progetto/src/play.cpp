
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
using std::system;
#include "Play.h"

Play::Play(Factory* player1, Factory* player2){
	
  grid1 = player1->GetGrid();
  grid2 = player2->GetGrid();
  Player1 = player1;
	Player2 = player2;
  
}


void Play::PlayBattleship(){    // serve fuzione per cancellare gli output
	int x,y;
  do{
    
    do{
      cout << "\nDimmi le coordinate che vuoi colpire "<< endl;
      cin >> x >> y;
    }while(!Check(x,y,grid1));
    	grid2.Strike(x,y);
    
    	grid1.DrawAlly();
    	grid2.DrawEnemy();
       
    
    system ("cls");
		do{
    cout << "\nDimmi le coordinate che vuoi colpire "<< endl;
    cin >> x >> y;
    }while(!Check(x,y,grid2));
    	grid1.Strike(x,y);
    
    	grid2.DrawAlly();
    	grid1.DrawEnemy();
    
    
    system ("cls");
    
  }while(Player1->EndGame() || Player2->EndGame())

}

bool Play::Check(int x, int y, Griglia grid){
	
  int s = grid.GetSize();
  
  if(x>=s && y>=s){
    cout << "Coordinate fuori target. Riprovare." << endl;
    return false;
  }
  
	else{
  	if(!(grid[x][y]->IsHit(x,y)) || grid[x][y]==NULL)
    	return true;
    else{
    	cout << "Coordinate già colpite. Riprovare." << endl;
    	return false;
    }
  }
 
}