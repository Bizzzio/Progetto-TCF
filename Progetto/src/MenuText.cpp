#include "MenuText.h"
using std::string;
using std::ifstream;
using std::ofstream;

void MenuText::DrawVoci() const                     //stampa il nome dei menu ai menù sopra
{
        cout << Voci;
}

MenuText::MenuText(string x)
{

    Voci=x;                                                 //inizializza Voci all'input ricevuto in input
    Description.push_back(x);                               //la prima riga da mostrare è il nome del menu
    string valore;

    ifstream file(string("src/") + x + string(".txt"));     //apre il file
    if (file.is_open())                                     
    {
        while (getline(file, valore))
            Description.push_back(valore);                  //copia le righe del file su description

        file.close();
    }
    else
    {
        file.open(GetFileName(x).c_str());                  //se il file non si era aperto, significa che lo abbiamo aperto dal main.exe in output, dobbiamo quindi cambiare cartella
        if (file.is_open())
        {
            while (getline(file, valore))
                Description.push_back(valore);

            file.close();
        }
        else
            cout << "Unable to open file " <<Voci<< endl;
    }

}

//Vedere se è da mettere
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

void MenuText::Draw() const                                                     //Stampa il menu
{
    unsigned int pos = 0;
    char c;
    cout << "Selezionare la configurazione usando le frecce" << endl;
    do                                                                          //Non è possibile usare Arrows perchè non ci si deve spostare tra le righe, si può solo premere invio
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
