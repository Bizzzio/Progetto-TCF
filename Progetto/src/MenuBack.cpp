#include "MenuBack.h"

MenuBack::MenuBack(){
    Voci.push_back("Back to menu");
}

MenuBack::MenuBack(string s){
    Voci.push_back(s);
}

void MenuBack::DrawVoci() const
{
    vector<string>::const_iterator i;
    for (i = Voci.begin(); i != Voci.end(); i++)
        cout << (*i);
}

void MenuBack::Draw() const
{
    cout << "Ritorno indietro" << endl;
}