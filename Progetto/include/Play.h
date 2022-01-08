#ifndef PLAY_H
#define PLAY_H
#include <iostream>
using namespace std;
#include <vector>
#include "Factory.h"
#include "PlayerFactory.h"
#include "ComputerFactory.h"
#ifdef _WIN32
#include <conio.h>
#define CLEAR "cls"
#else
#define CLEAR "clear"
#include <unistd.h>
#include <termios.h>
void getch()
{
	char a;
	struct termios t;
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);

	cin >> a;
}
#endif

class Play
{

public:
	Play(Factory *, Factory *);
	~Play(){};
	bool Check(int, int, Griglia);
	void PlayBattleship();

private:
	Griglia grid1;
	Griglia grid2;
	Factory *Player1;
	Factory *Player2;
};

#endif