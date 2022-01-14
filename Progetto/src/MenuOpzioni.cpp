#include "MenuOpzioni.h"
void MenuOpzioni::DrawVoci() const                              //Stampa il nome dell'opzione quando richiesto dai menù sopra
{
    cout << Nome;
}

MenuOpzioni::MenuOpzioni(int numero, string nome, string filename)                  //copio opzioni dal file di testo
{
    NumeroOpzione = numero;
    Nome = nome;
    Filename = filename;
    string valore;
    ifstream file(string("../src/") + Filename.c_str());                            //quando esegue main.exe devo tornare indietro di una cartella e aprire poi src
    if (file.is_open())
    {
        while (getline(file, valore))
        {
            Lista.push_back(valore);
        }

        file.close();
    }
    else
    {
        file.open(string("src/") + Filename.c_str());
        if (file.is_open())
        {

            while (getline(file, valore))
                Lista.push_back(valore);

            file.close();
        }
        else
        cout<<"Unable to open "<<Filename;
    }
    if (numero == 2)
        Lista.push_back("Aggiungi configurazione");
}

void MenuOpzioni::Draw() const                  //Gestisce tutto il menu: stampa, muoversi lungo le opzioni e gestire le scelte dell'utente
{
    unsigned int pos = 0;
    cout << "Selezionare la configurazione usando le frecce" << endl;

    do
    {
        system(CLEAR);
        PrintVoci(pos,Lista);
        pos = Arrows(&pos, Lista);

        if (pos)
            SetOption(NumeroOpzione, pos);
    } while (pos);
}

void MenuOpzioni::SetOption(int numero, unsigned int scelta) const          //SetOption modifica Setup(statico)
{
    switch (numero)                                                         //A seconda di quale sia in numero fornito come parametro, si comporta in modo diverso
    {
    case (0):                                                               //cambia il colore
    {
        Menu::Set(numero, scelta + 8);
    }
    break;

    case (1):                                                               //cambia dimensione della griglia
        Menu::Set(numero, stoi(Lista[scelta]));
        break;

    case (2):                                                               //cambia il numero di navi   
        if (scelta == Lista.size() - 1)
            AddConfig();
        for (int i = 0; i < 5; i++)
        {
            Menu::Set(i + 2, Lista[scelta][2 * i] - '0');
        }
        break;

    default:
        break;
    }
}



void MenuOpzioni::AddConfig() const                                     //aggiunge un'opzione (ad esempio una certa flotta)
{
    char n2, n3, n4, n5, n6;
    char newline[10] = {n2, ' ', n3, ' ', n4, ' ', n5, ' ', n6};
    for (int i = 0; i < 5; i++)
    {
        cout << "Inserire il numero di navi da " << i + 2 << endl;
        cin >> newline[i * 2];
        for (int j = 0; j < i + 1; j++)
        {
            cout << newline[j * 2] << " ";
        }
    }
    Lista.insert(Lista.end() - 1, newline);

    ofstream outfile("src/Setup.txt", std::ios_base::app); // Dalla stringa restituita da GetFileName otteniamo il vettore di const char relativo
    if (outfile.is_open())
    {
        outfile << '\n';
        for (int i = 0; i < 9; i++)
        {
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
            outfile << '\n';
            for (int i = 0; i < 9; i++)
            {
                outfile << newline[i];
            }
            outfile.close();
        }
        else
            cout << "Unable to modify file" << endl;
    }

    for (int j = 0; j < 5; j++)
    { //mettere questo se si vuole impostare subito la flotta
        Menu::Set(j + 2, newline[2 * j] - '0');
    }
}
