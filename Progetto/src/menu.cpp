#include "Menu.h"

vector<int> Menu::Setup{1, 0, 0, 0, 0};

void Menu::Add(int x)
{
    Setup.push_back(x);
}

vector<int> Menu::GetSetup()
{
    return Setup;
}