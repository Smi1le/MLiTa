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

class CDomino
{
public:
	CDomino(std::vector<Node> const &set)
		:m_setDominoes(set)
	{}
	void BuildPaths(std::vector<Node> &nodes);
	Node SearchFirstMaxDomino();
	std::vector<Node> GetBestPath() const;
private:
	std::vector<Node> m_setDominoes;
	std::vector<std::vector<Node>> m_paths;
};
