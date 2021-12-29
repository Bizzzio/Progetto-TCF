#ifndef ACQUA_H
#define ACQUA_H
#include "Navi.h"

class Acqua : public Navi{
  
public:
  Acqua();
	virtual void DrawEnemy(int, int) const {cout<<"~ "};
	virtual void DrawAlly(int, int) const {cout <<"~ "};
	virtual bool Sunk(vector<bool>) const {return false};
	virtual void Strike(int, int) {};
  
};

#endif