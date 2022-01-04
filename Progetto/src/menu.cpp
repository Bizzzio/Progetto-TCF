#include "Menu.h"

vector<int> Menu::Setup;

void Menu::Add(int x)
{
    Setup.push_back(x);
}

vector<int> Menu::GetSetup()
{
    return Setup;
}