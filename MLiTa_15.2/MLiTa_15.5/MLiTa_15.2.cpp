/*
15.2. Игра в умножение (6)
Двое играют в умножение: умножают целое число P на одно из чисел от 2 до 5. Первый игрок
всегда начинает с P=1, делает умножение, затем число умножает второй игрок, снова первый и т.
д. Перед началом игры им задают число N, и победителем считается тот, кто первым добьется
условия P ≥ N. Определить, кто выиграет при заданном N, если оба играют наилучшим образом.
Ограничения: 2 <= N <= 10000, время 1 с.
Ввод из файла INPUT.TXT. В первой строке находится количество партий M. В следующих M
строках задаются значения N для каждой партии.
Вывод в файл OUTPUT.TXT. Выводится М строк с числами 1 – если победит первый игрок,
или 2 - если победит второй.
Пример
Ввод
1
17
Вывод
1
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> ReadFromFile(string const &fileName)
{
	ifstream file(fileName);
	if (!file)
	{
		throw logic_error("input file not found");
	}
	int numberParties;
	file >> numberParties;
	vector<int> limits;
	for (size_t i = 0; i != numberParties; ++i)
	{
		int score;
		file >> score;
		if (score < 2 || score > 10000)
		{
			throw out_of_range("2 <= N <= 10000");
		}
		limits.push_back(score);
	}
	return limits;
}

bool RoundIsOver(int &currentNumber, int limit)
{
	if ((currentNumber * 5) >= limit)
	{
		currentNumber *= 5;
	}
	else if ((currentNumber * 25) >= limit)
	{
		currentNumber *= 2;
	}
	else
	{
		currentNumber *= 5;
	}
	return currentNumber >= limit ? true : false;
}

vector<int> Game(vector<int> const &roundsList)
{
	vector<int> listWinner;
	for (size_t i = 0; i != roundsList.size(); ++i)
	{
		int currentNumber = 1;
		int player = 1;
		while (!RoundIsOver(currentNumber, roundsList[i]))
		{
			player = player == 2 ? 1 : 2;
		}
		listWinner.push_back(player);
	}
	return listWinner;
}

void OutputToFile(string const &fileName, vector<int> const &listWinner)
{
	ofstream file(fileName);
	for (auto element : listWinner)
	{
		file << element << '\n';
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "ERROR! Usage program.exe <input file>.txt <output file>.txt\n";
		return EXIT_FAILURE;
	}
	try
	{
		OutputToFile(argv[2], Game(ReadFromFile(argv[1])));
		return EXIT_SUCCESS;
	}
	catch (...)
	{
		cerr << "ERROR!" << endl;
		return EXIT_FAILURE;
	}
}