#include "SortingAlgorithms.hpp"
#include <algorithm>

namespace SortingAlgorithms
{
	void CountSort::operator()(std::vector<int>& vec) const
	{
		const int vecMaxElement = *std::max_element(std::begin(vec), std::end(vec));
		std::vector<int> countVector(vecMaxElement + 1L);

		for (int i = 0; i < vec.size(); ++i)
		{
			countVector[vec[i]]++;
		}

		int j = 0;
		int k = 0;

		while (j < vecMaxElement + 1L)
		{
			if (countVector[j] > 0)
			{
				vec[k++] = j;
				countVector[j]--;
			}
			else
			{
				++j;
			}
		}
	}
}