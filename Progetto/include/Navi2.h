#include "navi.h"
#ifndef NAVI2_H
#define NAVI2_H

class Navi2 : public Navi
{

public:
    Navi2(bool, int, int);
    virtual void DrawEnemy(int, int) const;
    virtual void DrawAlly(int, int) const;
};

#endif