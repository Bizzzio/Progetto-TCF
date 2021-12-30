#include "Navi.h"
//#include "Acqua.h"
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
    Navi Water;
};
#endif

