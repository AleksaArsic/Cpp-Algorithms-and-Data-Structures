#include <iostream>
#include "DoublyLinkedList.hpp"

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
    constexpr unsigned int sizeOfArray = 10;
    DoublyLinkedList::DoublyLinkedList dll;

    //dll.AddElements(sizeOfArray, createDummyArray(sizeOfArray));

    std::cout << dll << std::endl;

    std::cout << "Number of Nodes in Circular Linked List: " << dll.countNodes() << std::endl;
    dll.Insert(0, 13);
    dll.Insert(0, 12);
    dll.Insert(0, 11);
    dll.Insert(0, 11);
    dll.Insert(0, 10);
    std::cout << dll << std::endl;
    std::cout << "Number of Nodes in Circular Linked List: " << dll.countNodes() << std::endl;
    dll.Insert(3, 33);
    dll.Insert(4, 44);
    std::cout << dll << std::endl;
    dll.InsertLast(55);
    std::cout << "Insert last : \n" << dll << std::endl;
    std::cout << dll << std::endl;
    std::cout << "Insert in a sorted list: " << std::endl;
    dll.InsertInASortedList(17);
    dll.InsertInASortedList(15);
    dll.InsertInASortedList(15);
    dll.InsertInASortedList(15);
    dll.InsertInASortedList(22);
    dll.InsertInASortedList(22);
    dll.InsertInASortedList(35);
    dll.InsertInASortedList(-1);
    std::cout << dll << std::endl;
    std::cout << "Display in reverse order: " << std::endl;
    dll.DisplayInReverse();
    std::cout << std::endl;
    //dll.DeleteElement(15);
    //dll.DeleteElement(22);
    dll.DeleteElement(55);
    dll.DeleteElement(-1);
    dll.DeleteAtPosition(65);
    dll.DeleteAtPosition(0);
    dll.DeleteAtPosition(2);
    dll.DeleteAtPosition(dll.countNodes() - 1);
    dll.DeleteDuplicates();

    std::cout << dll << std::endl;

    dll.ReverseNodes();

    std::cout << "Reverse nodes: " << std::endl;
    std::cout << dll << std::endl;

    for (unsigned int i = 0; i < 6; ++i)
    {
        dll.DeleteAtPosition(0);
    }
    dll.DeleteElement(11);

    dll.Insert(0, 11);
    dll.Insert(0, 11);
    dll.Insert(0, 11);

    dll.DeleteDuplicates();

    std::cout << dll << std::endl;

    return 0;
}