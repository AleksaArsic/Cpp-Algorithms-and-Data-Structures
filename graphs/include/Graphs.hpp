#pragma once
#include "ComplexTypes.hpp"
#include <memory>
#include <iostream>
#include <stack>
#include <queue>

namespace Graphs
{
	template <typename T, std::size_t Row, std::size_t Col> requires ComplexTypes::IntegralNumber<T>
	class Graph final
	{
		public:
			Graph() = delete;
			Graph(Graph& g) = delete;
			Graph(Graph&& g) = delete;

			Graph& operator=(const Graph& g) = delete;
			Graph& operator=(Graph&& g) = delete;

			Graph(ComplexTypes::Array2d<T, Row, Col>& adjecencyMatrix) 
			{
				graph = std::make_unique<ComplexTypes::Array2d<T, Row, Col>>(adjecencyMatrix);
			}

			void BFS(T vertix) const
			{
				std::cout << "BFS: " << std::endl;

				std::queue<T> dataQueue;
				std::array<bool, Col> visited{ false };

				dataQueue.push(vertix);
				visited[vertix] = true;

				while (!dataQueue.empty())
				{
					T vertix = dataQueue.front();
					dataQueue.pop();
					std::cout << vertix << " ";

					for (int i = 1L; i < Col; ++i)
					{
						if ((*graph)[vertix][i] >= 1L && visited[i] == false)
						{
							dataQueue.push(i);
							visited[i] = true;
						}
					}
				}
				std::cout << std::endl;
			}

			void DFS(T vertix) const
			{
				std::cout << "DFS: " << std::endl;

				DFSrecursion(vertix);

				std::cout << std::endl;
			}

			friend std::ostream& operator<<(std::ostream& os, const Graph& g)
			{
				os << "Graph Adjecency Matrix: " << std::endl;
				for (int i = 0L; i < Row; ++i)
				{
					for (int j = 0L; j < Col; ++j)
					{
						os << (*g.graph)[i][j] << " ";
					}
					os << std::endl;
				}

				return os;
			}

		private:
			std::unique_ptr<ComplexTypes::Array2d<T, Row, Col>> graph;

			void DFSrecursion(T vertix) const
			{
				static std::array<bool, Col> visited{ false };

				if (visited[vertix] == false)
				{
					std::cout << vertix << " ";
					visited[vertix] = true;

					for (int i = 1L; i < Col; ++i)
					{
						if ((*graph)[vertix][i] == 1L && visited[i] == false)
						{
							DFSrecursion(i);
						}
					}
				}
			}
	};
}