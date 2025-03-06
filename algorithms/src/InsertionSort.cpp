#include "SortingAlgorithms.hpp"

namespace SortingAlgorithms
{
	void InsertionSort::operator()(std::vector<int>& vec) const
	{		
		for (unsigned int i = 1; i < vec.size(); ++i)
		{
			int data = vec[i];
			int j = (i - 1L);

			while(j > -1L && vec[j] > data)
			{
				vec[j + 1] = vec[j];
				j--;
			}

			vec[j + 1] = data;
		}
	}
}