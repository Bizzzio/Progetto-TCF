#include <iostream>
#include <vector>
#include "Factory.h"
#include "Play.h"
#include "MenuText.h"
#include "MenuDiramazione.h"
#include "MenuOpzioni.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{

	MenuDiramazione MenuPrincipale;
	MenuPrincipale.Draw();

	return 0;
}
