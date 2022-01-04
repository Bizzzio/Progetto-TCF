#include "MenuInstructions.h"

void MenuInstructions::DrawVoci() const
{
    vector<string>::const_iterator i;
    for (i = Voci.begin(); i != Voci.end(); i++)
        cout << (*i);
}

void MenuInstructions::Draw() const
{
    cout << "Regole di gioco:" << endl;
}