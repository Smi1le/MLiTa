#include "stdafx.h"
#include "Domino.h"

using namespace std;

Node CDomino::SearchFirstMaxDomino()
{
	Node maxValue = m_setDominoes.front();
	size_t numberPos = 0;
	for (size_t i = 1; i != m_setDominoes.size(); ++i)
	{
		if (m_setDominoes[i].first > m_setDominoes[i].second)
		{
			if (m_setDominoes[i].first > maxValue.first
				|| m_setDominoes[i].first == maxValue.first && 
				(m_setDominoes[i].second > maxValue.second) && !m_setDominoes[i].wasPassed)
			{
				maxValue = m_setDominoes[i];
				numberPos = i;
			}
		}
		else
		{
			if (m_setDominoes[i].second > maxValue.second
				|| m_setDominoes[i].second == maxValue.second && 
				(m_setDominoes[i].first > maxValue.first) && !m_setDominoes[i].wasPassed)
			{
				maxValue = m_setDominoes[i];
				numberPos = i;
			}
		}
	}
	m_setDominoes.erase(m_setDominoes.begin() + numberPos);
	if (maxValue.first < maxValue.second)
	{
		return{ maxValue.second, maxValue.first, false };
	}
	return maxValue;
}

vector<Node> CDomino::GetBestPath() const
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


void CDomino::BuildPaths(vector<Node> &nodes)
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
			BuildPaths(nodes);
			m_setDominoes[i].wasPassed = false;
		}
		else if (m_setDominoes[i].second == key && !m_setDominoes[i].wasPassed)
		{
			nodes.push_back({ m_setDominoes[i].second, m_setDominoes[i].first, true });
			m_setDominoes[i].wasPassed = true;
			BuildPaths(nodes);
			m_setDominoes[i].wasPassed = false;
		}
	}
	m_paths.push_back(nodes);
	nodes.erase(nodes.end() - 1);
}