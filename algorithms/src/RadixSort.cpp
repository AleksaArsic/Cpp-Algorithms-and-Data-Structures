#include "SortingAlgorithms.hpp"
#include <algorithm>

namespace SortingAlgorithms
{
	void RadixSort::LLInsert(std::vector<std::shared_ptr<Node>>& buckets, const int bucketIdx, const int data) const
	{
		if (buckets[bucketIdx] == nullptr)
		{
			buckets[bucketIdx] = std::make_unique<Node>(data, nullptr);
		}
		else
		{
			std::shared_ptr<Node> node = buckets[bucketIdx];

			while (node->next != nullptr)
			{
				node = node->next;
			}

			node->next = std::make_shared<Node>(data, nullptr);
		}
	}

	int RadixSort::LLDelete(std::vector<std::shared_ptr<Node>>& buckets) const
	{
		int retData = INT_MIN;

		int i = 0; 
		while (buckets[i] == nullptr && i < buckets.size())
		{
			i++;
		}

		retData = buckets[i]->data;
		buckets[i] = buckets[i]->next;

		return retData;
	}

	void RadixSort::operator()(const RadixSort::NumeralSystem numeralSystem, std::vector<int>& vec) const
	{
		int maxElement = *std::max_element(std::begin(vec), std::end(vec));

		int divisor = 1L;
		int bucketIdx = INT_MIN;

		while (divisor < maxElement)
		{
			std::vector<std::shared_ptr<Node>> buckets(10L);

			for(int i = 0; i < vec.size(); ++i)
			{
				bucketIdx = (vec[i] / divisor) % 10L;

				// Insert in a linked list
				LLInsert(buckets, bucketIdx, vec[i]);
			}

			for (int i = 0; i < vec.size(); ++i)
			{
				// Delete from a linked list
				vec[i] = LLDelete(buckets);
			}

			divisor *= 10L;
		}
	}
}