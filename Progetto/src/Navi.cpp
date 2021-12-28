#include <iostream>
#include "Navi.h"
using namespace std;

void Navi::SetX(int x)
{
  X = x;
}

void Navi::SetY(int y)
{
  Y = y;
}

void Navi::SetHorizontal(bool horizontal)
{
  Horizontal = horizontal;
}

int Navi::GetX() const
{
  return X;
}

int Navi::GetY() const
{
  return Y;
}

bool Navi::IsHorizontal() const
{
  return Horizontal;
}

vector<bool> Navi::GetVector() const
{
  return Hit;
}