#include <iostream>
#include <vector>
#include <string>
#ifdef _WIN32
#include <conio.h>
#define CLEAR "cls"
#else
#define CLEAR "clear"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
int getchp(void)
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return ch;
}
#endif
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
#include "PlayerFactory.h"
// abbiamo creato la griglia da 10
// le regole sono che si possono usare 1 nave da 4, 1 da 5, 3 da 3, 3 da 2

PlayerFactory::PlayerFactory(int dim, int n2, int n3, int n4, int n5, int n6) : grid(dim)
{ //PlayerFactory::PlayerFactory(int dim, int n2,int n3, int n4, int n5, int n6)

	SetFleet(n2, n3, n4, n5, n6); //SetFleet(n2,n3,n4,n5,n6)
}

int PlayerFactory::GetSize() const
{
	return grid.GetSize();
}

void PlayerFactory::SetFleet(int n2, int n3, int n4, int n5, int n6)
{
	// dò in input il numero di navi da 2,3,4,5,6
	int numbers[5] = {n2, n3, n4, n5, n6};

	for (int i = 0, z = 2; i < 5; i++)
	{

		for (int j = 0; j < numbers[i]; j++)
		{
			int x, y, n;
			bool h;
			string input;
			grid.DrawAlly();
			do
			{
				cout << "\nVuoi la " << j + 1 << "a nave, da " << z << " caselle, orizzontale(=1) o verticale(=0)?" << endl;
				cin >> input;
				while (input.length() != 1 || (input[0] != 48 && input[0] != 49))  // ripeto finchè la lunghezza della stringa è diversa
				{																   // da 1 e finchè carattere diverso da 0 o 1
					cout << "Inserire 0 o 1" << endl;
					cin >> input;
				}
				h = input[0] - '0';

				cout << "\nDammi una x e una y per posizionare la nave sulla griglia" << endl;
				cin >> input;
				while (input.length() != 1 || (input[0] < 48 || input[0] > 57))
				{
					cout << "Inserire un numero valido" << endl;
					cin >> input;
				}
				x = input[0] - '0';
				cin >> input;
				while (input.length() != 1 || (input[0] < 48 || input[0] > 57))
				{
					cout << "Inserire un numero valido" << endl;
					cin >> input;
				}
				y = input[0] - '0';
			} while (!CheckCell(h, x, y, z));
			fleet.push_back(new Navi(h, x, y, z));
			if (h)
			{
				for (int i = 0; i < z; i++)
					grid.SetGriglia(x + i, y, fleet.back());
			}
			else
			{
				for (int i = 0; i < z; i++)
					grid.SetGriglia(x, y + i, fleet.back());
			}
			system(CLEAR);
			//fleet.DrawAlly(x,y);
		}
		z++;
	}
	grid.DrawAlly();
	cout << "Premi un tasto per oscurare" << endl;
#ifdef _WIN32
	getch();
#else
	getchp();
#endif
	system(CLEAR);
	//system(CLEAR);
}

vector<Navi *> PlayerFactory::GetFleet() const
{
	return fleet;
}

Griglia PlayerFactory::GetGrid() const
{
	return grid;
}

PlayerFactory::~PlayerFactory()
{
	vector<Navi *>::iterator i;
	for (i = fleet.begin(); i != fleet.end(); i++)
		delete *i;
}

bool PlayerFactory::EndGame() const
{

	unsigned int count = 0;
	vector<Navi *>::const_iterator i;

	for (i = fleet.begin(); i != fleet.end(); i++)
	{
		//cout << "count:" << count << " size:" << fleet.size() << " ";
		if ((*i)->Sunk())
			count++;
		else
			return false;
	}

	if (count == fleet.size())
	{

		return true;
	}
	else
		return false;
}

void PlayerFactory::Turn(Griglia &EnemyGrid, int NumGiocatore)
{

	int x, y;
	cout << "Premi un tasto per mostrare la griglia";
#ifdef _WIN32
	getch();
#else
	getchp();
#endif
	system(CLEAR);
	cout << "Turno giocatore" << NumGiocatore << endl;
	EnemyGrid.DrawEnemy();
	do
	{
		string input;
		cout << "\nDimmi le coordinate che vuoi colpire " << endl;
		cin >> input;
		while (input.length() != 1 || (input[0] < 48 || input[0] > 57))  // la seconda condizione identifica i numeri da tastiera, il
		{																 // ciclo continua finchè non viene inserito un numero	
			cout << "Inserire un numero valido" << endl;
			cin >> input;
		}
		x = input[0] - '0';
		cin >> input;
		while (input.length() != 1 || (input[0] < 48 || input[0] > 57))
		{
			cout << "Inserire un numero valido" << endl;
			cin >> input;
		}
		y = input[0] - '0';

	} while (!Check(x, y, EnemyGrid)); // controllo coordinate appartenenti alla griglia
	EnemyGrid.Strike(x, y);			   // e non ancora colpite, in tal caso chiamo Strike
	system(CLEAR);
	//grid1.DrawAlly();
	EnemyGrid.DrawEnemy();
	cout << "Premi un tasto per oscurare" << endl;
#ifdef _WIN32
	getch();
#else
	getchp();
#endif
	system(CLEAR);
}
