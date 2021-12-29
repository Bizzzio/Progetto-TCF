#include "Navi.h"
#include "Navi2.h"
#include "Navi3.h"
#include "Navi4.h"
#include "Navi5.h"
#include "Navi6.h"
#include "Acqua.h"
#ifndef GRIGLIA_H
#define GRIGLIA_H

#include <vector>
using std::vector;

class Griglia
{
  
public:
    Griglia(int);
    vector<Navi*> operator[] (int);
    void DrawEnemy() const;
    void DrawAlly() const;
    void SetGriglia(int, int, Navi*);
  	void Strike(int, int);
    //vector < vector <  Navi* > > grid;

private:
    vector<vector<Navi*> > grid;
    int size;
  	Acqua Water;
};
#endif
