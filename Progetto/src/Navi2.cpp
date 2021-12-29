#include "Navi2.h"
#include <iostream>
using std::cout;

Navi2::Navi2 (bool horizontal, int x, int y) {
  length = 2;
  SetHorizontal(horizontal);
  SetX(x);
  SetY(y);
  for (int i=0;i<length;i++)
  	Hit.push_back(false);
}

bool Navi2::Sunk(vector<bool> hit) const {
  
  vector<bool>::iterator k;
  
  for(k=hit.begin(); k<hit.end(); k++){
    if(!(*k))
      return false;
  }
  
  return true;
  
}

void Navi2::DrawEnemy(int x, int y) const{
  if (Sunk(GetVector()))  
  {
    cout << length;
  }
  else
  {
    if (IsHorizontal())
      {
        if (GetVector()[x-GetX()])
          cout<<"X ";
        else 
          cout<<". ";
      }
      else
      {
        if (GetVector()[y-GetY()])
          cout<<"X ";
        else 
          cout<<". ";
      }
  }
}


void Navi2::DrawAlly(int x, int y) const{
  //cout<<"ciao";
  //vector<bool> hit = GetVector();
  //cout<<Hit[0];
    if (IsHorizontal())
      {
        if (GetVector()[x-GetX()])
          cout<<"X ";
        else 
          cout<<length<<" ";
      }
      else
      {
        if (GetVector()[y-GetY()])
          cout<<"X ";
        else 
          cout<<length<< " ";
      }
}


vector<bool> Navi2::GetVector() const
{
  return Hit;
}

void Navi2::Strike(int x, int y)
{
  if (IsHorizontal())
        Hit[x-GetX()]=true;

  else
      Hit[y-GetY()]=true;
}