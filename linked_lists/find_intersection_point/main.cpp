#include <iostream>
#include <memory>
#include <stack>
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

// This method uses two stacks to find the intersection point of two linked lists.
// We are going through the linked lists and pushing the Nodes to the stack until we reach 
// the end of each linked list. After that we are popping from two stacks and comparing the 
// addresses of the Nodes. We repeat the pop operation until the two addresses are different.
// When there is a different address, the last Node was the intersection point of two linked lists.
// Time complexity -> o(n + n + n) = o(3n) = o(n)
// Space complexity -> o(n + n + n + n) = o(4n) = o(n) -> two lists and two stacks
std::shared_ptr<LinkedList::Node> findIntersectionNode(const LinkedList::LinkedList& list1, const LinkedList::LinkedList& list2)
{
    std::stack<std::shared_ptr<LinkedList::Node>> stackList1;
    std::stack<std::shared_ptr<LinkedList::Node>> stackList2;

    std::shared_ptr<LinkedList::Node> nodeList1 = list1.getHead();
    std::shared_ptr<LinkedList::Node> nodeList2 = list2.getHead();
    
    std::shared_ptr<LinkedList::Node> intersectionNode = nullptr;

    // Rewind the linked list to the end and populate the stack
    while (nodeList1 != nullptr)
    {
        stackList1.push(nodeList1); // o(1)
        nodeList1 = nodeList1->next;
    }

    // Rewind the linked list to the end and populate the stack
    while (nodeList2 != nullptr)
    {
        stackList2.push(nodeList2); // o(1)
        nodeList2 = nodeList2->next;
    }

    if (stackList1.size() && stackList2.size()) // o(1)
    {
        while (stackList1.top() == stackList2.top()) // o(1)
        {
            intersectionNode = stackList1.top(); // o(1)
            stackList1.pop(); // o(1)
            stackList2.pop(); // o(1)
        }
    }

    return intersectionNode;
}

void printIntersectioNode(const std::shared_ptr<LinkedList::Node>& node)
{
    if (node != nullptr)
    {
        std::cout << "Intersection Node of two lists is: " << node->data << std::endl;
    }
    else
    {
        std::cout << "There is no intersection node between two lists." << std::endl;
    }
}

int main()
{
    std::cout << "*************************************************************" << std::endl;
    std::cout << "Construct Linked list 1: " << std::endl;

    constexpr unsigned int sizeOfArray = 9;
    LinkedList::LinkedList list1;

    std::shared_ptr<int[]> elementsToAdd = createDummyArray(sizeOfArray);
    list1.AddElements(sizeOfArray, elementsToAdd);

    list1.Insert(0, 22);
    list1.Insert(0, 18);
    list1.Insert(0, 56);
    list1.Insert(0, 43);
    list1.Insert(0, 33);
    list1.Insert(0, 99);
    std::cout << list1 << std::endl;
    std::cout << "The number of nodes in the linked list 1 is: " << list1.countNodes() << std::endl;

    std::cout << "*************************************************************" << std::endl;
    std::cout << "Construct Linked list 2: " << std::endl;

    LinkedList::LinkedList list2;

    list2.Insert(0, 101);
    list2.Insert(0, 13);
    list2.Insert(0, -2);
    list2.Insert(0, -4);

    std::shared_ptr<LinkedList::Node> lastNode = list2.findMaxElementAddress();
    std::shared_ptr<LinkedList::Node> commonNode = list1.findMinElementAddress();

    if (commonNode != nullptr)
    {
        for (unsigned int i = 0; i < 3; ++i)
        {
            commonNode = commonNode->next;
        }

        lastNode->next = commonNode;
    }
    
    std::cout << list2 << std::endl;
    std::cout << "The number of nodes in the linked list 2 is: " << list2.countNodes() << std::endl;

    std::cout << "*************************************************************" << std::endl;
    std::cout << "Find intersection point of two linked lists: " << std::endl;

    std::shared_ptr<LinkedList::Node> intersectionNode = findIntersectionNode(list1, list2);

    printIntersectioNode(intersectionNode);

    return 0;
}