/*
13.26 Скобки и Python (8)

Напишите программу, првоеряющую правильную скобочную последовательность во входном
файле, написанном на языке Python 3. В случае правильной последовательности программа
выводит одну строку «Yes». Если же в скобочной последовательности есть ошибки, программа
выводит на первой строке «No», а на второй строке – номер строки и номер колонки в файле, где
встретилась ошибка (нумерация строк и колонок начинается с единицы). Правильной скобочной
последовательностью называется такая последовательность скобок, в которой у каждой
открывающей скобки есть соответствующая закрывающая скобки.
Требования:
 Программа должна обрабатывать круглые, квадратные и фигурные скобки
 Программа должна обрабатывать код с комментариями и строковыми
литералами, включая многострочные строковые литералы
 Программа может не обрабатывать правила неявного склеивания строк (implicit
line joining).
Лексическая структура Python 3: docs.python.org/3/reference/lexical_analysis.html
Примеры ввода-вывода:
Ввод 1
#!/usr/bin/env python3
print([1+12*(2 + 1 / 3), 201, 0])

Вывод 1
Yes

Ввод 2
#!/usr/bin/env python3
print([1+12*(2 + 1 / 3}, 201, 0])
Вывод 2
No
2 23

*/


#include "stdafx.h"
#include "TextProcessor.h"

using namespace std;

vector<string> LoadFromFile(string const &fileName)
{
	ifstream file(fileName);
	string bufStr;
	vector<string> text;
	if (!file)
	{
		throw(std::logic_error("Input file not found"));
	}
	while (getline(file, bufStr))
	{
		text.push_back(bufStr);
	}
	return text;
}

void OutputToFile(std::pair<int, int> const &result, string const &fileName)
{
	ofstream file(fileName);
	if (result.first == -1 && result.second == -1)
	{
		file << "YES";
	}
	else
	{
		file << "NO" << '\n';
		file << result.first << " " << result.second;
	}
}


int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cerr << "Error! Usage <string.exe> <input txt file> <output txt file>\n";
		return TypeError::INCORRECTLY_CALLED_COMMAND;
	}
	try
	{
		CTextProcessor text(LoadFromFile(argv[1]));
		OutputToFile(text.GetTestResult(), argv[2]);
		return TypeError::ALL_IS_SUCCESS;
	}
	catch (...)
	{
		cerr << "Error!" << endl;
		return TypeError::ERROR;
	}
}

