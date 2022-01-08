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
    string Filename = "src/Setup.txt";
    ifstream file(Filename.c_str());
    if (file.is_open())
    {
        while (getline(file, valore)){
        cout << "Copio file opzioni1" << endl;
            Config.push_back(valore);
        }

        file.close();
    }
    else
    {
        string Filename1 = "Setup.txt";
        file.open(Filename1.c_str());
        if (file.is_open())
        {
            cout << "Copio file opzioni2" << endl;
            while (getline(file, valore))
                Config.push_back(valore);

            file.close();
        }
        else
            cout << "Unable to open file opzioni1";
    }
    cout << "Fine costruttore MenuOption" << endl;
}

void MenuOption::AddConfig() const {
    char n2, n3, n4, n5, n6;
        char newline[10] = {n2, ' ', n3, ' ', n4, ' ', n5, ' ', n6};
        for (int i = 0; i < 5; i++) {
            cout << "Inserire il numero di navi da " << i + 2 << endl;
            cin >> newline[i*2];
            for (int j = 0; j < i; j++) {
                cout << newline[j*2] << " ";
            }
        }

        ofstream outfile("src/Setup.txt", std::ios_base::app); // Dalla stringa restituita da GetFileName otteniamo il vettore di const char relativo
        if (outfile.is_open())
        {
            cout << "Scrivo nel file 1" << endl;
            outfile << endl;
            for (int i = 0; i < 10; i++) {
                outfile << newline[i];
            }

            outfile.close();
        }
        else
        {
            cout << "Scrivo nel file 2";
            outfile.open("Setup.txt");
            if (outfile.is_open())
            {
                for (int i = 0; i < 10; i++) {
                    outfile << newline[i];
            }

                outfile.close();
            }
            else
                cout << "Unable to modify file" << endl;
        }
    
    for(int j=0;j<10;j++){
        Menu::Add(newline[2 * j] - '0');
    }
}

void MenuOption::Draw() const 
{
    SelectWindows();
}

    void MenuOption::PrintVoci(unsigned int pos) const
    {
    #ifdef _WIN32
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Selezionare la configurazione usando le frecce" << endl;
        for (unsigned int d = 0; d < Config.size(); d++)
        {
            if (d == pos)
            {
                SetConsoleTextAttribute(h, 10);
                cout << "--> " << Config[d];

                SetConsoleTextAttribute(h, 15);
                cout << endl;
            }
            else
                cout << Config[d];
            cout << endl;
    }
#else
    cout << "Selezionare la configurazione usando le frecce" << endl;
    for (unsigned int d = 0; d < Config.size(); d++)
    {
        if (d == pos)
        {
            cout << "\033[32m"
                 << "--> " << Config[d];

            cout << "\033[0m" << endl;
        }
        else
            cout << Config[d];
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
    
    unsigned int pos=0;
    int size;
    cout << " Inserire la grandezza della griglia: ";
    cin >> size;

    Menu::Add(size);

    bool a;
    cout << " Selezionare la composizione della flotta: premere \n";
    cout << " 0 per accedere alle flotte di default oppure 1 per \n";
    cout << " sceglierne una personalizzata: ";
    cin >> a;
    
    if(a){
        AddConfig();
    }
    else{
    do{
    
        
        // system("cls");
        PrintVoci(pos);

        pos=Arrows(&pos,Config);
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
    }

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
    system(CLEAR);
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
                system(CLEAR);
                if (c != 'a')
                    PrintVoci(pos);
            }
        } while (c != 'a');
        system(CLEAR);
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
      case 0:
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