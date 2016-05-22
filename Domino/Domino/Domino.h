#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>



struct Node
{
	Node() = default;
	Node(int lhs, int rhs, bool wasPas)
		: first(lhs)
		, second(rhs)
		, wasPassed(wasPas)
	{}
	int first;
	int second;
	bool wasPassed = false;
};

class CDominoHelper
{
public:
	CDominoHelper(std::vector<Node> const &set)
		:m_setDominoes(set)
	{}
	void BuildingPaths(std::vector<Node> &nodes);
	Node SearchFirstMaxDomino(Node const &max = Node(-1, -1, false));
	std::vector<Node> GetBestPath() const;
private:
	std::vector<Node> m_setDominoes;
	std::vector<std::vector<Node>> m_paths;
};
