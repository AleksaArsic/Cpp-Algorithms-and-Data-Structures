#include <iostream>
#include <memory>
#include "CircularDoublyLinkedList.hpp"

std::shared_ptr<int[]> createDummyArray(const unsigned int sizeOfArray)
{
    std::shared_ptr<int[]> elementsToAdd = std::make_shared<int[]>(sizeOfArray);

    for (int i = 0; i < sizeOfArray; ++i)
    {
        elementsToAdd[i] = i;
    }

    return elementsToAdd;
}

int main()
{
    constexpr int dummyArraySize = 10;
    CircularDoublyLinkedList::CircularDoublyLinkedList cdll;

    std::shared_ptr<int[]> dummyArray = createDummyArray(dummyArraySize);
    cdll.AddElements(dummyArraySize, dummyArray);
    std::cout << cdll << std::endl;
    cdll.AddElements(5, std::shared_ptr<int[]>(new int[] {10, 11, 12, 13, 14}));
    std::cout << cdll << std::endl;

    std::cout << cdll.getHead() << std::endl;
    std::cout << cdll.getHeadRef() << std::endl;

    cdll.DisplayInReverse();
    std::cout << std::endl;

    std::cout << "Insert at a position: " << std::endl;

    cdll.Insert(0, 15);
    cdll.Insert(0, 15);
    cdll.Insert(cdll.countNodes(), 25);
    cdll.Insert(4, 16);
    cdll.Insert(88, 16);
    
    std::cout << cdll << std::endl;

    cdll.InsertLast(66);
    cdll.InsertLast(77);
    cdll.InsertLast(88);

    std::cout << cdll << std::endl;

    CircularDoublyLinkedList::CircularDoublyLinkedList cdllSorted;

    cdllSorted.Insert(0, 10);
    cdllSorted.Insert(0, 10);
    cdllSorted.Insert(0, 10);
    cdllSorted.Insert(0, 8);
    cdllSorted.Insert(0, 8);
    cdllSorted.Insert(0, 3);
    cdllSorted.Insert(0, 0);
    cdllSorted.Insert(0, 0);
    cdllSorted.Insert(0, -5);

    std::cout << "Sorted Circular Doubly Linked List:" << std::endl;
    std::cout << cdllSorted << std::endl;

    cdllSorted.InsertInASortedList(2);
    cdllSorted.InsertInASortedList(-8);
    cdllSorted.InsertInASortedList(15);

    std::cout << cdllSorted << std::endl;

    cdllSorted.DeleteHead();
    cdllSorted.DeleteDuplicates();

    std::cout << cdllSorted << std::endl;

    cdllSorted.DeleteAtPosition(0);
    cdllSorted.DeleteAtPosition(4);
    cdllSorted.DeleteAtPosition(cdllSorted.countNodes() - 1);
    cdllSorted.DeleteElement(2);
    std::cout << cdllSorted << std::endl;

    cdllSorted.DeleteHead();
    cdllSorted.DeleteHead();
    //cdllSorted.DeleteElement(8);
    cdllSorted.DeleteAtPosition(0);

    std::cout << cdllSorted << std::endl;
    
    cdllSorted.Insert(0, 11);
    cdllSorted.Insert(0, 11);
    cdllSorted.Insert(0, 11);

    cdllSorted.DeleteDuplicates();
    std::cout << cdllSorted << std::endl;

    return 0;
}