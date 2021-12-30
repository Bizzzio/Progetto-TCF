#include "Navi.h"
//#include "Acqua.h"
#ifndef GRIGLIA_H
#define GRIGLIA_H

#include <vector>
using std::vector;

//la griglia è rappresentata da una matrice grid di puntatori di tipo Navi. Le caselle di tipo acqua non ancora colpite puntano ad un puntatore nullo; quando vengono colpite
//puntano alla nave Water, che è un data member della classe griglia. Le caselle occupate da una nave puntano tutte a quella nave.

class Griglia
{

public:
    Griglia(int);                               //il parametro in input rappresenta la dimensione della griglia
    vector<Navi*> operator[] (int);             //l'operatore [] richiama la posizione del vettore grid
    void DrawEnemy() const;                     //le funzioni Draw si occupano di stampare la griglia chiamando le funzioni Draw delle navi se la casella è occupata da una nave 
    void DrawAlly() const;                      //(o acqua colpita), oppure stampare un punto quando la cella è occupata da un'acqua non colpita
    void SetGriglia(int, int, Navi*);           //fa puntare la casella in input ad una nave in input
    void Strike(int, int);                      //gestisce il colpire una certa casella, richiamando la funzione Strike delle navi.
    //vector < vector <  Navi* > > grid;

private:
    vector<vector<Navi*> > grid;                //una matrice che rappresenta la griglia
    int size;                                   //la dimensione della griglia
    Navi Water;                                 //rappresenta la nave a cui puntano le caselle di tipo acqua dopo che vengono colpite
};
#endif

