#include "CircularDoublyLinkedList.hpp"

namespace CircularDoublyLinkedList
{
    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    std::shared_ptr<Node> CircularDoublyLinkedList::getHead() const
    {
        return head;
    }
    // Time Complexity -> o(1)
    // Space Complexity -> o(1)    
    std::shared_ptr<Node>& CircularDoublyLinkedList::getHeadRef()
    {
        return head;
    }
    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::AddElements(const unsigned int noOfElements, const std::shared_ptr<int[]> elementArray)
    {
        unsigned int position = 0;

        if (head == nullptr)
        {
            head = std::make_shared<Node>(elementArray[0], nullptr, nullptr);
            head->next = head;
            head->previous = head;
            position = 1;
        }

        std::shared_ptr<Node> node = head;

        while (node->next != head)
        {
            node = node->next;
        }

        for (unsigned int i = position; i < noOfElements; ++i)
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(elementArray[i], head, node);
            node->next = newNode;

            node = node->next;
        }

        head->previous = node;
    }

    // Time Complexity -> min -> o(1)
    //                 -> max -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::Insert(const unsigned int position, const int x)
    {
        std::shared_ptr<Node> node = head;
        unsigned int nodeCount = countNodes();

        if (node == nullptr)
        {
            head = std::make_shared<Node>(x, nullptr, nullptr);
            head->next = head;
            head->previous = head;
        }
        else
        {
            if (node != nullptr && position <= nodeCount)
            {
                for (unsigned int i = 0; i < position; ++i)
                {
                    node = node->next;
                }

                std::shared_ptr<Node> newNode = std::make_shared<Node>(x, node, node->previous);
                node->previous->next = newNode;
                node->previous = newNode;

                if (position == 0U)
                {
                    head = newNode;
                }
            }
        }
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::InsertLast(const int x)
    {
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node->next != head)
            {
                node = node->next;
            }

            std::shared_ptr<Node> newNode = std::make_shared<Node>(x, node->next, node);
            node->next = newNode;
        }
    }

    // Time Complexity -> min -> o(1)
    //                 -> max -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::InsertInASortedList(const int x)
    {
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node->next != head && x > node->data)
            {
                node = node->next;
            }

            std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr, nullptr);
            
            if (node == head)
            {
                newNode->next = node;
                newNode->previous = node->previous;
                node->previous = newNode;
                newNode->previous->next = newNode;

                head = newNode;
            }
            else
            {
                newNode->next = node->next;
                node->next = newNode;
                newNode->previous = node;
                newNode->next->previous = newNode;
            }
        }

    }

    // Time Complexity -> min -> o(1)
    //                 -> max -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::DeleteElement(const int x)
    {
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node->next != head && node->data != x)
            {
                node = node->next;
            }

            if (node->data == x)
            {
                std::shared_ptr<Node> nodeToDelete = node;
                node = node->previous;

                node->next = nodeToDelete->next;
                node->next->previous = nodeToDelete->previous;

                if (countNodes() == 1U)
                {
                    head.reset();
                }
                
                nodeToDelete->next.reset(); // need to check if this is needed.
                nodeToDelete->previous.reset(); // need to check if this is needed.
                nodeToDelete.reset(); // need to check if this is needed.

            }
        }
    }

    // Time Complexity -> min -> o(1)
    //                 -> max -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::DeleteAtPosition(const int position)
    {
        std::shared_ptr<Node> node = head;
        unsigned int nodeCount = countNodes();

        if (node != nullptr && position < nodeCount)
        {
            for (unsigned int i = 0; i < position; ++i)
            {
                node = node->next;
            }

            std::shared_ptr<Node> nodeToDelete = node;
            node = node->previous;

            node->next = nodeToDelete->next;
            node->next->previous = nodeToDelete->previous;

            nodeToDelete->next.reset(); // need to check if this is needed.
            nodeToDelete->previous.reset(); // need to check if this is needed.
            nodeToDelete.reset(); // need to check if this is needed.

            if (position == 0U)
            {
                head.reset();
                head = node->next;
            }
        }
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::DeleteDuplicates()
    {
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node->next != head)
            {
                if (node->data == node->next->data)
                {
                    std::shared_ptr<Node> duplicate = node->next;

                    node->next = duplicate->next;
                    node->next->previous = node;

                    duplicate->next.reset(); // need to check if this is needed.
                    duplicate->previous.reset(); // need to check if this is needed.
                    duplicate.reset(); // need to check if this is needed.
                }
                else
                {
                    node = node->next;
                }
            }
        }
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::DeleteHead()
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> nextNode = nullptr;

        if (node != nullptr)
        {
            node->previous->next = node->next;
            node->next->previous = node->previous;
            nextNode = node->next;
            node->next.reset(); // need to check if this is needed.
            node->previous.reset(); // need to check if this is needed.
            node.reset(); // resets only node, while the head will still be valid
            head.reset(); // resets head and makes it empty
            head = nextNode;
        }
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    void CircularDoublyLinkedList::DisplayInReverse() const
    {
        std::cout << "Circular Doubly Linked List in Reverse order: " << std::endl;

        if (head != nullptr)
        {
            std::shared_ptr<Node> node = head->previous;
            do
            {
                std::cout << node->data << " ";
                node = node->previous;
            } while (node != head->previous);
        }
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    [[nodiscard]] unsigned int CircularDoublyLinkedList::countNodes() const
    {
        std::shared_ptr<Node> node = head;
        unsigned int count = 0;

        if (node != nullptr)
        {
            do
            {
                count++;
                node = node->next;
            } while (node != head);
        }

        return count;
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const CircularDoublyLinkedList& cdll)
    {
        std::shared_ptr<Node> node = cdll.head;
        os << "Circular Doubly Linked List: " << std::endl;

        if (cdll.head != nullptr)
        {
            do
            {
                os << node->data << " ";
                node = node->next;
            } while (node != cdll.head);
        }

        return os;
    }

}