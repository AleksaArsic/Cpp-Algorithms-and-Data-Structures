#include "SortingAlgorithms.hpp"

namespace SortingAlgorithms
{
    void PrintVector::operator()(std::vector<int>& vec) const
    {
        std::cout << "Vector: ";
        for (const auto x : vec)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}