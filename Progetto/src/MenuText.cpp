#include "MenuText.h"
using std::string;

void MenuText::DrawVoci() const
{
    vector<string>::const_iterator i;
    for (i = Voci.begin(); i != Voci.end(); i++)
        cout << (*i);
}

MenuText::MenuText(string x)
{
    string name; // sizeof(x)
    for (int z = 0; z < x.size(); z++) {
        name.push_back(x[z]);
    }

    Voci.push_back(name);

    // string valore;
    // GetFileName(x).c_str()

    // string Filename = "src/Instructions.txt";
    // ifstream file(Filename.c_str());

    cout << "Stampo file Ins" << endl;

    ifstream fin("src/Ins.txt");
    if (!fin)
    cout << "Errore nell’apertura del file" << endl;
    else {
        string str1, str2;
        fin >> str1;
        fin >> str2;
    }
    fin.close(); 

    cout << "File aperto" << endl;

    string valore;
    string Filename = "src/Ins.txt";
    ifstream file(Filename.c_str());
    if (file.is_open())
    {
        while (getline(file, valore)){
        cout << "Copio file Ins1 su istruzioni" << endl;
            Description.push_back(valore);
        }

        file.close();
    }
    else
    {
        string Filename1 = "Ins.txt";
        file.open(Filename1.c_str());
        if (file.is_open())
        {
            cout << "Copio file Ins2 su istruzioni" << endl;
            while (getline(file, valore))
                Description.push_back(valore);

            file.close();
        }
        else
            cout << "Unable to open file Ins" << endl;
    }

    // Prova 1
    /*
    ifstream file("src/Instructions.txt");
    string line;
    while (getline(file, line))
    {
        cout << "Caricamento1" << endl;
        Description.push_back(line);
    }
    ifstream file1("Instructions.txt");
    string line1;
    while (getline(file1, line1))
    {
        cout << "Caricamento2" << endl;
        Description.push_back(line1);
    }*/

    // Prova 2
    /*if (file.is_open())
    {
        while (getline(file, valore)){
        cout << "Copio file istruzioni1" << endl;
            Description.push_back(valore);
        }

        file.close();
    }
    else
    {
        // string Filename1 = "Instructions.txt";
        // file.open(Filename1.c_str());
        file.open("Instructions.txt");
        if (file.is_open())
        {
            cout << "Copio file istruzioni2" << endl;
            while (getline(file, valore))
                Description.push_back(valore);

            file.close();
        }
        else
            cout << "Unable to open file istruzioni1" << endl;
    }*/
    cout << "Fine costruttore MenuText" << endl;
}

string MenuText::GetFileName(string x) const{

    string filename;
    string location = "src/";
    string extension = ".txt";

    for (int z = 0; z < location.length(); z++) {
        filename.push_back(location.at(z));
    }

    for (int i = 0; i < x.size(); i++) {
        filename.push_back(x[i]);
    }

    for (int j = 0; j < extension.length(); j++) {
        filename.push_back(extension.at(j));
    }

    // char pippo[filename.size() + 1]; 
 
    // strcpy(pippo, filename.c_str()); 

    // const char * Filename[filename.size()+1] = filename.c_str();

    // const char Filename = "nomedelfile";

    // cout << "Name of file: " << *Filename << endl;

    return filename;

}

void MenuText::Draw() const
{
    cout << "Ciao1" << endl;
    SelectWindows();
}

void MenuText::PrintVoci(unsigned int pos) const
{
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << Description[0] << endl;
    for (unsigned int d = 1; d < Description.size(); d++){
        cout << Description[d];
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

void MenuText::SelectWindows() const
{
#ifdef _WIN32
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

    int c, ex;
    unsigned int pos=0;

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
                    if (pos < Description.size() - 1)
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
                Menu::Add(Description[pos][2 * i] - '0');
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

void MenuText::SelectOthers() const
{
}