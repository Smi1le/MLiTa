#include "stdafx.h"
#include "Data.h"


using namespace std;



CData::CData(std::vector<int> const &seq, int limit)
	: m_sequence(seq)
	, m_limit(limit)
{}

pair<int, vector<int>>  CData::GetResultsSearch() const
{
	if (!m_resulingSequence.empty())
	{
		return{ m_lastNormalPoint.front(), m_resulingSequence.front() };
	}
	return{ -1,{} };
}


void CData::CalculationPossibleSequences()
{
	for (size_t i = 0; i != m_sequence.size(); ++i)
	{
		int firstElement = m_sequence[i];
		vector<int> sequence = { firstElement };
		int limit = 1;
		bool flag = false;

		for (size_t j = i; j != m_sequence.size(); ++j)
		{
			if (m_sequence[j] == firstElement + 13)
			{
				sequence.push_back(m_sequence[j]);
				firstElement += 13;
				++limit;
			}
			if (limit == m_limit && !flag)
			{
				flag = true;
				m_lastNormalPoint.push_back(static_cast<int>(j));
			}
		}
		if (flag)
		{
			m_resulingSequence.push_back(sequence);
		}
	}
}