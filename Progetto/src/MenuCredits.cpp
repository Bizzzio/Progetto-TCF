#include "MenuCredits.h"

void MenuCredits::DrawVoci() const
{

    vector<string>::const_iterator i;
    for (i = Voci.begin(); i != Voci.end(); i++)
        cout << (*i) << endl;
}

void MenuCredits::Draw() const
{
    cout << "Regole di gioco:" << endl;
}