#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H
#include <iostream>
using namespace std;
#include <vector>
#include "Navi.h"
#include "Griglia.h"
#include "Factory.h"

class PlayerFactory : public Factory {

	public:
  PlayerFactory(int dim, int n2,int n3, int n4, int n5, int n6);
  ~PlayerFactory();
  virtual void SetFleet(int n2, int n3, int n4, int n5, int n6);
  virtual vector<Navi*> GetFleet() const;
  virtual Griglia GetGrid() const;
  virtual bool EndGame() const;
  virtual int GetSize() const;
  virtual void Turn(Griglia, int);

  private:
  vector<Navi*> fleet;
  Griglia grid;
  
};
#endif
