#include <iostream>
#include <memory>
#include "CircularLinkedList.h"

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

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Circular Linked list" << std::endl;
    constexpr int dummyArraySize = 10;
    CircularLinkedList::CircularLinkedList circularLinkedList;

    std::shared_ptr<int[]> dummyArray = createDummyArray(dummyArraySize);

    //circularLinkedList.AddElements(dummyArraySize, dummyArray);
    std::cout << circularLinkedList << std::endl;
    //circularLinkedList.AddElements(4, std::shared_ptr<int[]>(new int[]{11, 13, 14, 15}));
    std::cout << circularLinkedList << std::endl;

    std::cout << "Display linked list in reverse:" << std::endl;
    circularLinkedList.DisplayInReverse(circularLinkedList.getHead());
    std::cout << std::endl;

    std::cout << "Number of Nodes in Circular Linked List: " << circularLinkedList.countNodes() << std::endl;
    circularLinkedList.Insert(0, 13);
    circularLinkedList.Insert(0, 12);
    circularLinkedList.Insert(0, 11);
    circularLinkedList.Insert(0, 10);
    std::cout << "Insert at index 9 : \n" << circularLinkedList << std::endl;
    //circularLinkedList.InsertLast(2);
    std::cout << "Insert last : \n" << circularLinkedList << std::endl;
    circularLinkedList.InsertInASortedList(17);
    circularLinkedList.InsertInASortedList(15);
    circularLinkedList.InsertInASortedList(15);
    circularLinkedList.InsertInASortedList(15);
    circularLinkedList.InsertInASortedList(22);
    circularLinkedList.InsertInASortedList(22);
    circularLinkedList.InsertInASortedList(22);
    circularLinkedList.InsertInASortedList(-1);
    circularLinkedList.InsertInASortedList(-1);
    std::cout << "Insert in a sorted list : \n" << circularLinkedList << std::endl;
    std::cout << "Number of Nodes in Circular Linked List: " << circularLinkedList.countNodes() << std::endl;
    std::cout << "Delete duplicates from Circular Linked List: " << std::endl;
    std::cout << circularLinkedList << std::endl;
    circularLinkedList.DeleteDuplicates();
    std::cout << circularLinkedList << std::endl;
    std::cout << "Delete from Circular Linked List: " << std::endl;
    circularLinkedList.DeleteHead();
    std::cout << circularLinkedList << std::endl;
    circularLinkedList.DeleteElement(13);
    std::cout << circularLinkedList << std::endl;
    circularLinkedList.DeleteAtPosition(5);
    std::cout << circularLinkedList << std::endl;
    circularLinkedList.DeleteAtPosition(15);
    std::cout << circularLinkedList << std::endl;
    circularLinkedList.DeleteAtPosition(0);
    std::cout << circularLinkedList << std::endl;
    circularLinkedList.DeleteAtPosition(circularLinkedList.countNodes() - 1);
    std::cout << circularLinkedList << std::endl;

    circularLinkedList.DeleteAtPosition(0);
    circularLinkedList.DeleteAtPosition(0);
    circularLinkedList.DeleteAtPosition(0);
    //circularLinkedList.DeleteHead();
    //circularLinkedList.DeleteElement(15);
    std::cout << circularLinkedList << std::endl;

    return 0;
}