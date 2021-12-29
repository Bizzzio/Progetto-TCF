#include "Navi.h"
#ifndef NAVI2_H
#define NAVI2_H

class Navi2 : public Navi
{

public:
    Navi2(bool, int, int);
    virtual void DrawEnemy(int, int) const;
    virtual void DrawAlly(int, int) const;
    virtual bool Sunk(vector<bool>) const;
    vector<bool> GetVector() const;
    virtual void Strike(int, int);
private:
    int length;
    vector<bool> Hit;
};

#endif