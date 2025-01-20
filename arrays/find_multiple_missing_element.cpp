#include <iostream>
#include <memory>
#include <algorithm>

// Array needs to be sorted!
// Time complexity -> o(n^2)
// Inner loop will repeat only several times so we can neglect it in the 
// time complexity analysis per some lecturers
void findMissingElement(const unsigned int size, const unsigned int* array)
{
    unsigned int diff = array[0] - 0; // diff = lowest element - first index

    for(unsigned int i = 0; i < size; ++i)
    {
        while(array[i] - i != diff)
        {
            std::cout << "Missing element is: " << diff + i << std::endl;
            diff++;
        }
    }
}

// Array does not have to be sorted!
// Time complexity -> o(n)
// Can take a great amount of space due to the hash being kept in memory
void findMissingElementsWithHashing(const unsigned int size, const unsigned int* array)
{
    unsigned int maximalElement = *(std::max_element(array, array + size));
    unsigned int minimalElement = *(std::min_element(array, array + size));

    std::unique_ptr<unsigned int[]> hashTable = std::make_unique<unsigned int[]>(maximalElement + 1);

    for(unsigned int i = 0; i < size; ++i)
    {
        hashTable[array[i]] = 1;
    }

    for(unsigned int i = minimalElement; i < maximalElement; ++i)
    {
        if(hashTable[i] == 0)
        {
            std::cout << "[HASHING] Missing number: " << i << std::endl;
        }
    }
}

int main()
{
    constexpr unsigned int n = 11;
    unsigned int arrayOfNumbers[n] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};

    findMissingElement(n, arrayOfNumbers);
    findMissingElementsWithHashing(n, arrayOfNumbers);
    
    return 0;
}