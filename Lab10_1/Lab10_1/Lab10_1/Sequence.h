#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

enum TypeError { ALL_IS_SUCCESS, ERROR, INCORRECTLY_CALLED_COMMAND } const;


class CSequence
{
public:
	CSequence(int divider, int itemNumberToSearch, int firstElement);
	~CSequence() = default;
	int GetRightSequenceElement();
private:
	void FillingVectorNumbers();
	bool NumberIncludedInVector(int numberForVerification) const;
	std::vector<int> m_numbers;
	int m_divider;
	int m_itemNumberToSearch;
	int m_firstElementSequence;
};