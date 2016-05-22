#include "stdafx.h"
#include "Domino.h"

using namespace std;

Node CDominoHelper::SearchFirstMaxDomino(Node const &max)
{
	Node maxValue = max;
	size_t number = -1;
	for (size_t i = 0; i != m_setDominoes.size(); ++i)
	{
		if (m_setDominoes[i].first > m_setDominoes[i].second)
		{
			if (m_setDominoes[i].first > maxValue.first
				|| m_setDominoes[i].first == maxValue.first && m_setDominoes[i].second > maxValue.second && !m_setDominoes[i].wasPassed)
			{
				maxValue = m_setDominoes[i];
				number = i;
			}
		}
		else
		{
			if (m_setDominoes[i].second > maxValue.second
				|| m_setDominoes[i].second == maxValue.second && m_setDominoes[i].first > maxValue.first && !m_setDominoes[i].wasPassed)
			{
				maxValue = m_setDominoes[i];
				number = i;
			}
		}
	}
	m_setDominoes.erase(m_setDominoes.begin() + number);
	if (maxValue.first < maxValue.second)
	{
		return{ maxValue.second, maxValue.first, false };
	}
	return maxValue;
}

vector<Node> CDominoHelper::GetBestPath() const
{
	size_t number = 0;
	size_t size = 0;
	for (size_t i = 0; i != m_paths.size(); ++i)
	{
		if (m_paths[i].size() > size)
		{
			number = i;
			size = m_paths[i].size();
		}
	}
	return m_paths[number];
}


void CDominoHelper::BuildingPaths(vector<Node> &nodes)
{
	int key;
	if (nodes.size() == 1)
	{
		key = nodes[nodes.size() - 1].first < nodes[nodes.size() - 1].second
			? nodes[nodes.size() - 1].first : nodes[nodes.size() - 1].second;
	}
	else
	{
		key = nodes[nodes.size() - 1].second;
	}
	for (size_t i = 0; i != m_setDominoes.size(); ++i)
	{
		if (m_setDominoes[i].first == key && !m_setDominoes[i].wasPassed)
		{
			m_setDominoes[i].wasPassed = true;
			nodes.push_back(m_setDominoes[i]);
			BuildingPaths(nodes);
			m_setDominoes[i].wasPassed = false;
		}
		else if (m_setDominoes[i].second == key && !m_setDominoes[i].wasPassed)
		{
			nodes.push_back({ m_setDominoes[i].second, m_setDominoes[i].first, true });
			m_setDominoes[i].wasPassed = true;
			BuildingPaths(nodes);
			m_setDominoes[i].wasPassed = false;
		}
	}
	m_paths.push_back(nodes);
	nodes.erase(nodes.end() - 1);
}