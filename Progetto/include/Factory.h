#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
using namespace std;
#include <vector>
#include "Navi.h"
#include "Griglia.h"

class Factory
{

public:
        //Factory(int dim, int n2,int n3, int n4, int n5, int n6);
        //~Factory();
        virtual void SetFleet(int n2, int n3, int n4, int n5, int n6) = 0;
        virtual vector<Navi *> GetFleet() const = 0;
        virtual Griglia GetGrid() const = 0;
        virtual bool EndGame() const = 0;
        virtual int GetSize() const = 0;
        virtual void Turn(Griglia &, int) = 0;
        bool Check(int, int, Griglia &);
};
#endif
