#ifndef GRIGLIA_H
#define GRIGLIA_H
using namespace std;
#include 'Navi.h'

class Griglia
{
public:
    Griglia(int);

    void DrawEnemy() const;
    void DrawAlly() const;

private:
    vector<vector<*Navi>> grid;
};
#endif