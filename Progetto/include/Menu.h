#ifndef MENU_H
#define MENU_H

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else

#include <unistd.h>
#include <termios.h>

/*char get()
{
	char buf = 0;
	struct termios old = {0};
	if (tcgetattr(0, &old) < 0)
		perror("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");
	if (read(0, &buf, 1) < 0)
		perror("read()");
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &old) < 0)
		perror("tcsetattr ~ICANON");
	return (buf);
}*/
#endif

#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Menu
{

public:
	virtual void DrawVoci() const {};
	virtual void Draw() const = 0;
	static void Add(int);

	static vector<int> GetSetup();

private:
	static vector<int> Setup;
};

#endif
