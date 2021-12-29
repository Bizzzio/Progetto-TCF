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

void Navi::SetLength(int length)
{
  Length=length;
}

int Navi::GetX() const
{
  return X;
}

int Navi::GetY() const
{
  return Y;
}

int Navi::GetLength() const
{
  return Length;
}

bool Navi::IsHorizontal() const
{
  return Horizontal;
}
