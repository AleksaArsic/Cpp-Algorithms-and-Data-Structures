#include <iostream>
#include <memory>
#include <algorithm>

// Duplicates need to be next to one another
// Time complexity -> o(n^2)
// Inner loop will repeat only several times so we can neglect it in the 
// time complexity analysis per some lecturers
void findDuplicateElements(const unsigned int size, const unsigned int* array)
{
    unsigned int j = 0;

    for(unsigned int i = 0; i < size - 1; ++i)
    {
        if(array[i] == array[i + 1])
        {
            j = i + 1;
            while(array[i] == array[j]) { j++; }
            std::cout << "Found duplicate: " << array[i] << ". Number of found duplicates: " << j - i << std::endl;

            i = j - 1;
        }
    }
}

// Array does not have to be sorted!
// Time complexity -> o(n)
// Can take a great amount of space due to the hash being kept in memory
void findDuplicateElementsWithHashing(const unsigned int size, const unsigned int* array)
{
    unsigned int maximalElement = *(std::max_element(array, array + size));
    unsigned int minimalElement = *(std::min_element(array, array + size));

    std::unique_ptr<unsigned int[]> hashTable = std::make_unique<unsigned int[]>(maximalElement + 1);

    for(unsigned int i = 0; i < size; ++i)
    {
        hashTable[array[i]]++;
    }

    for(unsigned int i = minimalElement; i < maximalElement; ++i)
    {
        if(hashTable[i] > 1)
        {
            std::cout << "[HASHING] Duplicate element: " << i << " repeats " << hashTable[i] << " times." << std::endl;
        }
    }

}

// Array does not have to be sorted! 
// Duplicate elements do not have to be next to each other!
// Time complexity -> O(n^2) (two for loops)
// Time complexity -> n + n - 1 + ... + 2 + 1
//                 -> n(n-1) / 2 -> O(n^2)
void findDuplicateElementsInUnsortedArray(const unsigned int size, int* array)
{
    unsigned int count = 0;
    for(unsigned int i = 0; i < size - 1; ++i)
    {        
        if(array[i] == -1) continue;

        count = 1;
        for(unsigned int j = i + 1; j < size; ++j)
        {
            if(array[i] == array[j]) 
            {
                count++;
                array[j] = -1; // intentionally
            }
        }

        if(count > 1)
        {
            std::cout << "Number " << array[i] << " is found " << count << " times." << std::endl;
        }
    }
}

int main()
{
    constexpr int n = 11;
    unsigned int arrayOfNumbers[n] = {2, 11, 11, 9, 3, 12, 6, 6, 18, 18, 18};
    int arrayOfNumbersTwo[n] = {2, 11, 11, 9, 3, 12, 6, 6, 18, 18, 18};

    findDuplicateElements(n, arrayOfNumbers);
    findDuplicateElementsWithHashing(n, arrayOfNumbers);
    findDuplicateElementsInUnsortedArray(n, arrayOfNumbersTwo);

    return 0;
}