#include "Navi.h"
#ifndef NAVI5_H
#define NAVI5_H

class Navi5 : public Navi
{

public:
    Navi5(bool, int, int);
    virtual void DrawEnemy(int, int) const;
    virtual void DrawAlly(int, int) const;
    virtual bool Sunk(vector<bool>) const;
    vector<bool> GetVector() const;
    virtual void Strike(int, int);
private:
    //int length;
    vector<bool> Hit;
};

#endif