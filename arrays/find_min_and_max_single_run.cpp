#include <iostream>

// Time complexity -> o(n)
// Best time -> we will have the n - 1 comparations, array is in ascending order
// Worst time -> we will have 2*(n - 1) comparations, array is in descending order
void findMinAndMaxSingleRun(const unsigned int size, const int* array)
{
    int maxElement = array[0];
    int minElement = array[0];

    for(unsigned int i = 1; i < size; ++i)
    {
        if(array[i] > maxElement)
        {
            maxElement = array[i];
        }
        else if(array[i] < minElement)
        {
            minElement = array[i];
        }
    }

    std::cout << "Minimal element in the array: " << minElement << ", maximal element in the array: "
              << maxElement << "." << std::endl;
}

int main()
{
    constexpr unsigned int n = 10;
    int arrayOfNumbers[n] = { 5, 8, 3, 9, 6, 2, 10, 7, -1, 4 };

    findMinAndMaxSingleRun(n, arrayOfNumbers);

    return 0;
}