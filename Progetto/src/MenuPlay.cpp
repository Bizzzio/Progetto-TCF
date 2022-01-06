#include "MenuPlay.h"

void MenuPlay::DrawVoci() const
{
	cout << "Play";
}

void MenuPlay::PrintVoci(int pos) const
{
#ifdef _WIN32
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Selezionare la configurazione usando le frecce" << endl;
	for (int d = 0; d < voci.size(); d++)
	{
		if (d == pos)
		{
			SetConsoleTextAttribute(h, 10);
			cout << "--> " << voci[d];
			SetConsoleTextAttribute(h, 15);
			cout << endl;
		}
		else
			cout << voci[d];
		cout << endl;
	}
#else
	cout << "Selezionare la configurazione usando le frecce" << endl;
	for (int d = 0; d < voci.size(); d++)
	{
		if (d == pos)
		{
			cout << "\033[32m"
				 << "--> " << voci[d];
			cout << "\033[0m" << endl;
		}
		else

			cout << voci[d] << endl;
	}
#endif
}

void MenuPlay::Draw() const
{
	vector<string>::iterator i;

	for (int c = 0; c < voci.size(); c++)
		cout << voci[c] << endl;

#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
	/*cout<<"ciao";
		int ch;
		ch=getch();
		cout<<ch;
		getch();
		//system("cls");*/
	int c, ex, pos = 0;
	cout << "Selezionare la configurazione usando le frecce" << endl;

	PrintVoci(0);
	system("cls");
	do
	{
		PrintVoci(pos);

		do
		{

			c = getch();
			if (c == 0 || c == 224)
			{
				switch (ex = getch())
				{
				case KEY_UP /* H */:
					//cout << endl << "Up" << endl;//key up
					if (pos != 0)
						pos--;
					break;
				case KEY_DOWN /* K */:
					//cout << endl << "Down" << endl;   // key down
					if (pos < voci.size() - 1)
						pos++;
					break;

				default:
					break;
				}
				system("cls");
				if (c != 13)
					PrintVoci(pos);
			}
		} while (c != 13);

		/*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

		switch (pos)
		{
		case 0:
			//Factory* p1=new PlayerFactory;
			//Factory* p2=new ComputerFactory;
			//Play* play=new Play (p1,p2);
			break;
		case 1:
		{
			system("cls");
			vector<int> setup = Menu::GetSetup();
			Factory *p1 = new Factory(10, setup[0], setup[1], setup[2], setup[3], setup[4]); //dovrà essere new PlayerFactory
			Factory *p2 = new Factory(10, setup[0], setup[1], setup[2], setup[3], setup[4]); //dovrà essere new PlayerFactory
			Play *play = new Play(p1, p2);
			play->PlayBattleship();
			break;
		}

		default:
			break;
		}
#endif
	} while (pos != voci.size() - 1);
}
