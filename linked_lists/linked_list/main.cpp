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

int main()
{
    constexpr unsigned int sizeOfArray = 9;

    LinkedList::LinkedList list;

    std::shared_ptr<int[]> elementsToAdd = createDummyArray(sizeOfArray);
    list.AddElements(sizeOfArray, elementsToAdd);

    std::shared_ptr<LinkedList::Node> head = list.getHead();

    if (head == nullptr)
    {
        std::cout << "Linked list is empty. Head points to nullptr." << std::endl;
    }
    else
    {
        std::cout << "Linked list has elements." << std::endl;
    }

    std::cout << list << std::endl;
    list.DisplayInReverse(head);
    std::cout << std::endl;

    std::cout << "Number of nodes in the Linked list: " << list.countNodes() << std::endl;
    std::cout << "Sum of all elements in the Linked list: " << list.sumOfAllElements() << std::endl;
    std::cout << "Maximal element in the Linked list: " << list.findMaxElement() << std::endl;
    std::cout << "Maximal element in the Linked list [recursively]: " << list.rFindMaxElement(head) << std::endl;
    std::cout << "Maximal element address in the Linked list: " << list.findMaxElementAddress() << std::endl;
    std::cout << "Minimal element in the Linked list: " << list.findMinElement() << std::endl;
    std::cout << "Minimal element in the Linked list [recursively]: " << list.rFindMinElement(head) << std::endl;
    std::cout << "Minimal element address in the Linked list: " << list.findMinElementAddress() << std::endl;
    std::cout << "Element: " << 5L << " is found in the Linked list: " << list.findElement(5L) << std::endl;
    std::cout << "Element: " << -5L << " is found in the Linked list: " << list.findElement(-5L) << std::endl;
    std::cout << "Element: " << 5L << " is found in the Linked list [recursively]: " << list.rFindElement(head, 5L) << std::endl;
    std::cout << "Element: " << -5L << " is found in the Linked list [recursively]: " << list.rFindElement(head, -5L) << std::endl;
    std::cout << "Element: " << 5L << " is found in the Linked list [optimized]: " << list.findElementOptimized(5L) << std::endl;
    std::cout << "Element: " << -5L << " is found in the Linked list [optimized]: " << list.findElementOptimized(-5L) << std::endl;
    std::cout << list << std::endl;
    std::cout << "Element: " << 5L << " is found in the Linked list [optimized]: " << list.findElementOptimized(8L) << std::endl;
    std::cout << list << std::endl;
    std::cout << "Element: " << 5L << " is found in the Linked list [optimized]: " << list.findElementOptimized(5L) << std::endl;
    std::cout << list << std::endl;
    std::cout << "Insert in front of linked list: " << 33L << std::endl;
    list.Insert(0L, 33L);
    std::cout << list << std::endl;
    std::cout << "Insert element: " << 55L << " at position: " << 4L << std::endl;
    list.Insert(4L, 55L);
    std::cout << list << std::endl;

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Create Linked List by using Insert() at the begining of the list" << std::endl;
    // Create Linked List by using Insert() at the begining of the list
    LinkedList::LinkedList list2;

    for (int i = 9; i >= 0; --i)
    {
        list2.Insert(0, i);
    }

    std::cout << list2 << std::endl;

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Create Linked List by using Insert() at the end of the list" << std::endl;
    // Create Linked List by using Insert() at the end of the list
    LinkedList::LinkedList list3;

    for (int i = 9; i >= 0; --i)
    {
        list3.Insert(list3.countNodes(), i);
    }

    std::cout << list3 << std::endl;

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Create Sorted Linked List" << std::endl;
    // Create Sorted Linked List
    LinkedList::LinkedList list4;
    int j = 3;

    for (int i = 0; i < 10; ++i)
    {
        list4.Insert(list4.countNodes(), i + j);

        if (i % 2 == 0)
        {
            j+=3;
        }
    }

    std::cout << list4 << std::endl;

    std::cout << "InsertInASortedList" << std::endl;
    list4.InsertInASortedList(15);
    list4.InsertInASortedList(30);
    list4.InsertInASortedList(-2);

    std::cout << list4 << std::endl;

    std::cout << "DeleteElement" << std::endl;
    list4.DeleteElement(15);
    list4.DeleteElement(30);
    list4.DeleteElement(-2);

    std::cout << list4 << std::endl;

    std::cout << "DeleteAtPosition" << std::endl;
    list4.DeleteAtPosition(0);
    list4.DeleteAtPosition(list4.countNodes() - 1);
    list4.DeleteAtPosition(3);
    list4.DeleteAtPosition(30);

    std::cout << list4 << std::endl;

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Check if lists are sorted in ascending order" << std::endl;

    std::cout << list << std::endl;
    if (list.checkIfSortedAscending())
    {
        std::cout << "List is sorted in ascending order" << std::endl;
    }
    else
    {
        std::cout << "List is not sorted in ascending order" << std::endl;
    }

    std::cout << list4 << std::endl;
    if (list4.checkIfSortedAscending())
    {
        std::cout << "List is sorted in ascending order" << std::endl;
    }
    else
    {
        std::cout << "List is not sorted in ascending order" << std::endl;
    }

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Check if lists are sorted in descending order" << std::endl;

    std::cout << list << std::endl;
    if (list.checkIfSortedDescending())
    {
        std::cout << "List is sorted in descending order" << std::endl;
    }
    else
    {
        std::cout << "List is not sorted in descending order" << std::endl;
    }

    std::cout << list3 << std::endl;
    if (list3.checkIfSortedDescending())
    {
        std::cout << "List is sorted in descending order" << std::endl;
    }
    else
    {
        std::cout << "List is not sorted in descending order" << std::endl;
    }

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Delete duplicate elements from linked list" << std::endl;

    LinkedList::LinkedList list5;

    std::shared_ptr<int[]> duplicateElementsArray(new int[]{3, 7, 7, 11, 12, 12, 12 });
    list5.AddElements(7, duplicateElementsArray);

    std::cout << list5 << std::endl;
    list5.DeleteDuplicates();
    std::cout << list5 << std::endl;

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Reverse the elements/nodes of the linked list" << std::endl;

    std::cout << list4 << std::endl;
    list4.ReverseElements();
    std::cout << list4 << std::endl;
    list4.ReverseNodes();
    std::cout << list4 << std::endl;
    list4.rReverseNodes(nullptr, list4.getHead());
    std::cout << list4 << std::endl;

    std::cout << "******************************************************************" << std::endl;
    std::cout << "Merge two lists" << std::endl;

    LinkedList::LinkedList list6;
    LinkedList::LinkedList list7;

    std::shared_ptr<int[]> evenNumberArray(new int[] { 2, 4, 6, 8, 10 });
    list6.AddElements(5, evenNumberArray);

    std::shared_ptr<int[]> oddNumberArray(new int[] { 1, 3, 5, 7, 9 });
    list7.AddElements(5, oddNumberArray);

    std::cout << list6 << std::endl;
    std::cout << list7 << std::endl;
    list6.MergeLinkedList(list7);
    std::cout << list6 << std::endl;


    std::cout << "******************************************************************" << std::endl;
    std::cout << "Check if linked list has a loop" << std::endl;
    LinkedList::LinkedList list8;

    // Create artificial loop
    list8.AddElements(5, evenNumberArray);
    list8.findMaxElementAddress()->next = list8.getHead();

    std::cout << list6 << std::endl;

    if (list6.checkIfLoop())
    {
        std::cout << "List has a loop" << std::endl;
    }
    else
    {
        std::cout << "List does not have a loop" << std::endl;
    }

    if (list8.checkIfLoop())
    {
        std::cout << "List has a loop" << std::endl;
    }
    else
    {
        std::cout << "List does not have a loop" << std::endl;
    }

    // Check deallocation features and element deletion
    std::cout << "******************************************************************" << std::endl;
    std::cout << "Check deallocation features and element deletion" << std::endl;
    LinkedList::LinkedList list9;

    list9.AddElements(5, evenNumberArray);

    std::cout << list9 << std::endl;
    list9.DeleteAtPosition(0);
    list9.DeleteAtPosition(0);
    list9.DeleteAtPosition(0);
    list9.DeleteAtPosition(0);
    //list9.DeleteAtPosition(0);
    list9.DeleteElement(10);
    std::cout << list9 << std::endl;

    return 0;
}