#include "stdafx.h"
#include "TextProcessor.h"


using namespace std;


std::pair<int, int> CTextProcessor::MakeCheckAndGetResult()
{
	if (CheckTextForCorrect())
	{
		return make_pair<int, int>(-1, -1);
	}
	return m_bracketsPositions[m_bracketsPositions.size() - 1];
}

bool CTextProcessor::CheckTextForCorrect()
{
	size_t i = 0;
	stack<char> st;
	for (auto l : m_pText)
	{
		boost::string_ref textString(l);
		for (size_t j = 0; j != textString.size(); ++j)
		{
			if (textString[j] == '#')
			{
				if (st.empty())
				{
					j = textString.size() - 1;
				}
				else
				{
					return false;
				}
			}
			else
			{
				for (auto it = m_brackets.begin(); it != m_brackets.end(); ++it)
				{
					if (st.empty() && (textString[j] == ')' || textString[j] == '}' || textString[j] == ']'))
					{
						m_bracketsPositions.push_back(make_pair<int, int>(static_cast<int>(i) + 1, static_cast<int>(j) + 1));
						return false;
					}
					if (it->first == textString[j])
					{
						m_bracketsPositions.push_back(make_pair<int, int>(static_cast<int>(i) + 1, static_cast<int>(j) + 1));
						st.push(textString[j]);
						it = m_brackets.end();
					}
					if (it->second == textString[j] && !st.empty() && st.top() == it->first)
					{
						m_bracketsPositions.pop_back();
						st.pop();
						it = m_brackets.end();
					}
					else if (it->second == textString[j] && !st.empty() && st.top() != it->first)
					{
						m_bracketsPositions.push_back(make_pair<int, int>(static_cast<int>(i) + 1, static_cast<int>(j) + 1));
						return false;
					}
				}
			}
		}
		++i;
	}
	return true;
}