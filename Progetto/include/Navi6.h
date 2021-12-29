#include "Navi.h"
#ifndef NAVI6_H
#define NAVI6_H

class Navi6 : public Navi
{

public:
    Navi6(bool, int, int);
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