#include "MenuPlay.h"

MenuPlay::MenuPlay()
{
	voci.push_back("1 giocatore");
	voci.push_back("2 giocatori");
	voci.push_back("Back to menu");
}

void MenuPlay::DrawVoci() const
{
	cout << "Play";
}


void MenuPlay::Draw() const
{
	unsigned int pos = 0;
	cout << "Selezionare la configurazione usando le frecce" << endl;

	do
	{
		system(CLEAR);
    	PrintVoci(pos,voci);
    	pos = Arrows(&pos, voci);          //arrows permette di muoversi dentro il menu

		switch (pos)
		{
		case 0:
		{
			system(CLEAR);
			/* 
			int a;
			cout << "Selezionare la difficoltà: 0 per facile, 1 per difficile: "
			do{
				cin >> a;
			}while(a!=0 && a!=1)
			Menu::Add(a);
			*/
			vector<int> setup = Menu::GetSetup();
			Factory *p1 = new PlayerFactory(setup[1], setup[2], setup[3], setup[4], setup[5], setup[6]);
			Factory *p2 = new ComputerFactory(setup[1], setup[2], setup[3], setup[4], setup[5], setup[6]);
			Play *play = new Play(p1, p2);
			play->PlayBattleship();
			break;
		}
		case 1:
		{
			system(CLEAR);
			vector<int> setup = Menu::GetSetup();
			Factory *p1 = new ComputerFactory(setup[1], setup[2], setup[3], setup[4], setup[5], setup[6]); //dovrà essere new PlayerFactory
			Factory *p2 = new ComputerFactory(setup[1], setup[2], setup[3], setup[4], setup[5], setup[6]); //dovrà essere new PlayerFactory
			Play *play = new Play(p1, p2);
			play->PlayBattleship();
			break;
		}

		default:
			break;
		}
	} while (pos != voci.size() - 1);

}
