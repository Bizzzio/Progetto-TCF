#include "MenuOption.h"
void MenuOption::DrawVoci() const
{
    vector<string>::const_iterator i;
    for (i = Voci.begin(); i != Voci.end(); i++)
        cout << (*i);
}

MenuOption::MenuOption()
{

    string valore;
    ifstream file("src/Setup.txt");
    if (file.is_open())
    {
        while (getline(file, valore))
            Config.push_back(valore);

        file.close();
    }
    else
    {
        file.open("Setup.txt");
        if (file.is_open())
        {
            while (getline(file, valore))
                Config.push_back(valore);

            file.close();
        }
        else
            cout << "Unable to open file";
    }
}

void MenuOption::Draw() const
{
    SelectWindows();
}
void MenuOption::PrintVoci(int pos) const
{
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Selezionare la configurazione usando le frecce" << endl;
    for (int d = 0; d < Config.size(); d++)
    {
        if (d == pos)
        {
            SetConsoleTextAttribute(h, 10);
            cout << "--> ";
            Config[d];
            SetConsoleTextAttribute(h, 15);
            cout << endl;
        }
        else
            Config[d];
        cout << endl;
    }
#else
    cout << "Selezionare la configurazione usando le frecce" << endl;
    for (int d = 0; d < Config.size(); d++)
    {
        if (d == pos)
        {
            cout << "\033[32m"
                 << "--> ";
            Config[d];
            cout << "\033[0m" << endl;
        }
        else
            Config[d];
        cout << endl;
    }
#endif
}

void MenuOption::SelectWindows() const
{
#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

    int c, ex, pos = 0;

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
                    if (pos < Config.size() - 1)
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
        system("cls");
        /*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

        if (pos)
            for (int i = 0; i < 5; i++)
            {
                Menu::Add(Config[pos][2 * i] - '0');
            }
    } while (pos);

#else
#include <iostream>
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_DOWN 66

    // Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    int pos = 0;
    char c, d, e;
    cout << "Selezionare la configurazione usando le frecce" << endl;

    PrintVoci(0);
    system("clear");
    do
    {
        PrintVoci(pos);

        do
        {
            //char c, d, e;
            cin >> c;
            if (c != 'a')
            {
                cin >> d;
                cin >> e;
                if ((c == 27) && (d = 91))
                {
                    switch (e)
                    {
                    case KEY_UP /* H */:
                        //cout << endl << "Up" << endl;//key up
                        if (pos != 0)
                            pos--;
                        break;
                    case KEY_DOWN /* K */:
                        //cout << endl << "Down" << endl;   // key down
                        if (pos < Config.size() - 1)
                            pos++;
                        break;

                    default:
                        break;
                    }
                }
                system("clear");
                if (c != 'a')
                    PrintVoci(pos);
            }
        } while (c != 'a');
        /*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

        /* switch (pos)
    {
    case 0:
      menuplay.Draw();
      break;
    case 2:

      menuoption.Draw();
      break;
      /*case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;
    case 0:
                    cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;

    default:
      break;*/
        if (pos)
            for (int i = 0; i < 5; i++)
            {
                Menu::Add(Config[pos][2 * i] - '0');
            }
    } while (pos);
#endif
}

void MenuOption::SelectOthers() const
{
}