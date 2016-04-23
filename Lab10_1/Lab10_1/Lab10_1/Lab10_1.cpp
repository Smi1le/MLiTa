/*10.1.Последовательность 1 (6)

В последовательности чисел a1, a2, a3, ... задан первый член, а остальные вычисляются по

формуле ai  = (ai  - 1)2 mod M.Найти N - й член последовательности.

Ограничения: 1 ≤ M ≤ 10000, 2 ≤ N ≤ 2×10^9, 0 ≤ a1 ≤ M, время 1 с.

	Ввод из файла INPUT.TXT.В первой строке находятся числа M, N и a1, разделённые пробелом.

	Вывод в файл OUTPUT.TXT.Вывести одно число - aN.

	Примеры

	Ввод 1      Ввод 2

	10000 3 4   7777 2000000000 0

	Вывод 1     Вывод 2

	256         0
	*/
#include "stdafx.h"
#include "Sequence.h"
#include <memory>

using namespace std;

void CheckingValidatyData(int divider, int firstElementSequence, int itemNumberToSearch)
{
	if (divider <= 0 || divider > 10000 ||
		firstElementSequence < 0 || firstElementSequence > divider ||
		itemNumberToSearch < 2 || itemNumberToSearch > 2 * pow(10, 9))
	{
		throw(invalid_argument("Incorrect Data"));
	}
}

shared_ptr<CSequence> ReadDataFromFile(string const &fileName)
{
	ifstream inputFile(fileName);
	if (!inputFile)
	{
		throw(std::logic_error("Input file not found"));
	}
	try
	{
		int divider;
		int itemNumberToSearch;
		int firstElementSequence;
		inputFile >> divider;
		inputFile >> itemNumberToSearch;
		inputFile >> firstElementSequence;
		CheckingValidatyData(divider, firstElementSequence, itemNumberToSearch);
		return make_shared<CSequence>(divider, itemNumberToSearch, firstElementSequence);
	}
	catch (...)
	{
		throw;
	}
}

void OutputInFile(string const &fileName, int number)
{
	ofstream outputFile(fileName);
	outputFile << number;
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
		shared_ptr<CSequence> sequence;
		sequence = ReadDataFromFile(argv[1]);
		OutputInFile(argv[2], sequence->GetRightSequenceElement());
	}
	catch (logic_error const &e)
	{
		cerr << "Error!" << e.what() << endl;
		return TypeError::ERROR;
	}
    return TypeError::ALL_IS_SUCCESS;
}