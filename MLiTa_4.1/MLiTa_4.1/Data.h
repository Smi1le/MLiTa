#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class CData
{
public:
	CData(std::vector<int> const &seq, int limit);
	void CalculationPossibleSequences();
	std::pair<int, std::vector<int>> GetResultsSearch() const;
private:
	std::vector<std::vector<int>> m_resulingSequence;
	std::vector<int> m_sequence;
	std::vector<int> m_lastNormalPoint;
	int m_limit;
};