#include "MenuBack.h"

MenuBack::MenuBack(){
    Voci= "Back to menu";
}

MenuBack::MenuBack(string s){
    Voci=s;
}

void MenuBack::DrawVoci() const
{
    cout<<Voci;
}
