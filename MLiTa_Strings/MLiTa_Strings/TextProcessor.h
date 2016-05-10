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
	CTextProcessor(std::vector<std::string> const &text)
		:m_pText(text)
	{
		m_brackets.insert({ '(', ')' });
		m_brackets.insert({ '[', ']' });
		m_brackets.insert({ '{', '}' });
	}
	std::pair<int, int> MakeCheckAndGetResult();
private:
	bool CheckTextForCorrect();
	std::vector<std::pair<int, int>> m_bracketsPositions;
	std::map<char, char> m_brackets;
	std::vector<std::string> m_pText;

};