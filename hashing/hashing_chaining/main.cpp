#include <iostream>
#include <memory>
#include "ChainHashing.hpp"

int main()
{
    ChainHashing::Hash hashMap;

    hashMap.SortedInsert(1);
    hashMap.SortedInsert(12);
    hashMap.SortedInsert(88);
    hashMap.SortedInsert(3);
    hashMap.SortedInsert(13);
    hashMap.SortedInsert(8);
    hashMap.SortedInsert(22);
    hashMap.SortedInsert(1);
    hashMap.SortedInsert(17);

    for (unsigned int i = 33; i < 52; ++i)
    {
        hashMap.SortedInsert(i);
    }

    std::cout << hashMap << std::endl;

    std::cout << "Search for ";
    if (hashMap.Search(22))
    {
        std::cout << "22: found." << std::endl;
    }
    else
    {
        std::cout << "22: not found." << std::endl;
    }

    std::cout << "Search for ";
    if (hashMap.Search(100))
    {
        std::cout << "100: found." << std::endl;
    }
    else
    {
        std::cout << "100: not found." << std::endl;
    }

    std::cout << "Deleting: " << hashMap.DeleteElement(22) << std::endl;
    std::cout << "Deleting: " << hashMap.DeleteElement(12) << std::endl;
    std::cout << "Deleting: " << hashMap.DeleteElement(42) << std::endl;
    std::cout << "Deleting: " << hashMap.DeleteElement(100) << std::endl;

    std::cout << hashMap << std::endl;

    return 0;
}