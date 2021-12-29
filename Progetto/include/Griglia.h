#include "Navi.h"
#include "Navi2.h"
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
    //vector < vector <  Navi* > > grid;

private:
    vector<vector<Navi*> > grid;
    int size;
};
#endif