// Domino.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Domino.h"

using namespace std;

vector<Node> ReadFromFile(string const &fileName)
{
	vector<Node> setDominoes;
	ifstream file(fileName);
	if (!file)
	{
		throw logic_error("input file is missing.");
	}
	int number;
	file >> number;
	if (number > 20)
	{
		throw logic_error("out of range (2 <= N <= 20).");
	}
	for (size_t i = 0; i != number; ++i)
	{
		Node node;
		if (!(file >> node.first) || !(file >> node.second))
		{
			throw logic_error("incorrectly set the pair of dominoes bones.");
		}
		if (node.first > 6 || node.second > 6)
		{
			throw logic_error("out of range (0 <= X, Y <= 6).");
		}
		setDominoes.push_back(node);
	}
	return setDominoes;
}

void Output(CDominoHelper const &helper, string const &fileName)
{
	ofstream file(fileName);
	for (auto el : helper.GetBestPath())
	{
		file << el.first << el.second;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Error! Usage <program.exe><input file *.txt><output file *.txt>\n";
		return EXIT_FAILURE;
	}
	try
	{
		CDominoHelper helper(ReadFromFile(argv[1]));
		vector<Node> paths;
		paths.push_back(helper.SearchFirstMaxDomino());
		helper.BuildingPaths(paths);
		Output(helper, argv[2]);
		return EXIT_SUCCESS;
	}
	catch (logic_error const &e)
	{
		cout << "Error! " << e.what() << endl;
		return EXIT_FAILURE;
	}
   
}

