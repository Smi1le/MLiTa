/*
3.8. Школа танцев (7)

В школу бальных танцев профессора Падеграса записались N  учеников — мальчиков и
девочек. Профессор построил их в один ряд, и хочет отобрать из них для первого занятия группу
стоящих подряд учеников, в которой количество мальчиков и девочек одинаково. Сколько
вариантов выбора есть у профессора? Решить задачу с помощью рекуррентных соотношений.
Ввод. В первой строке входного файла задано число N  (1 ≤ N ≤ 106). Во второй строке задается
описание построенного ряда из мальчиков и девочек — строка из N символов a и b (символ a
соответствует девочке, а символ b — мальчику).
Вывод. В единственной строке выходного файла должно содержаться количество вариантов
выбора требуемой группы.

Примеры
Ввод 1         Ввод 2
3              8
bab            abbababa
Вывод 1        Вывод 2
2              13

*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

struct Data
{
	unsigned numberPupils;
	std::string studentsInLine;
};

void ReadDataFromFile(std::string const &fileName, Data &data)
{
	std::ifstream inputFile(fileName);
	if (!inputFile)
	{
		throw(std::logic_error("File was not opened!"));
	}
	std::string tNumber;
	std::getline(inputFile, tNumber);
	data.numberPupils = static_cast<unsigned>(atoi(tNumber.c_str()));
	std::getline(inputFile, data.studentsInLine);
}

int CountingNumberGroups(Data const &pData, bool &personsEqually, int &difference)
{
	int numberBoys = 0;
	int numberGirls = 0;
	for (auto element : pData.studentsInLine)
	{
		if (toupper(element) == 'A')
		{
			++numberGirls;
		}
		if (toupper(element) == 'B')
		{
			++numberBoys;
		}
	}
	difference = abs(numberBoys - numberGirls);
	if (numberBoys == numberGirls)
	{
		personsEqually = true;
	}
	return numberBoys >= numberGirls ? numberGirls : numberBoys;
}

int CountingNumberGroupsOptions(Data const &pData)
{
	bool personsEqually = false;
	int difference;
	int numberPairs = CountingNumberGroups(pData, personsEqually, difference);
	int numberOptions = 0;
	for (size_t i = numberPairs; i != 0; --i)
	{
		/*if (i == numberPairs)
		{
			numberOptions += i;
		}*/
		if (i == numberPairs)
		{
			numberOptions += i + difference;
		}
		else if (i == 1)
		{
			numberOptions += 1 + difference;
		}
		else
		{
			numberOptions += i * (i - 1) + i * difference;
		}
	}
	return numberOptions;
}

void OutputInFile(std::string const &nameFile, int numberOptions)
{
	std::ofstream outputFile(nameFile);
	outputFile << numberOptions;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Error! Usage <dancingSchool.exe> <input file> <output file>\n";
		return EXIT_FAILURE;
	}
	try
	{
		std::string inputFileName = argv[1];
		std::string outputFileName = argv[2];
		Data pData;
		ReadDataFromFile(inputFileName, pData);
		OutputInFile(outputFileName, CountingNumberGroupsOptions(pData));
	}
	catch (std::logic_error const &e)
	{
		std::cout << "Error! " << e.what() << std::endl;
	}
    return EXIT_SUCCESS;
}