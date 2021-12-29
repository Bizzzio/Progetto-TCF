#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	std::cout << "Ciao! sono arianna" << std::endl;
	vector<vector<int> > griglia;
	for (int i = 0; i < 10; i++)
	{
		vector<int> temp;
		temp.push_back(0);
		for (int j = 0; j < 10; j++)
		{

			griglia.push_back(temp); //aggiunge una riga
			griglia[i].push_back(0);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << griglia[i][j];
		}
		cout << endl;
	}
}