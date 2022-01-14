#include "MenuText.h"
using std::string;

void MenuText::DrawVoci() const
{
        cout << Voci;
}

MenuText::MenuText(string x)
{
    /*string name;
    for (int z = 0; z < x.size(); z++) {
        name.push_back(x[z]);
    }*/

    Voci=x;
    Description.push_back(x);

    string valore;
    // string Filename = "src/Ins.txt";

    ifstream file(string("src/") + x + string(".txt")); // Dalla stringa restituita da GetFileName otteniamo il vettore di const char relativo
    if (file.is_open())
    {
        while (getline(file, valore))
        {
            cout << "Copio file Ins1 su istruzioni" << endl;
            Description.push_back(valore);
        }

        file.close();
    }
    else
    {
        file.open(GetFileName(x).c_str());
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
    cout << "Fine costruttore MenuText" << endl;

}

string MenuText::GetFileName(string &x) const
{

    string filename;
    string location = "../src/";
    string extension = ".txt";

    for (int j = 0; j < extension.length(); j++)
    {
        x.push_back(extension.at(j));
    }

    for (int z = 0; z < location.length(); z++)
    {
        filename.push_back(location.at(z));
    }

    for (int i = 0; i < x.size(); i++)
    {
        filename.push_back(x[i]);
    }
    return filename;
}

void MenuText::Draw() const
{
    unsigned int pos = 0;
    char c;
    cout << "Selezionare la configurazione usando le frecce" << endl;
    do
    {
        system(CLEAR);
        PrintVoci(Description.size()-1,Description);
        #ifdef _WIN32
            c = getch();
    } while (c!=13);
    #else
    struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
    
    cin>>c;
    }while(c!='a');
  #endif  

}
