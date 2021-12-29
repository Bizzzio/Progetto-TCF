#include "Navi2.h"
using std::cout;

Navi2::Navi2 (bool horizontal, int x, int y) {
  length = 2;
  SetHorizontal(horizontal);
  SetX(x);
  SetY(y);
  for (int i=0;i<lenght;i++)
  	Hit.push_back(false);
}

bool Navi2::Sunk(vector<bool> hit) const {
  
  vector<bool>::iterator k;
  
  for(k=hit.begin(); k<hit.end(); k++){
    if(!hit[k])
      return false;
  }
  
  return true;
  
}

void Navi2::DrawEnemy(int x, int y) const{
  if (Sunk(Hit))  
  {
    cout << length;
  }
  else
  {
    if (IsHorizontal)
      {
        if (Hit(x-GetX))
          cout<<"X ";
        else 
          cout<<". ";
      }
      else
      {
        if (Hit(y-GetY))
          cout<<'X ';
        else 
          cout<<". ";
      }
  }
}


void Navi2::DrawAlly(int x, int y) const{

    if (IsHorizontal)
      {
        if (Hit(x-GetX))
          cout<<"X ";
        else 
          cout<<length;
      }
      else
      {
        if (Hit(y-GetY))
          cout<<'X ';
        else 
          cout<<length;
      }
}
