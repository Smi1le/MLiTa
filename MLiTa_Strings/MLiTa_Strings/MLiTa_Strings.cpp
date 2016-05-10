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
		OutputToFile(text.MakeCheckAndGetResult(), argv[2]);
		return TypeError::ALL_IS_SUCCESS;
	}
	catch (...)
	{
		cerr << "Error!" << endl;
		return TypeError::ERROR;
	}
}

