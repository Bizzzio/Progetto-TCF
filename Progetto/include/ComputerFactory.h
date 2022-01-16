#ifndef COMPUTERFACTORY_H
#define COMPUTERFACTORY_H
#include <iostream>
#include <cstdlib>
using std::vector;
#include <vector>
#include "Navi.h"
#include "Griglia.h"
#include "Factory.h"

class ComputerFactory : public Factory
{

public:
	ComputerFactory(int dim, int n2, int n3, int n4, int n5, int n6);
	~ComputerFactory();
	virtual void SetFleet(int n2, int n3, int n4, int n5, int n6);
	virtual vector<Navi *> GetFleet() const;
	virtual Griglia GetGrid() const;
	virtual bool EndGame() const;
	virtual int GetSize() const; // ritorna dimensione griglia
	void Turn(Griglia &EnemyGrid, int NumGiocatore);  // turno di gioco computer
	bool CheckSurroundings(Griglia &EnemyGrid, int i, int j); // Intelligenza artificiale per scelta intelligente
															  // delle caselle	

private:
	vector<Navi *> fleet;  // vector di puntatori alle navi che costituiscono la flotta
	Griglia grid;		   // griglia dove salveremo la disposizione delle navi
};
#endif