#include "stdafx.h"
#include "Sequence.h"

using namespace std;

CSequence::CSequence(int divider, int itemNumberToSearch, int firstElement)
	: m_divider(divider)
	, m_itemNumberToSearch(itemNumberToSearch)
	, m_firstElementSequence(firstElement)
{}

bool CSequence::NumberIncludedInVector(int numberForVerification) const
{
	return (0 == std::count(m_numbers.begin(), m_numbers.end(), numberForVerification));
}

void CSequence::FillingVectorNumbers()
{
	size_t squareNumber = static_cast<size_t>(pow(m_firstElementSequence, 2));
	int previousValue = squareNumber % m_divider;
	for (size_t i = 3; i <= INT_MAX - 1; ++i)
	{
		squareNumber = static_cast<size_t>(pow(previousValue, 2));
		previousValue = squareNumber % m_divider;
		if (!NumberIncludedInVector(previousValue))
		{
			m_numbers.push_back(previousValue);
		}
		else
		{
			i = INT_MAX;
		}
	}
}

int CSequence::GetRightSequenceElement()
{
	if (m_firstElementSequence > 1 || m_firstElementSequence < -1)
	{
		FillingVectorNumbers();
		size_t passesNumber = m_itemNumberToSearch / (m_numbers.size());
		if (passesNumber == 0)
		{
			//Так как элементы вектора считаются с 0 позиции то -1 ,а так как первые два элемента не считаются то -3
			return m_numbers[m_itemNumberToSearch - 3];
		}
		else
		{
			int positionDesiredItem = m_itemNumberToSearch - static_cast<int>(2 + (passesNumber * (m_numbers.size())));
			if (positionDesiredItem == 0)
			{
				return m_numbers[m_numbers.size() - 1];
			}
			else if (positionDesiredItem < 0)
			{
				positionDesiredItem = m_itemNumberToSearch - static_cast<int>(2 + ((passesNumber - 1) * (m_numbers.size())));
				return m_numbers[positionDesiredItem - 1];
			}
			else
			{
				return m_numbers[positionDesiredItem - 1];
			}
		}
	}
	else
	{
		return m_firstElementSequence == 0 ? 0 : 1;
	}
}