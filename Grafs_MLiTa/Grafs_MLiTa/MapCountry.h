#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>

enum TypeError
{
	ALL_IS_SUCCESS
	, ERROR
	, INCORRECTLY_CALLED_COMMAND
};

struct Pair
{
	int first;
	int second;
};


class CMapCountry
{
public:
	CMapCountry(std::vector<int> const &numberRoads)
		: m_numberRoadsLeavingCitys(numberRoads)
	{}
	void ConstructionNewRoads();
	std::vector<Pair> GetListNewRoads() const;
private:
	std::vector<int> m_numberRoadsLeavingCitys;
	std::vector<Pair> m_newRoads;
};