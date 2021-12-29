#include "Navi.h"
#include "Navi2.h"
#ifndef GRIGLIA_H
#define GRIGLIA_H

#include <vector>
using std::vector;

class Griglia
{
  
  friend vector<Navi*> operator[] (Griglia g, int i);
  
public:
    Griglia(int);

    void DrawEnemy() const;
    void DrawAlly() const;
    //vector < vector <  Navi* > > grid;

private:
    vector<vector<Navi*> > grid;
    int size;
};
#endif