#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
using namespace std;
#include <vector>
#include "Navi.h"
#include "Griglia.h"

class Factory {

	public:
  Factory(int dim, int n2,int n3, int n4, int n5, int n6);
  ~Factory();
  void SetFleet(int n2, int n3, int n4, int n5, int n6);
  vector<Navi*> GetFleet() const;
  Griglia GetGrid() const;
  bool EndGame() const;

  private:
  vector<Navi*> fleet;
  Griglia grid;
  
};
#endif
