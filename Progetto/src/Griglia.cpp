#include <iostream>
#include "Griglia.h"
using std::vector;
using std::cout;
using std::endl;

Griglia::Griglia(int d) : Water(false, -1, -1, -1)    // Inizializziamo l'acqua della griglia con valori dei DM che
{													  // ci permettano di individuare facili condizioni per gli if
	size = d;

	// Costruiamo la griglia come matrice di puntatori, inizialmente tutti nulli. Con il primo ciclo creiamo
	// un vector di Navi* temp costituito da un puntatore nullo e poi nel secondo ciclo facciamo il push
	// back di puntatori nulli su temp: la griglia è un vector di vector i cui elementi sono puntatori 
	// nulli

	for (int i = 0; i < size; i++)
	{
		vector<Navi *> temp;
		temp.push_back(NULL);           
		for (int j = 0; j < size; j++)
		{

			grid.push_back(temp); //aggiunge una riga
			grid[i].push_back(NULL);
			//cout<<". ";
		}
		//cout<<endl;
	}
}

int Griglia::GetSize() const
{
	return size;
}

void Griglia::DrawEnemy() const     // stampa griglia nemica
{
	// Stampe per layout
	cout << "La griglia avversaria" << endl;
	cout << "    ";
	for (int i = 0; i < size; i++)
		cout << i << " ";
	cout << endl
		 << "   ";
	for (int i = 0; i < size; i++)
		cout << "--";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		// stampiamo la griglia iterando su tutti i puntatori della griglia e stampando 
		// a video un certo carattere in relazione allo stato della casella nell'evoluzione
		// del gioco
		cout << i << " | ";
		for (int j = 0; j < size; j++)
		{ 
			// Controllo se il puntatore della casella [x][y] è inizializzato o no per distinguere 
			// l'acqua non colpita dall'acqua colpita e dalle navi, se è inizializzato richiamo il 
			// DrawEnemy di Nave, altrimenti stampo un carattere fisso
			if (grid[j][i])

				grid[j][i]->DrawEnemy(j, i);
			else
				cout << ". ";
		}
		cout << "| " << i << endl;
	}
	cout << "   ";
	for (int i = 0; i < size; i++)
		cout << "--";
	cout << endl;
	cout << "    ";
	for (int i = 0; i < size; i++)
		cout << i << " ";
	cout << endl
		 << endl;
}

void Griglia::DrawAlly() const     // stampa griglia alleata
{
	cout << "La tua Griglia" << endl;
	cout << "    ";
	for (int i = 0; i < size; i++)
		cout << i << " ";
	cout << endl
		 << "   ";
	for (int i = 0; i < size; i++)
		cout << "--";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << " | ";
		// stampiamo la griglia iterando su tutti i puntatori della griglia e stampando 
		// a video un certo carattere in relazione allo stato della casella nell'evoluzione
		// del gioco
		for (int j = 0; j < size; j++)
		{
			// Controllo se il puntatore della casella [x][y] è inizializzato o no per distinguere 
			// l'acqua non colpita dall'acqua colpita e dalle navi, se è inizializzato richiamo il 
			// DrawAlly di Nave, altrimenti stampo un carattere fisso
			if (grid[j][i])  

				grid[j][i]->DrawAlly(j, i);
			else
				cout << ". ";
		}
		cout << "| " << i << endl;
	}
	cout << "   ";
	for (int i = 0; i < size; i++)
		cout << "--";
	cout << endl;
	cout << "    ";
	for (int i = 0; i < size; i++)
		cout << i << " ";
	cout << endl
		 << endl;
}

void Griglia::SetGriglia(int i, int j, Navi *nave)
{
	this->grid[i][j] = nave;
}

void Griglia::Strike(int x, int y)   // ci dice se, scegliendo di colpire [x][y] che abbiamo già controllato non  
{									 // essere già stat scelta, abbiamo colpito una nave oppure no
	//system(CLEAR);
	if (!grid[x][y])  // entro nell'if se la casella è associata ad acqua non colpita e faccio 
	{				  // da ora in poi puntare il puntatore non inizializzato di [x][y] a Water
		grid[x][y] = &Water;					
		cout << "\nNon hai colpito" << endl;
	}
	else   // L'else copre le caselle occupate da navi e chiama Strike
	{
		grid[x][y]->Strike(x, y);
		cout << "\nHai colpito una nave " << endl;
	}
}

vector<Navi *> Griglia::operator[](int i)
{
	return this->grid[i];
}

bool Griglia::IsHit(int x, int y) const
{
	if (grid[x][y] && (grid[x][y]->GetX()) != -1)  // guardo se il puntatore è inizializzato e se l'oggetto cui punta
	{											   // ha coordinata x diversa da 0 per escludere l'acqua colpita e 
		if (grid[x][y]->IsHit(x, y))			   // non colpita, poi chiamo IsHit che restituisce True se la casella
			return true;						   // in argomento è stata colpita, altrimenti false
	}
	return false;
}