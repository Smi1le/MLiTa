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
	unsigned pupilsNumber;
	std::string inLineStudents;
};

void ReadDataFromFile(std::string const &fileName, Data &data)
{
	std::ifstream inputFile(fileName);
	if (!inputFile)
	{
		throw(std::logic_error("File was not opened!"));
	}
	inputFile >> data.pupilsNumber;
	inputFile >> data.inLineStudents;
}

int GetNumberPairs(Data const &data, int &difference)
{
	int boysNumber = 0;
	int girlsNumber = 0;
	for (auto element : data.inLineStudents)
	{
		if (toupper(element) == 'A')
		{
			++girlsNumber;
		}
		if (toupper(element) == 'B')
		{
			++boysNumber;
		}
	}
	difference = abs(boysNumber - girlsNumber);
	return boysNumber >= girlsNumber ? girlsNumber : boysNumber;
}

int GetNumberOptions(Data const &data)
{
	int difference;
	int pairsNumber = GetNumberPairs(data, difference);
	size_t optionsNumber = 0;
	for (size_t i = pairsNumber; i != 0; --i)
	{
		if (i == pairsNumber)
		{
			optionsNumber += i + static_cast<size_t>(difference);
		}
		else if (i == 1)
		{
			optionsNumber += 1 + difference;
		}
		else
		{
			optionsNumber += i * (i - 1) + i * difference;
		}
	}
	return static_cast<int>(optionsNumber);
}

void OutputInFile(std::string const &nameFile, int numberOptions)
{
	std::ofstream outputFile(nameFile);
	outputFile << numberOptions;
}

void InputValidation(Data const &data)
{
	if (data.pupilsNumber >= 1 && data.pupilsNumber <= 106 || 
		data.inLineStudents.length() != data.pupilsNumber)
	{
		throw(std::invalid_argument("It was entered wrong data"));
	}
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
		Data data;
		InputValidation(data);
		ReadDataFromFile(inputFileName, data);
		OutputInFile(outputFileName, GetNumberOptions(data));
	}
	catch (...)
	{
		std::cout << "Error! " << std::endl;
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}