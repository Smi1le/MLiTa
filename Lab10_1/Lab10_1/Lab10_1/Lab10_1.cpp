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
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CSequence
{
public:
	void ReadDataFromFile(std::string const &fileName);
	void OutputInformationInConsole() const;
	int GetRightSequenceElement();
private:
	void FillingVectorNumbers();
	void CheckingValidatyData() const;
	bool NumberIncludedInVector(int numberForVerification) const;
	std::vector<int> m_numbers;
	size_t m_divider;
	size_t m_itemNumberToSearch;
	int m_firstElementSequence;
};

bool CSequence::NumberIncludedInVector(int numberForVerification) const
{
	for (auto element : m_numbers)
	{
		if (numberForVerification == element)
		{
			return true;
		}
	}
	return false;
}

void CSequence::FillingVectorNumbers()
{
	size_t squareNumber = static_cast<size_t>(pow(m_firstElementSequence, 2));
	int previousValue = squareNumber % m_divider;
	for (size_t i = 3; i <= INT_MAX - 1; ++i)
	{
		squareNumber = static_cast<size_t>(pow(previousValue, 2));
		previousValue = squareNumber % m_divider;
		if (!NumberIncludedInVector(previousValue))
		{
			m_numbers.push_back(previousValue);
		}
		else
		{
			i = INT_MAX;
		}
	}
}

int CSequence::GetRightSequenceElement()
{
	if (m_firstElementSequence > 1 || m_firstElementSequence < -1)
	{
		int previousValue = m_firstElementSequence;
		FillingVectorNumbers();
		size_t passesNumber = m_itemNumberToSearch / (m_numbers.size());
		if (passesNumber == 0)
		{
			//Так как элементы вектора считаются с 0 позиции то -1 ,а так как первые два элемента не считаются то -2
			return m_numbers[m_itemNumberToSearch - 3];
		}
		else
		{
			int positionDesiredItem = m_itemNumberToSearch - (2 + (passesNumber * (m_numbers.size())));
			if (positionDesiredItem == 0)
			{
				return m_numbers[m_numbers.size() - 1];
			}
			else if (positionDesiredItem < 0)
			{
				positionDesiredItem = m_itemNumberToSearch - (2 + ((passesNumber - 1) * (m_numbers.size())));
				return m_numbers[positionDesiredItem - 1];
			}
			else
			{
				return m_numbers[positionDesiredItem - 1];
			}
		}
	}
	else
	{
		if (m_firstElementSequence == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void CSequence::OutputInformationInConsole() const
{
	cout << "m_numbers.size() = " << m_numbers.size() << endl;
	cout << "m_divider = " << m_divider << endl;
	cout << "m_itemNumberToSearch = " << m_itemNumberToSearch << endl;
	cout << "m_firstElementSequence = " << m_firstElementSequence << endl;
}

void CSequence::ReadDataFromFile(string const &fileName)
{
	ifstream inputFile(fileName);
	if (!inputFile)
	{
		throw(std::logic_error("Input file not found"));
	}
	inputFile >> m_divider;
	inputFile >> m_itemNumberToSearch;
	inputFile >> m_firstElementSequence;
}

void OutputInFile(string const &fileName, int number)
{
	ofstream outputFile(fileName);
	outputFile << number;
}

enum TypeError {
	ALL_IS_SUCCESS ,
	ERROR ,
	INCORRECTLY_CALLED_COMMAND
};

void CSequence::CheckingValidatyData() const
{
	if ((m_divider <= 0 || m_divider > 10000) ||
		(m_firstElementSequence < 0 || m_firstElementSequence > m_divider) ||
		(m_itemNumberToSearch < 2 || m_itemNumberToSearch > 2 * pow(10, 9)))
	{
		throw(invalid_argument("Incorrect Data"));
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
		CSequence sequence;
		sequence.ReadDataFromFile(argv[1]);
		OutputInFile(argv[2], sequence.GetRightSequenceElement());
	}
	catch (logic_error const &e)
	{
		cerr << "Error!" << e.what() << endl;
		return TypeError::ERROR;
	}
    return TypeError::ALL_IS_SUCCESS;
}