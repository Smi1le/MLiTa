/*
3.8. Школа танцев (7)

В школу бальных танцев профессора Падеграса записались N  учеников — мальчиков и
девочек. Профессор построил их в один ряд, и хочет отобрать из них для первого занятия группу
стоящих подряд учеников, в которой количество мальчиков и девочек одинаково. Сколько
вариантов выбора есть у профессора? Решить задачу с помощью рекуррентных соотношений.
Ввод. В первой строке входного файла задано число N  (1 ≤ N ≤ 10^6). Во второй строке задается
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
#include <vector>
#include <boost\utility\string_ref.hpp>

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
		//throw(std::logic_error("File was not opened!"));
	}
	inputFile >> data.pupilsNumber;
	inputFile >> data.inLineStudents;

}

size_t akk(Data const &data)
{
	int difference = 1;
	char startElement = data.inLineStudents[0];
	int countPairs = 0;
	int largestNumberPairs = 0;
	for (size_t i = 1; i != data.pupilsNumber; ++i)
	{

		
		if (data.inLineStudents[i] == startElement)
		{
			++difference;
		}
		else
		{
			--difference;
		}
		if (difference == 0)
		{
			++countPairs;
		}
		/*std::cout << "data.inLineStudents[i] = " << data.inLineStudents[i] << std::endl;
		std::cout << "startElement = " << startElement << std::endl;
		std::cout << "difference = " << difference << std::endl;
		std::cout << "countPairs = " << countPairs << std::endl;*/
		if (difference < -1 || difference > 1 || i == data.pupilsNumber - 1)
		{
			/*if (largestNumberPairs <= countPairs)
			{
				largestNumberPairs += countPairs;
			}*/
			startElement = data.inLineStudents[i];
			//countPairs = 1;
			difference = 1;
		}
		
		//system("pause");
	}
	return countPairs;
}

size_t vLob(Data const &data)
{
	//int difference = 0;
	int boysNumber;
	int girlsNumber;
	int pairsNumber = 0;
	boost::string_ref str(data.inLineStudents);
	for (size_t i = 0; i != data.pupilsNumber; ++i)
	{
		girlsNumber = 0;
		boysNumber = 0;
		for (size_t j = i; j != data.pupilsNumber; ++j)
		{
			if (str[j] == 'a')
			{
				++girlsNumber;
			}
			else
			{
				++boysNumber;
			}
			if (boysNumber == girlsNumber)
			{
				++pairsNumber;
			}
		}
		/*std::cout << "boysNumber = " << boysNumber << std::endl;
		std::cout << "girlsNumber = " << girlsNumber << std::endl;
		system("pause");*/
		
	}
	return pairsNumber;
}

size_t kkkk(Data const &data)
{
	std::vector<std::string> vec;
	vec.resize(data.pupilsNumber, "");
	int number = 0;
	for (size_t i = 1; i != data.pupilsNumber; i++)
	{
		int j = 1;
		std::cout << "i1 = " << i << std::endl;
		//system("pause");
		while (j + i <= data.pupilsNumber + 1)
		{
			std::cout << "j + i = " << i + j << std::endl;
			++number;
			for (int k = 1; k != i; ++k)
			{
				std::cout << "k = " << k << std::endl;
				std::cout << "i + k - 1 = " << i + k - 1 << std::endl;
				std::cout << "data.inLineStudents[2] = " << data.inLineStudents[2] << std::endl;
				vec[number] = vec[number] + data.inLineStudents[i + k - 1];
			}
			++j;
		}
	}
	int boysNumber = 0;
	int girlsNumber = 0;
	int pairsNumber = 0;
	for (size_t i = 1; i != number; ++i)
	{
		std::cout << "i2 = " << i << std::endl;
		for (size_t j = 1; j != vec[i].size(); ++j)
		{
			std::cout << "j2 = " << j << std::endl;
			if (vec[i][j] == 'a')
			{
				++girlsNumber;
			}
			else
			{
				++boysNumber;
			}
		}
		if (girlsNumber == boysNumber)
		{
			++pairsNumber;
		}
	}
	
	return pairsNumber;
}

/*int GetNumberPairs(Data const &data, size_t &difference)
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
	std::cout << "boysNumber = " << boysNumber << std::endl;
	std::cout << "girlsNumber = " << girlsNumber << std::endl;
	system("pause");
	return boysNumber > girlsNumber ? girlsNumber : boysNumber;
}*/

size_t GetNumberOptions(Data const &data)
{
	size_t difference;
	int pairsNumber = 1;// GetNumberPairs(data, difference);
	size_t optionsNumber = 0;
	for (size_t i = pairsNumber; i != 0; --i)
	{
		if (i == pairsNumber)
		{
			optionsNumber += i + 1;
		}
		else if (i == 1)
		{
			optionsNumber += 1 + 1;
		}
		else
		{
			optionsNumber += i * (i - 1) + i * 1;
		}
		/*std::cout << "-------------------------------------" << std::endl;
		std::cout << "optionsNumber = " << optionsNumber << std::endl;
		std::cout << "i = " << i << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << std::endl;*/
	}
	return optionsNumber;
}

void OutputInFile(std::string const &nameFile, size_t numberOptions)
{
	std::cout << "numberOptions = " << numberOptions << std::endl;
	std::ofstream outputFile(nameFile);
	outputFile << numberOptions;
}

void InputValidation(Data const &data)
{
	if (data.pupilsNumber > pow(10, 6))
	{
		//throw(std::invalid_argument("It was entered wrong data"));
	}
}


//int main(int argc, char *argv[])
int main()
{
	/*if (argc != 3)
	{
		std::cout << "Error! Usage <dancingSchool.exe> <input file> <output file>\n";
		return EXIT_FAILURE;
	}*/
	try
	{
		std::string inputFileName = "input9.txt";// argv[1];
		std::string outputFileName = "output9.txt"; // argv[2];
		Data data;
		
		ReadDataFromFile(inputFileName, data);
		InputValidation(data);
		std::cout << "vLob(data) = " << vLob(data) << std::endl;
		OutputInFile(outputFileName, GetNumberOptions(data));
	}
	catch (...)
	{
		std::cout << "Error! " << std::endl;
		return EXIT_FAILURE;
	}
    return EXIT_SUCCESS;
}