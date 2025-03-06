#include "SortingAlgorithms.hpp"
#include <algorithm>
#include <memory>

namespace SortingAlgorithms
{
	void BucketSort::LLInsert(std::vector<std::unique_ptr<Node>>& buckets, const int data) const
	{
		std::unique_ptr<Node> newNode = std::make_unique<Node>(data, std::move(buckets[data]));
		buckets[data] = std::move(newNode);
	}

	int BucketSort::LLDelete(std::vector<std::unique_ptr<Node>>& buckets, const int data) const
	{
		int retData = INT_MIN;
		
		if (buckets[data] != nullptr)
		{
			retData = data;
			std::unique_ptr<Node> root = std::move(buckets[data]);
			buckets[data] = std::move(root->next);
			root.reset();
		}

		return retData;
	}

	void BucketSort::operator()(std::vector<int>& vec) const
	{
		int vecMaxElement = *std::max_element(std::begin(vec), std::end(vec));
		std::vector<std::unique_ptr<Node>> buckets(vecMaxElement + 1L);

		// Populate the buckets
		for (int i = 0; i < vec.size(); ++i)
		{
			LLInsert(buckets, vec[i]);
		}

		// Populate original vector with sorted values
		int j = 0;
		int k = 0;

		while (j < vecMaxElement + 1L)
		{
			while (buckets[j] != nullptr)
			{
				vec[k++] = LLDelete(buckets, j);
			}

			++j;
		}
	}
}