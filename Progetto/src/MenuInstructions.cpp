#include "MenuInstructions.h"
#include <fstream>
using std::ifstream;

void MenuInstructions::DrawVoci() const
{
    cout << "Ciao" << endl;
    vector<string>::const_iterator i;
    for (i = Voci.begin(); i != Voci.end(); i++)
        cout << (*i);
}

MenuInstructions::MenuInstructions(string x){

    
    string name; // sizeof(x)
    for (int z = 0; z < x.size(); z++) {
        name.push_back(x[z]);
    }

    Voci.push_back(name);

    /*string filename;
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

    char pippo[filename.size() + 1]; 
 
    strcpy(pippo, filename.c_str()); 

    const char Filename[filename.size()+1] = pippo;

    cout << "Name of file: " << Filename << endl;*/
    
    /*string filename;
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

    cout << "Name of file: " << filename << endl;

    const char* c = filename.c_str();*/

    string valore;
    ifstream file("src/Instructions.txt");
    // ifstream file(c);
    if (file.is_open())
    {
        while (getline(file, valore)){
            cout << "Copio file istruzioni" << endl;
            Description.push_back(valore);

        }
        file.close();
    }
    else
    {
        /*string filename1;
        for (int y = location.length() - 1; y < extension.length(); y++) {
            filename1.push_back(filename.at(y));
        }

        const char* c1 = filename1.c_str();*/

        file.open("Instructions.txt");
        if (file.is_open())
        {
            while (getline(file, valore))
                cout << "Copio file istruzioni" << endl;
                Description.push_back(valore);

            file.close();
        }
        else
            cout << "Unable to open file";
    }
}




void MenuInstructions::PrintVoci(unsigned int pos) const
{
    for (unsigned int d = 0; d < Description.size(); d++)
    {   
        cout << Description[d] << endl;
    }
}

void MenuInstructions::Draw() const
{
    cout << "Stampo file" << endl;
    PrintVoci(0);
    /*vector<string>::const_iterator i;
    for (i = Description.begin(); i != Description.end(); i++)
        cout << (*i);*/
}