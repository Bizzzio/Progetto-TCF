#include "MenuBack.h"

void MenuBack::DrawVoci() const{

    vector<string>::const_iterator i;
    for (i = Voci.begin(); i != Voci.end(); i++)
        cout << (*i) << endl;
}

void MenuBack::Draw() const
{
	cout << "Ritorno indietro" << endl;
}