#include "SortingAlgorithms.hpp"

namespace SortingAlgorithms
{
	void MergeSort::Merge(std::vector<int>& vec, const int low, const int mid, const int high) const
	{
		std::vector<int> mergeVector;
        int i = low;
        int j = mid + 1L;

        while(i <= mid && j <= high)
        {
            if(vec[i] < vec[j]) mergeVector.emplace_back(vec[i++]);
            else mergeVector.emplace_back(vec[j++]);
        }

        for(; i <= mid; ++i) mergeVector.emplace_back(vec[i]);
        for(; j <= high; ++j) mergeVector.emplace_back(vec[j]);

        for(int k = low, l = 0; k <= high; ++k, ++l) vec[k] = mergeVector[l];
	}

	void MergeSort::Partition(std::vector<int>& vec, const int low, const int high) const
	{
		if (low < high)
		{	
			int mid = (low + high) / 2L;
			Partition(vec, low, mid);
			Partition(vec, mid + 1L, high);

			Merge(vec, low, mid, high);
		}

		
	}

	void MergeSort::iterativeMergeSort(std::vector<int>& vec) const
	{
		int p;

		for (p = 2L; p <= vec.size(); p *= 2L)
		{
			for (int i = 0; i + p - 1L < vec.size(); i += p)
			{
				int low = i;
				int high = i + p - 1L;
				int mid = (low + high) / 2L;

				Merge(vec, low, mid, high);
			}
		}

		if (p / 2L < vec.size())
		{
			Merge(vec, 0L, p / 2L - 1L, vec.size() - 1L);
		}
	}

	void MergeSort::recursiveMergeSort(std::vector<int>& vec) const
	{
		Partition(vec, 0L, vec.size() - 1L);
	}

	void MergeSort::operator()(const MergeSortType& type, std::vector<int>& vec) const
	{
		switch (type)
		{
			case MergeSortType::ITERATIVE_MERGE_SORT:
				iterativeMergeSort(vec);
				break;
			case MergeSortType::RECURSIVE_MERGE_SORT:
				recursiveMergeSort(vec);
				break;
			default:
				break;
		}
	}
}