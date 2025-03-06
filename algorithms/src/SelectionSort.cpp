#include "SortingAlgorithms.hpp"
#include <algorithm>

namespace SortingAlgorithms
{
	void SelectionSort::operator()(std::vector<int>& vec) const
	{
		unsigned int vecSize = vec.size();

		for (unsigned int i = 0L; i < vecSize - 1L; ++i)
		{
			unsigned int k = i;

			for (unsigned int j = i + 1L; j < vecSize; ++j)
			{
				if (vec[j] < vec[k])
				{
					k = j;
				}
			}

			std::swap(vec[i], vec[k]);
		}
	}
}