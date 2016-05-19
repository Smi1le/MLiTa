#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <boost/utility/string_ref.hpp>
#include <stack>
#include <map>

enum TypeError
{
	ALL_IS_SUCCESS
	, ERROR
	, INCORRECTLY_CALLED_COMMAND
};

class CTextProcessor
{
public:
	CTextProcessor(std::vector<std::string> const &text);
	std::pair<int, int> GetTestResult();
private:
	bool CheckCorrectnessBrackets(char element, std::stack<char> &st, int i, int j);
	bool CheckCorrectnessString(boost::string_ref const &element, std::stack<char> &st,
		int i, bool &multilineComment, bool &multilineLiteral);
	bool CheckCorrectnessText();

	std::vector<std::pair<int, int>> m_bracketsPositions;
	std::map<char, char> m_brackets;
	std::vector<std::string> m_text;

};