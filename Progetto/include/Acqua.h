#ifndef ACQUA_H
#define ACQUA_H
#include "Navi.h"

class Acqua : public Navi{
  
public:
  Acqua()
  {
    Length=0;
    Horizontal=false;
    X=0;
    Y=0;
  }
	virtual void DrawEnemy(int, int) const {cout<<"~ "};
	virtual void DrawAlly(int, int) const {cout <<"~ "};
	virtual bool Sunk(vector<bool>) const {return false};
	virtual void Strike(int, int) {};
  
};