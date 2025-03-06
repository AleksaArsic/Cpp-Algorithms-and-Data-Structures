#include "SortingAlgorithms.hpp"
#include <vector>
#include <algorithm>

namespace SortingAlgorithms
{
    void BubbleSort::operator()(std::vector<int>& vec) const
    {
        unsigned int vecSize = vec.size();
        bool swapped = false;

        for (int i = 0L; i < vecSize - 1L; ++i)
        {
            swapped = false;
            for (int j = 0L; j < vecSize - 1L - i; ++j)
            {
                if (vec[j] > vec[j + 1])
                {
                    std::swap(vec[j], vec[j + 1L]);
                    swapped = true;
                }
            }

            if (!swapped)
            {
                break;
            }
        }
    }
}