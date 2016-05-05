// Grafs_MLiTa.cpp: определяет точку входа для консольного приложения.
//

/*
12.2. Королевские дороги (7)
В некотором королевстве N городов соединены N-1 дорогой. Имеется ровно один путь между
любой парой городов. Дороги иногда выходят из строя. Требуется построить минимальное
количество новых дорог так, чтобы каждая пара городов оказалась бы связана не менее чем двумя
путями.
Ввод. В первой строке N (2 ≤ N ≤ 100000). В следующих N-1 строках – дороги в виде пар номеров
городов Ai, Bi (1 ≤ Ai, Bi ≤ N).
Вывод. В первой строке минимальное число K новых дорог. В следующих K строках – пары
городов, задающих новые дороги.
Примеры
Ввод 1		Ввод 2
5			4
1 2			1 2
2 3			1 3
3 4			1 4
3 5
Вывод 1		Вывод 2
2			 2
1 4			3 2
4 5			1 4
*/

#include "stdafx.h"
#include "MapCountry.h"

using namespace std;

void CheckingValidatyData(int Ai, int Bi, int N)
{
	if (Ai < 1 || Bi > N)
	{
		throw(invalid_argument("Incorrect Data"));
	}
}

vector<int> LoadDataFromFile(string const &fileName)
{
	ifstream file(fileName);
	if (!file)
	{
		throw(std::logic_error("Input file not found"));
	}
	try
	{
		vector<int> numberRoads;
		size_t size;
		file >> size;
		if (size < 2 || size > pow(10, 5))
		{
			throw(invalid_argument("Incorrect Data"));
		}
		numberRoads.resize(size, 0);
		while (!file.eof())
		{
			int lCity = 0;
			int rCity = 0;
			file >> lCity;
			file >> rCity;
			CheckingValidatyData(lCity, rCity, size);
			++numberRoads[lCity - 1];
			++numberRoads[rCity - 1];
		}
		return numberRoads;
	}
	catch (...)
	{
		throw;
	}
}

void Filing(CMapCountry const &mapCountry, string const &fileName)
{
	ofstream file(fileName);
	auto listNewRoads = mapCountry.GetListNewRoads();
	file << listNewRoads.size() << "\n";
	for (auto element : listNewRoads)
	{
		file << element.first << " " << element.second << "\n";
	}
}



int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Error! Usage <Program.exe> <input file> <output file>\n";
		return TypeError::INCORRECTLY_CALLED_COMMAND;
	}
	try
	{
		CMapCountry mapCountry(LoadDataFromFile(argv[1]));
		mapCountry.ConstructionNewRoads();
		Filing(mapCountry, argv[2]);
		return TypeError::ALL_IS_SUCCESS;
	}
	catch (std::logic_error const &e)
	{
		cerr << "Error!" << e.what() << endl;
		return TypeError::ERROR;
	}
}

