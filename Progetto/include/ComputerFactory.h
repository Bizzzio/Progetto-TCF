#ifndef COMPUTERFACTORY_H
#define COMPUTERFACTORY_H
#include <iostream>
#include <cstdlib>
using namespace std;
#include <vector>
#include "Navi.h"
#include "Griglia.h"
#include "Factory.h"

class ComputerFactory : public Factory {

	public:
  	ComputerFactory(int dim, int n2,int n3, int n4, int n5, int n6);
  	~ComputerFactory();
  	virtual void SetFleet(int n2, int n3, int n4, int n5, int n6);
  	virtual vector<Navi*> GetFleet() const;
  	virtual Griglia GetGrid() const;
  	virtual bool EndGame() const;
  	virtual int GetSize() const;

  	private:
  	vector<Navi*> fleet;
  	Griglia grid;
  
};
#endif