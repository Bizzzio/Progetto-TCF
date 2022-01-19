#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
#include <vector>
using std::vector;
#include "Navi.h"
#include "Griglia.h"

class Factory
{

public:
        //Factory(int dim, int n2,int n3, int n4, int n5, int n6);
        //~Factory();
        virtual void SetFleet(int n2, int n3, int n4, int n5, int n6) = 0; // funzione per costruzione flotta
        virtual vector<Navi *> GetFleet() const = 0;
        virtual Griglia GetGrid() const = 0;
        virtual bool EndGame() const = 0; // funzione che verifica se le navi della flotta sono tutte affondate,
                                          // serve per terminare il gioco
        virtual int GetSize() const = 0;
        virtual void Turn(Griglia &, int) = 0;             // funzione che implementa il turno di gioco
        virtual bool CheckCell(bool, int, int, int) const; // funzione che controlla se le celle in cui voglio posizionare
                                                           // le navi vanno bene o sono già occupate
        bool Check(int, int, Griglia &);                   // funzione che controlla se le caselle indicate dagli interi sono state
                                                           // già colpite oppure no
        bool IsNave(int, int, Griglia &);
};
#endif
