#include <iostream>
#include <algorithm>
#include <memory>

// All elements of the array are unique
// Array does not have to be sorted
// The procedure is similar as to the finding duplicate elements
// Time complexity -> o(n^2)
// This is a time consuming method
void pairOfElementsWithTheSum(const unsigned int sum, 
                              const unsigned int size, const unsigned int* array)
{
    for(unsigned int i = 0; i < size - 1; ++i)
    {
        for(unsigned int j = i + 1; j < size; ++j)
        {
            if(array[i] + array[j] == sum)
            {
                std::cout << "The numbers with the given sum: " << sum << 
                             " are: (" << i << ", " << array[i] << ") and (" << 
                             j << ", " << array[j] << ")." << std::endl; 
            }
        }
    }
}

// All elements of the array are unique
// Array does not have to be sorted
// The procedure is similar as to the finding duplicate elements
// Time complexity -> o(n)
// This is a memory consuming method
void pairOfElementsWithTheSumHashing(const unsigned int sum, 
                                     const unsigned int size, const unsigned int* array)
{
    unsigned int minElement = *(std::min_element(array, array + size));
    unsigned int maxElemenet = *(std::max_element(array, array + size));

    std::unique_ptr<unsigned int[]> hashTable = std::make_unique<unsigned int[]>(maxElemenet);

    unsigned int secondOperand = 0;
    for(unsigned int i = 0; i < size; ++i)
    {
        if(sum > array[i])
        {
            secondOperand = sum - array[i];
        }
        else
        {
            continue;
        }

        if(hashTable[secondOperand] != 0)
        {
            std::cout << "[HASHING] The numbers with the given sum: " << sum << 
                             " are: (" << array[i] << ", " << secondOperand << ")." << std::endl; 
        }
        
        hashTable[array[i]]++;
    }

}

// Array has to be sorted!
// All elements of the array are unique
// The procedure is similar as to the finding duplicate elements
// Time complexity -> o(n)
void pairOfElementsWithTheSumSorted(const unsigned int sum, 
                                    const unsigned int size, const unsigned int* array)
{
    unsigned int i = 0;
    unsigned int j = size - 1;
    unsigned int elementSum = 0;

    while(i < j)
    {
        elementSum = array[i] + array[j];

        if(elementSum > sum)
        {
            --j;
        }
        else if(elementSum < sum)
        {
            ++i;
        }
        else
        {
            std::cout << "The numbers with the given sum: " << sum << 
                             " are: (" << i << ", " << array[i] << ") and (" << 
                             j << ", " << array[j] << ")." << std::endl; 
            ++i;
            --j;
        }
    }

}

int main()
{
    constexpr unsigned int requestedSum = 10;
    constexpr unsigned int n = 11;
    unsigned int arrayOfNumbers[n] = { 6, 3, 8, 10, 16, 7, 5, 2, 9, 14, 1};
    unsigned int arrayOfNumbersSorted[n] = { 1, 3, 4, 5, 6, 8, 9, 10, 12, 14, 16};

    pairOfElementsWithTheSum(requestedSum, n, arrayOfNumbers);
    pairOfElementsWithTheSumHashing(requestedSum, n, arrayOfNumbers);
    pairOfElementsWithTheSumSorted(requestedSum, n, arrayOfNumbersSorted);

    return 0;
}