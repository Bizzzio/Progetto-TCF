#include <iostream>
using std::cout;
using std::endl;


#include "Navi.h"
  

void Navi::SetX(int x){
  X = x; 
}

void Navi::SetY(int y){
  X = x; 
}

void SetHorizontal (bool horizontal){
  Horizontal=horizontal;
}

int Navi::GetX() const{
  return X; 
}

int Navi::GetY() const{
  return Y; 
}

bool IsHorizontal () const {
  return Horizontal;
}

vector<bool> GetVector() const {
  return Hit;
}