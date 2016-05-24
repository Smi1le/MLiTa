/*
	4.1. Прогрессия (6)
Король Камбузии с детства боится несчастливых арифметических прогрессий с разностью 13. 
Однажды ему представили список расходов на нужды подданных, состоящий из N чисел. Король 
потребовал оставить только такую начальную часть  списка, в которой не скрывается 
несчастливая арифметическая прогрессия. Либеральная общественность, считаясь с мнением 
короля, настаивает, тем не менее, на сохранении как можно большей части списка. Найти  
максимальное значение K такое, что из первых K чисел списка невозможно выделить M чисел, 
следующих в порядке их нахождения в списке и образующих последовательные члены 
несчастливой арифметической прогрессии. Выдать члены первой обнаруженной несчастливой 
прогрессии. 
Ввод из файла INPUT.TXT. Первая строка содержит два целых положительных числа N и M, 
разделенных пробелом: N – количество чисел в списке, а  M – недопустимое число членов 
прогрессии. Вторая строка содержит список расходов в виде целых положительных чисел. 
Ограничения: 2 ≤ N,M ≤ 5000, 1 ≤ Xi ≤ 65000, время 2 с.
Вывод в файл OUTPUT.TXT. В первой строке выводится единственное число K- 
максимальное количество начальных чисел списка, не содержащих в качестве подсписка M 
последовательных членов  несчастливой арифметической прогрессии. Во второй строке 
выводятся через пробел члены первой обнаруженной несчастливой прогрессии. Если ее не 
обнаружено, вывести No.
Пример 
Ввод
9 3
5 9 3 22 16 19 35 7 29
Вывод
9 22 35
Пояснение: из первых 7 чисел выделяются 3 члена несчастливой прогрессии 9, 22, 35, а из 
первых 6 чисел можно выделить только 2 таких члена: 9, 22 либо 3, 16.
	
*/

#include "stdafx.h"
#include "Data.h"

using namespace std;


CData ReadFromFile(string const &nameFile)
{
	ifstream file(nameFile);
	if (!file)
	{
		throw logic_error("Incorrect input file");
	}
	int number;
	int limit;
	if (!(file >> number) || !(file >> limit) || !(2 <= number && number <= 5000)
		|| !(2 <= limit && limit <= 5000))
	{
		throw logic_error("Incorrect restrictions.");
	}
	vector<int> sequence;
	sequence.resize(number);
	for (size_t i = 0; i != number; ++i)
	{
		
		if (!(file >> sequence[i]) || !(1 <= sequence[i] && sequence[i] <= 65000))
		{
			throw logic_error("Error! Incorrect restrictions11.");
		}
	}
	return CData(sequence, limit);
}

void OutputInFile(string const &fileName, pair<int, vector<int>> const &res)
{
	ofstream file(fileName);
	if (res.first == -1)
	{
		file << "No";
	}
	else
	{
		file << res.first << '\n';
		for (auto element : res.second)
		{
			file << element << ' ';
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Error! Usage <program.exe> <input file *.txt> <output file *.txt>\n";
		return EXIT_FAILURE;
	}
	try
	{
		CData data = ReadFromFile(argv[1]);
		data.CalculationPossibleSequences();
		OutputInFile(argv[2], data.GetResultsSearch());
		return EXIT_SUCCESS;
	}
	catch (logic_error const &e)
	{
		cout << "Error!" << e.what() << endl;
		return EXIT_FAILURE;
	}
}

