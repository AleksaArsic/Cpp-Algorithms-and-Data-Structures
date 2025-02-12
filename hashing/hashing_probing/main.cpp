#include <iostream>
#include <memory>
#include "ProbeHashing.hpp"

int main()
{
    ProbeHashing::Hash hashMap(10);

    hashMap.Insert(88);
    hashMap.Insert(13);
    hashMap.Insert(3);
    hashMap.Insert(33);
    //hashMap.Insert(99);
    //hashMap.Insert(10);
    hashMap.Insert(9);

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

    std::cout << "Deleting: " << hashMap.DeleteElement(13) << std::endl;
    //std::cout << "Deleting: " << hashMap.DeleteElement(3) << std::endl;
    //std::cout << "Deleting: " << hashMap.DeleteElement(33) << std::endl;
    std::cout << "Deleting: " << hashMap.DeleteElement(222) << std::endl;

    std::cout << hashMap << std::endl;

    return 0;
}