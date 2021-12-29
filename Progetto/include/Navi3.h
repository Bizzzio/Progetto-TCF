#include "Navi.h"
#ifndef NAVI3_H
#define NAVI3_H

class Navi3 : public Navi
{

public:
    Navi3(bool, int, int);
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