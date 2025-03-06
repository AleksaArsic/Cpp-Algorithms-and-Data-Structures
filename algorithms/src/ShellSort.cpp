#include "SortingAlgorithms.hpp"

namespace SortingAlgorithms
{
	void ShellSort::operator()(std::vector<int>& vec) const
	{
		for (int gap = vec.size() / 2L; gap >= 1L; gap /= 2L)
		{
			for (int i = gap; i < vec.size(); ++i)
			{
				int temp = vec[i];
				int j = i - gap;

				while (j >= 0L && vec[j] > temp)
				{
					vec[j + gap] = vec[j];
					j = j - gap;
				}

				vec[j + gap] = temp;
			}
		}
	}
}