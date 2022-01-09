#include "MenuOpzioni.h"
void MenuOpzioni::DrawVoci() const
{
    cout<<Nome;
}

MenuOpzioni::MenuOpzioni(int numero,string nome, string filename)
{
    NumeroOpzione=numero;
    Nome=nome;
    Filename=filename;
    string valore;
    ifstream file(string("../src/")+Filename.c_str());
    cout<<string("../src/")+Filename.c_str();
    if (file.is_open())
    {
        while (getline(file, valore)){
            Lista.push_back(valore);
        }

        file.close();
    }
    else
    {
        file.open(string("src/")+Filename.c_str());
        if (file.is_open())
        {
            cout << "Copio file opzioni2" << endl;
            while (getline(file, valore))
                Lista.push_back(valore);

            file.close();
        }
        else
            cout << "Unable to open file opzioni1";
    }
    if(numero==2)
        Lista.push_back("Aggiungi configurazione");
    cout << "Fine costruttore MenuOpzioni" << endl;
}

void MenuOpzioni::Draw() const
{
  unsigned int pos=0;
  cout << "Selezionare la configurazione usando le frecce" << endl;

  
  do
  {
    system("cls");
    PrintVoci(pos);
    pos = Arrows(&pos, Lista);

    if (pos)
        SetOption(NumeroOpzione,pos);
    } while (pos);
}

void MenuOpzioni::SetOption(int numero,unsigned int scelta) const
{
    switch (numero)
    {
    case (0):
        {
            Menu::Set(numero,scelta+8);
        }
        break;


    case (1):
        Menu::Set(numero,stoi(Lista[scelta]));
        break;

    case (2):
        if (scelta==Lista.size()-1)
            AddConfig();
        for (int i = 0; i < 5; i++)
            {
                Menu::Set(i+2,Lista[scelta][2 * i] - '0');
            }
        break;

    default:
        break;
    }
}

void MenuOpzioni::PrintVoci(unsigned int pos) const
{
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Selezionare la configurazione usando le frecce" << endl;
    for (unsigned int d = 0; d < Lista.size(); d++)
    {
        if (d == pos)
        {
            SetConsoleTextAttribute(h, Menu::GetSetup()[0]);
            cout << "--> " << Lista[d];

            SetConsoleTextAttribute(h, 15);
            cout << endl;
        }
        else
            cout << Lista[d];
        cout << endl;
    }
#else
    cout << "Selezionare la Listaurazione usando le frecce" << endl;
    for (unsigned int d = 0; d < Lista.size(); d++)
    {
        if (d == pos)
        {
            cout << "\033[32m"
                 << "--> " << Lista[d];

            cout << "\033[0m" << endl;
        }
        else
            cout << Lista[d];
        cout << endl;
    }
#endif
}

void MenuOpzioni::AddConfig() const {
    char n2, n3, n4, n5, n6;
        char newline [10] = {n2, ' ', n3, ' ', n4, ' ', n5, ' ', n6};
        for (int i = 0; i < 5; i++) {
            cout << "Inserire il numero di navi da " << i + 2 << endl;
            cin >> newline[i*2];
            for (int j = 0; j < i+1; j++) {
                cout << newline[j*2] << " ";
            }
        }
        Lista.insert(Lista.end()-1,newline);

        ofstream outfile("src/Setup.txt", std::ios_base::app); // Dalla stringa restituita da GetFileName otteniamo il vettore di const char relativo
        if (outfile.is_open())
        {
            outfile<<'\n';
            for (int i = 0; i < 9; i++) {
                outfile << newline[i];
        }
            outfile.close();
        }
        else
        {
            cout << "Scrivo nel file 2";
            outfile.open("../src/Setup.txt", std::ios_base::app);
            if (outfile.is_open())
            {
                outfile<<'\n';
                for (int i = 0; i < 9; i++) {
                    outfile << newline[i];
            }
                outfile.close();
            }
            else
                cout << "Unable to modify file" << endl;
        }
    
    for(int j=0;j<5;j++){                                       //mettere questo se si vuole impostare subito la flotta
        Menu::Set(j+2,newline[2 * j] - '0');
    }
}

