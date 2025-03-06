#include "Graphs.hpp"
#include "ComplexTypes.hpp"

int main()
{
	constexpr int verticeNo = 7L;
	ComplexTypes::Array2d<int, verticeNo, verticeNo> graphAdjecencyMatrix{{ {0, 0, 0, 0, 0, 0, 0},
																			{0, 0, 1, 1, 0, 0, 0},
																			{0, 1, 0, 0, 1, 0, 0},
																			{0, 1, 0, 0, 1, 0, 0},
																			{0, 0, 1, 1, 0, 1, 1},
																			{0, 0, 0, 0, 1, 0, 0},
																			{0, 0, 0, 0, 1, 0, 0} }};

	Graphs::Graph<int, verticeNo, verticeNo> graph(graphAdjecencyMatrix);

	std::cout << graph;
	graph.BFS(1L);
	graph.DFS(1L);

	return 0;
}