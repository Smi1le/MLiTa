#include "stdafx.h"
#include "TextProcessor.h"


using namespace std;

CTextProcessor::CTextProcessor(vector<string> const &text)
	:m_text(text)
{
	m_brackets.insert({ '(', ')' });
	m_brackets.insert({ '[', ']' });
	m_brackets.insert({ '{', '}' });
}

std::pair<int, int> CTextProcessor::GetTestResult()
{
	if (CheckCorrectnessText())
	{
		return { -1, -1 };
	}
	return m_bracketsPositions.back();
}

bool CTextProcessor::CheckCorrectnessText()
{
	size_t i = 0;
	stack<char> st;
	bool multilineComment = false;
	for (auto const &l : m_text)
	{
		boost::string_ref textString(l);
		if (!CheckCorrectnessString(textString, st, static_cast<int>(i), multilineComment))
		{
			return false;
		}
		++i;
	}
	return true;
}

bool CTextProcessor::CheckCorrectnessString(boost::string_ref const &element, stack<char> &st, int i, bool &multilineComment)
{
	string lit;
	int number = 1;
	for (size_t j = 0; j != element.size(); ++j)
	{
		lit = lit + element[j];
		if (number == 3 && (lit == R"(""")"))
		{
			multilineComment = multilineComment ? false : true;
		}
		if (!multilineComment && element[j] == '#')
		{
			if (st.empty())
			{
				break;
			}

			m_bracketsPositions.push_back({ i + 1, static_cast<int>(j) + 1 });
			return false;
		}
		else if (!multilineComment)
		{
			if (!CheckCorrectnessBrackets(element[j], st, i, static_cast<int>(j)))
			{
				return false;
			}
		}
		if (j < element.size() && element[j + 1] == element[j])
		{
			++number;
		}
		else
		{
			number = 1;
			lit = "";
		}
	}
	if (!multilineComment && !st.empty())
	{
		m_bracketsPositions.push_back({ i + 1, static_cast<int>(element.size()) });
		return false;
	}
	return true;
}

bool CTextProcessor::CheckOnMultilineComment(int number, string const &lit, bool const &mc, boost::string_ref const &element, int j)
{
	
}

bool CTextProcessor::CheckCorrectnessBrackets(char element, stack<char> &st, int i, int j)
{
	for (auto it = m_brackets.begin(); it != m_brackets.end(); ++it)
	{
		if (st.empty() && (element == ')' || element == '}' || element == ']'))
		{
			m_bracketsPositions.push_back({ i + 1, j + 1 });
			return false;
		}
		if (it->first == element)
		{
			m_bracketsPositions.push_back({ i + 1, j + 1 });
			st.push(element);
			break;
		}
		if (it->second == element && !st.empty() && st.top() == it->first)
		{
			m_bracketsPositions.pop_back();
			st.pop();
			break;
		}
		else if (it->second == element && !st.empty() && st.top() != it->first)
		{
			m_bracketsPositions.push_back({ i + 1, j + 1 });
			return false;
		}
	}
	return true;
}