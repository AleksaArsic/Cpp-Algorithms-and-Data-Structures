#include "CircularLinkedList.h"

namespace CircularLinkedList
{
    std::shared_ptr<Node> CircularLinkedList::getHead() const
    {
        return head;
    }

    void CircularLinkedList::AddElements(const unsigned int noOfElements, const std::shared_ptr<int[]> elementArray)
    {
        
        std::shared_ptr<Node> node = std::make_shared<Node>(elementArray[0], nullptr);
        unsigned int startIdx = 0;

        if (head == nullptr)
        {
            head = node;
            startIdx = 1;
        }
        else
        {
            node = head;
            while (node->next != head)
            {
                node = node->next;
            }
            startIdx = 0;
        }

        for(unsigned int i = startIdx; i < noOfElements; ++i)
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(elementArray[i], nullptr);
            node->next = newNode;
            node = newNode;
        }

        node->next = head;
    }

    // Time complexity -> min - o(1)
    // Time complexity -> max - o(n)
    // Space complexity -> o(1)
    void CircularLinkedList::Insert(const unsigned int position, const int x)
    {
        unsigned int nodeCount = countNodes();
        std::shared_ptr<Node> node = head;

        if (position <= nodeCount)
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr);

            if (node == nullptr)
            {
                head = newNode;
                head->next = newNode;
            }
            else
            {
                for (unsigned int i = 0; i < position; ++i)
                {
                    node = node->next;
                }

                if (position == 0U)
                {
                    while (node->next != head)
                    {
                        node = node->next;
                    }

                    node->next = newNode;
                    newNode->next = head;
                    head = newNode;
                }
                else
                {
                    newNode->next = node->next;
                    node->next = newNode;
                }
            }
            
            
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void CircularLinkedList::InsertLast(const int x)
    {
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node->next != head)
            {
                node = node->next;
            }

            std::shared_ptr<Node> newNode = std::make_shared<Node>(x, node->next);
            node->next = newNode;
        }
        else
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr);
            head = newNode;
            head->next = newNode;
        }
    }

    // Time complexity -> min - o(1)
    // Time complexity -> max - o(n)
    // Space complexity -> o(1)
    void CircularLinkedList::InsertInASortedList(const int x)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tail = nullptr;
        std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr);

        if (node == nullptr)
        {
            head = newNode;
            head->next = newNode;
        }
        else
        {
            do
            {
                tail = node;
                node = node->next;
            } while (node->data < x && node != head);

            // if tail == head -> position == 0
            // if node == head -> position == end
            // if tail != head && node != head -> position in between
            if (tail == head)
            {
                while (node->next != head)
                {
                    node = node->next;
                }

                newNode->next = tail;
                node->next = newNode;
                head = newNode;
            }
            else
            {
                newNode->next = node;
                tail->next = newNode;
            }
        }       
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] unsigned int CircularLinkedList::countNodes() const
    {
        unsigned int nodeCount = 1;
        std::shared_ptr<Node> node = head;

        if (node != nullptr)
        {
            while (node->next != head)
            {
                nodeCount++;
                node = node->next;
            }

            return nodeCount;
        }

        return 0U;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void CircularLinkedList::DeleteElement(const int x)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tail = nullptr;
        
        if (node != nullptr)
        {
            while (node->next != head && node->data != x)
            {
                tail = node;
                node = node->next;
            }

            if (node == head)
            {
                node->next = nullptr;
                tail = nullptr;
                head = nullptr;
            }
            else
            {
                if (node->data == x)
                {
                    tail->next = node->next;
                    node->next = nullptr;
                }
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void CircularLinkedList::DeleteAtPosition(const int position)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tail = nullptr;
        unsigned int nodeCount = countNodes();

        if (position < nodeCount)
        {
            if (position == 0)
            {
                while (node->next != head)
                {
                    tail = node;
                    node = node->next;
                }

                tail = node;
                node = node->next;
            }
            else
            {
                for (unsigned int i = 0; i < position; ++i)
                {
                    tail = node;
                    node = node->next;
                }    
            }

            tail->next = node->next;

            if (node == head)
            {
                head = node->next;
            }
            node->next = nullptr;

            if (tail == head)
            {
                head.reset();
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void CircularLinkedList::DeleteDuplicates()
    {
        std::shared_ptr<Node> node = head->next;
        std::shared_ptr<Node> tail = head;

        while (node != head)
        {
            if (node->data == tail->data)
            {
                tail->next = node->next;
                node->next = nullptr;
                // No need to deallocate, we are using smart pointers
                node = tail->next;
            }
            else
            {
                tail = tail->next; // tail = node;
                node = node->next;
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void CircularLinkedList::DeleteHead()
    {
        std::shared_ptr<Node> node = head;

        if (head != nullptr)
        {
            while (node->next != head)
            {
                node = node->next;
            }

            node->next = head->next;
            head->next.reset();
            head.reset();
            head = node->next;
        }
    }

    // Recursive display in reverse
    // Time complexity -> o(1)
    // Space complexity -> o(n + 1) -> o(n) 
    void CircularLinkedList::DisplayInReverse(const std::shared_ptr<Node>& node) const
    {
        static bool headWasEqualToNode = false;

        if (node != nullptr)
        {
            if (headWasEqualToNode == false || node != head)
            {
                headWasEqualToNode = true;
                DisplayInReverse(node->next);
                std::cout << node->data << " ";
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const CircularLinkedList& cll)
    {
        std::shared_ptr<Node> node = cll.head;
        os << "Circular linked list elements: " << std::endl;
        
        if (node != nullptr)
        {
            os << node->data << " ";
            node = node->next;

            while (node != cll.head)
            {
                os << node->data << " ";
                node = node->next;
            }
        }

        

        return os;
    }
}