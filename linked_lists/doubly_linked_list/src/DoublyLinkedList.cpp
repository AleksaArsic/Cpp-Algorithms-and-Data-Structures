#include "DoublyLinkedList.hpp"

namespace DoublyLinkedList
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    std::shared_ptr<Node> DoublyLinkedList::getHead() const
    {
        return head;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::AddElements(const unsigned int noOfElements, std::shared_ptr<int[]> elementArray)
    {

        if (head == nullptr)
        {
            head = std::make_shared<Node>(elementArray[0], nullptr, nullptr);
        }
        
        std::shared_ptr<Node> node = head;

        for (unsigned int i = 1; i < noOfElements; ++i)
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(elementArray[i], nullptr, nullptr);

            newNode->previous = node;
            node->next = newNode;
            node = node->next;
        }
        
    }

    // Time complexity -> min o(1)
    //                 -> max o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::Insert(const unsigned int position, const int x)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr, nullptr);

        if (position == 0)
        {
            if (head != nullptr)
            {
                node->previous = newNode;
                newNode->next = node;
            }

            head = newNode;
        }
        else
        {
            if (position < countNodes())
            {
                for (unsigned int i = 0; i < position; ++i)
                {
                    node = node->next;
                }

                newNode->next = node->next;
                newNode->previous = node;

                if (node->next != nullptr)
                {
                    node->next->previous = newNode;
                }
                node->next = newNode;
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::InsertLast(const int x)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr, nullptr);

        if (node == nullptr)
        {
            node = newNode;
            head = node;
        }
        else
        {
            while (node->next != nullptr)
            {
                node = node->next;
            }

            node->next = newNode;
            newNode->previous = node;
        }
        
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::InsertInASortedList(const int x)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr, nullptr);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {

            while (node != nullptr && newNode->data > node->next->data)
            {
                node = node->next;
            }

            if (node == head)
            {
                node->previous = newNode;
                newNode->next = node;
                head = newNode;
            }
            else
            {
                node->next->previous = newNode;
                newNode->next = node->next;
                node->next = newNode;
                newNode->previous = node;
            }
        }
    }

    // Time complexity -> min o(1)
    //                 -> max o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::DeleteElement(const int x)
    {
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node != nullptr && node->data != x)
            {
                node = node->next;
            }

            if (node == head)
            {
                if (node->next != nullptr)
                {
                    node = node->next;
                    node->previous->next = nullptr;
                    node->previous = nullptr;
                    head = node;
                }
                else
                {
                    head.reset();
                }
            }
            else
            {
                node->previous->next = node->next;

                if (node->next != nullptr)
                {
                    node->next->previous = node->previous;
                }
            }

            
        }
    }

    // Time complexity -> min o(1)
    //                 -> max o(1)
    // Space complexity -> o(1)
    void DoublyLinkedList::DeleteAtPosition(const unsigned int position)
    {
        std::shared_ptr<Node> node = head;
        unsigned int nodeCount = countNodes();

        if (node != nullptr && position < nodeCount)
        {
            for (unsigned int i = 0; i < position; ++i)
            {
                node = node->next;
            }

            if (node == head)
            {
                head = node->next;
            }

            if (node->previous != nullptr)
            {
                node->previous->next = node->next;
                node->previous = nullptr;
            }

            if (node->next != nullptr)
            {
                node->next->previous = node->previous;
                node->next = nullptr;
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::DeleteDuplicates()
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> nodeToDelete = nullptr;

        if (node != nullptr)
        {
            while (node->next != nullptr)
            {
                if (node->data == node->next->data)
                {
                    nodeToDelete = node->next;
                    node->next = node->next->next;
                    if (node->next != nullptr)
                    {
                        node->next->previous = node;
                    }
                    nodeToDelete->next = nullptr;
                    nodeToDelete->previous = nullptr;
                    nodeToDelete.reset(); // Need to check if this is needed
                }
                else
                {
                    node = node->next;
                }
            }
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void DoublyLinkedList::ReverseElements()
    {
        // In real use-cases we should be avoiding copying the data elements of the 
        // nodes in the linked lists because there's a chance we can have a complex 
        // data type(s) that are expensive to copy
        std::cout << "NOT IMPLEMENTED." << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::ReverseNodes()
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tempNode = head;

        if (node != nullptr)
        {
            while (node != nullptr)
            {
                tempNode = node->next;
                node->next = node->previous;
                node->previous = tempNode;

                if (node->previous == nullptr)
                {
                    head = node;
                }

                node = node->previous;
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] unsigned int DoublyLinkedList::countNodes() const
    {
        unsigned int count = 0;
        std::shared_ptr<Node> node = head;

        while (node != nullptr)
        {
            count++;
            node = node->next;
        }
        
        return count;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void DoublyLinkedList::DisplayInReverse() const
    {
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node->next != nullptr)
            {
                node = node->next;
            }

            while (node != nullptr)
            {
                std::cout << node->data << " ";
                node = node->previous;
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& dll)
    {
        std::shared_ptr<Node> node = dll.getHead();

        os << "Doubly Linked List: " << std::endl;

        while(node != nullptr)
        {
            os << node->data << " ";

            node = node->next;
        }

        return os;
    }
}