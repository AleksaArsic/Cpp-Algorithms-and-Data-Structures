#include <iostream>
#include <memory>
#include "LinkedList.h"

std::shared_ptr<int[]> createDummyArray(const unsigned int sizeOfArray)
{
    std::shared_ptr<int[]> elementsToAdd = std::make_shared<int[]>(sizeOfArray);

    for (int i = 0; i < sizeOfArray; ++i)
    {
        elementsToAdd[i] = i;
    }

    return elementsToAdd;
}

void printMiddleNode(std::shared_ptr<LinkedList::Node> node)
{
    if (node != nullptr)
    {
        std::cout << "Middle node of linked list is with data value: " << node->data << std::endl;
    }
    else
    {
        std::cout << "List is empty." << std::endl;
    }
}

int main()
{
    constexpr unsigned int sizeOfArray = 9;

    LinkedList::LinkedList list;

    std::shared_ptr<int[]> elementsToAdd = createDummyArray(sizeOfArray);
    list.AddElements(sizeOfArray, elementsToAdd);

    list.Insert(0, 22);
    list.Insert(0, 18);
    list.Insert(0, 56);
    list.Insert(0, 43);
    list.Insert(0, 33);
    list.Insert(0, 99);

    std::cout << list << std::endl;
    std::cout << "The number of nodes in the linked list is: " << list.countNodes() << std::endl;

    std::shared_ptr<LinkedList::Node> middleNode = list.findMiddleNodeSimple();

    printMiddleNode(list.findMiddleNodeSimple());
    printMiddleNode(list.findMiddleNode());
    printMiddleNode(list.findMiddleNodeAdvanced());

    return 0;
}