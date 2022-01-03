#ifndef MENU_H
#define MENU_H

#ifdef _WIN32
	#include <conio.h>
	#include <windows.h>
#else

	#include <unistd.h>
	#include <termios.h>

	char getch() {
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
				perror ("read()");
		old.c_lflag |= ICANON;
		old.c_lflag |= ECHO;
		if (tcsetattr(0, TCSADRAIN, &old) < 0)
				perror ("tcsetattr ~ICANON");
		return (buf);
}
#endif

#ifndef MENU_H
#define MENU_H
#include<iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Menu
{
    public:
        virtual void Draw() const = 0;
  		
	private: 
  		static int Config;
  		
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> f28ab04d8034400bad31874e37d56f07eb0d22f9
