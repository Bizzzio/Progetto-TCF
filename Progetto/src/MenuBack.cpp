#include "MenuBack.h"

MenuBack::MenuBack()
{
    Voci = "Torna indietro";
}

MenuBack::MenuBack(string s)
{
    Voci = s;
}

void MenuBack::DrawVoci() const
{
    cout << Voci;
}
