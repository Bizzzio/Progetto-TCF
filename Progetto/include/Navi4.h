#include "Navi.h"
#ifndef NAVI4_H
#define NAVI4_H

class Navi4 : public Navi
{

public:
    Navi4(bool, int, int);
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