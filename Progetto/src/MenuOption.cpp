#include "MenuOption.h"

MenuOption::MenuOption()
{

    string valore;
    ifstream file("src/Setup.txt");
    if (file.is_open())
    {
        while (getline(file, valore))
            voci.push_back(valore);

        file.close();
    }
    else
        cout << "Unable to open file";
}

void MenuOption::Draw() const
{
#ifdef _WIN32
    SelectWindows();
#elif
    SelectOthers();
#endif
}

void MenuOption::PrintVoci(int pos) const
{
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
            cout << voci[d] << endl;
    }
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
        system("cls");
        /*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

#endif

        if (pos)
            for (int i = 0; i < 5; i++)
            {
                Menu::Add(voci[pos][2 * i] - '0');
            }
    } while (pos);
}