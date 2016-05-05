#include "stdafx.h"
#include "MapCountry.h"


void CMapCountry::ConstructionNewRoads()
{
	if (m_numberRoadsLeavingCitys.size() > 2)
	{
		int first = 0;
		for (size_t i = 0; i != m_numberRoadsLeavingCitys.size(); ++i)
		{
			if (first == 0 && m_numberRoadsLeavingCitys[i] == 1)
			{
				first = i + 1;
			}
			else if (m_numberRoadsLeavingCitys[i] == 1)
			{
				m_newRoads.push_back({ first, static_cast<int>(i) + 1 });
				first = i + 1;
			}
		}
	}
}

std::vector<Pair> CMapCountry::GetListNewRoads() const
{
	return m_newRoads;
}