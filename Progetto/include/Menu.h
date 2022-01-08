#ifndef MENU_H
#define MENU_H

#ifdef _WIN32
#define CLEAR "cls"
#include <conio.h>
#include <windows.h>
#else
#define CLEAR "clear"
#include <unistd.h>
#include <termios.h>

#endif

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*#ifdef _WIN32
//#include <conio.h>
#define CLEAR "CLEAR"
#else
#define CLEAR "clear"
//#include <unistd.h>
//#include <termios.h>
void getcha()
{
	char a;
	struct termios t;
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ICANON;
	tcsetattr(STDIN_FILENO, TCSANOW, &t);

	cin >> a;
}
#endif*/

class Menu
{

public:
	
	unsigned int Arrows(unsigned int *pos, vector<Menu *>) const;
	unsigned int Arrows(unsigned int *pos, vector<string>) const;
	virtual void PrintVoci(unsigned int) const=0;
	virtual void DrawVoci() const {};
	virtual void Draw() const = 0;
	static void Add(int);

	static vector<int> GetSetup();

private:
	static vector<int> Setup;
};

#endif
