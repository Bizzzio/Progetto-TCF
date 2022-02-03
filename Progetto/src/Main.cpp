#include "MenuDiramazione.h"
#include <time.h>

int main()
{

	srand(time(NULL));

	MenuDiramazione MenuPrincipale;
	MenuPrincipale.Draw();

	return 0;
}
