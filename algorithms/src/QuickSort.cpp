#include "SortingAlgorithms.hpp"
#include <algorithm>

namespace SortingAlgorithms
{
    void QuickSort::recursiveQuickSortAlg(std::vector<int>& vec, const int low, const int high) const
    {
        int highIdx;

        if (low < high)
        {
            highIdx = partition(vec, low, high);
            recursiveQuickSortAlg(vec, low, highIdx);
            recursiveQuickSortAlg(vec, highIdx + 1L, high);
        }
    }

    int QuickSort::partition(std::vector<int>& vec, const int low, const int high) const
    {
        int pivot = vec[low];
        int lowIdx = low;
        int highIdx = high;

        do
        {
            while (vec[lowIdx] <= pivot) lowIdx++;
            while (vec[highIdx] > pivot) highIdx--;

            if (lowIdx < highIdx) std::swap(vec[lowIdx], vec[highIdx]);

        } while (lowIdx < highIdx);

        std::swap(vec[low], vec[highIdx]);

        return highIdx;
    }

    void QuickSort::operator()(std::vector<int>& vec) const
    {
        recursiveQuickSortAlg(vec, 0, vec.size() - 1L);
    }
}