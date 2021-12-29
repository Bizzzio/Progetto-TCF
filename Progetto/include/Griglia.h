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
    vector<vector<*Navi>> grid;
private:
    // vector<vector<*Navi>> grid;
};
#endif