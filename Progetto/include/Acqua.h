#ifndef ACQUA_H
#define ACQUA_H
#include "Navi.h"
using std::cout;

class Acqua : public Navi{
  
public:
  Acqua()
  {
    SetLength(0);
    SetHorizontal(false);
    SetX(0);
    SetY(0);
  }
	virtual void DrawEnemy(int, int) const {cout<<"~ ";}
	virtual void DrawAlly(int, int) const {cout <<"~ ";}
	virtual bool Sunk(vector<bool>) const {return false;}
	virtual void Strike(int, int) {};
  
};

#endif
