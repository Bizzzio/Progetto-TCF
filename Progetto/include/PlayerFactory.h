#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H
#include <iostream>
#include <vector>
using std::vector;
#include "Navi.h"
#include "Griglia.h"
#include "Factory.h"

class PlayerFactory : public Factory
{

public:
  PlayerFactory(int dim, int n2, int n3, int n4, int n5, int n6);
  ~PlayerFactory();
  virtual void SetFleet(int n2, int n3, int n4, int n5, int n6);
  virtual vector<Navi *> GetFleet() const;
  virtual Griglia GetGrid() const;
  virtual bool EndGame() const; // funzione che guarda se le navi della flotta sono affondate tutte
  virtual int GetSize() const;
  virtual void Turn(Griglia &, int); // turno giocatore umano

private:
  vector<Navi *> fleet; // vector di puntatori alle navi che costituiscono la flotta
  Griglia grid;         // griglia dove salveremo la disposizione delle navi
};
#endif
