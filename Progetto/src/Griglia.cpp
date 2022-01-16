#include <iostream>
#include "Griglia.h"
using std::vector;
using std::cout;
using std::endl;

Griglia::Griglia(int d) : Water(false, -1, -1, -1)
{
	size = d;

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

void Griglia::DrawEnemy() const
{
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
		cout << i << " | ";
		for (int j = 0; j < size; j++)
		{
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

void Griglia::DrawAlly() const
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
		for (int j = 0; j < size; j++)
		{
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
//TODO: aggiungere messaggi di errore
/*bool Griglia::CheckCell(bool t, int x, int y, int length) const
{
	if (t)
	{
		if (x + length - size <= 0)
		{

			for (int i = 0; i < length; i++)
			{
				if (grid[x + i][y])
					return false;
			}
			if (y < size)
				return true;
		}
		return false;
	}

	else
	{
		if (y + length - size <= 0)
		{
			for (int i = 0; i < length; i++)
			{
				if (grid[x][y + i])
					return false;
			}
			if (x < size)
				return true;
		}
		return false;
	}
	return false;
}*/

void Griglia::SetGriglia(int i, int j, Navi *nave)
{
	this->grid[i][j] = nave;
}

void Griglia::Strike(int x, int y)
{
	//system(CLEAR);
	if (!grid[x][y])
	{
		grid[x][y] = &Water;
		cout << "\nNon hai colpito" << endl;
	}
	else
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
	if (grid[x][y] && (grid[x][y]->GetX()) != -1)
	{
		if (grid[x][y]->IsHit(x, y))
			return true;
	}
	return false;
}