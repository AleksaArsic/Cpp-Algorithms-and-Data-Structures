#include "LinkedList.h"
#include <cmath>
#include <stack>

namespace LinkedList
{
    // Time complexity -> o(1)
    std::shared_ptr<Node> LinkedList::getHead() const
    {
        return head;
    }

    // Time complexity -> o(n)
    void LinkedList::AddElements(const unsigned int noOfElements, std::shared_ptr<int[]> elements)
    {
        if (head == nullptr)
        {
            head = std::make_shared<Node>(elements[0], nullptr);
        }

        std::shared_ptr<Node> node = head;

        while (node->next != nullptr)
        {
            node = node->next;
        }

        for (unsigned int i = 1; i < noOfElements; ++i)
        {
            std::shared_ptr<Node> newElement = std::make_shared<Node>(elements[i], nullptr);

            node->next = newElement;
            node = node->next;
        }
        
    }

    // Time complexity -> best case - o(1)
    // Time complexity -> worst case - o(n)
    // Space complexity -> o(1)
    void LinkedList::Insert(const unsigned int position, const int x)
    {
        std::shared_ptr<Node> node;

        if (position > countNodes())
        {
            return;
        }
        else
        {
            if (position == 0L)
            {
                node = std::make_shared<Node>(x, head);
                head = node;
            }
            else
            {
                node = head;

                for (unsigned int i = 0; i < position - 1 && node != nullptr; ++i)
                {
                    node = node->next;
                }

                if (node != nullptr)
                {
                    std::shared_ptr<Node> newNode = std::make_shared<Node>(x, node->next);
                    node->next = newNode;
                }
            }
        }
    }

    void LinkedList::InsertLast(const int x)
    {
        // Can be done by maintaing the head and tail pointers
        // Head is the first Node in the list
        // Tail is the last Node in the list
        // We always insert at the last->next and 
        // maintain a valid head and tail pointers within the class.
        // This will result in the constant time complexity because
        // we do not need to traverse the list.
        std::cout << "[InsertLast] NOT IMPLEMENTED." << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void LinkedList::InsertInASortedList(const int x)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tail = nullptr;

        std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            while (node != nullptr && x > node->data)
            {
                tail = node;
                node = node->next;
            }

            if (tail == nullptr)
            {
                newNode->next = head;
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
    void LinkedList::DeleteElement(const int x)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tail = nullptr;

        if (node == nullptr)
        {
            return;
        }
        else
        {
            while (node != nullptr && x != node->data)
            {
                tail = node;
                node = node->next;
            }

            if (node == nullptr)
            {
                return;
            }
            else
            {
                // no need to deallocate, we are using smart pointers
                (tail == nullptr) ? head = node->next : tail->next = node->next;
            }
        }
        
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void LinkedList::DeleteAtPosition(const int position)
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tail = nullptr;
        
        if (node == nullptr || position >= countNodes() || position < 0)
        {
            return;
        }
        else
        {
            for (unsigned int i = 0; i < position; ++i)
            {
                tail = node;
                node = node->next;
            }

            if (node == nullptr)
            {
                return;
            }
            else
            {
                // no need to deallocate, we are using smart pointers
                (tail == nullptr) ? head = node->next : tail->next = node->next;
            }
        }

    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void LinkedList::DeleteDuplicates()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            std::shared_ptr<Node> node = head->next;
            std::shared_ptr<Node> tail = head;

            while (node != nullptr)
            {
                if (tail->data == node->data)
                {
                    tail->next = node->next;
                    // no need to deallocate, we are using smart pointers
                    node = tail->next;
                }
                else
                {
                    tail = tail->next; // tail = node;
                    node = node->next;
                }
            }
        }
    }

    // For demonstrating purposes only
    // In real use-cases we should be avoiding copying the data elements of the 
    // nodes in the linked lists because there's a chance we can have a complex 
    // data type(s) that are expensive to copy
    // This method uses auxilary array for storing the data elements of nodes
    // Time complexity -> o(3n) -> o(n)
    // Space complexity -> o(1)
    void LinkedList::ReverseElements()
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<int[]> auxArray = std::make_shared<int[]>(countNodes());

        unsigned int i = 0;
        while (node != nullptr)
        {
            auxArray[i++] = node->data;
            node = node->next;
        }

        node = head;
        i = i - 1;

        while (node != nullptr)
        {
            node->data = auxArray[i--];
            node = node->next;
        }
    }

    // Uses sliding pointer method of three pointers to 
    // reverse the nodes of the linked list.
    // Time complexity -> o(n)
    // Space complexity -> o(1)
    void LinkedList::ReverseNodes()
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> middle = nullptr;
        std::shared_ptr<Node> tail = nullptr;

        while (node != nullptr)
        {
            tail = middle;
            middle = node;
            node = node->next;
            middle->next = tail;
        }
        
        head = middle;
    }

    // Recursevly reverse the nodes of the linked list
    // Time complexity -> o(1)
    // Space complexity -> o(n)
    void LinkedList::rReverseNodes(std::shared_ptr<Node> tail, std::shared_ptr<Node> node)
    {
        if (node != nullptr)
        {
            rReverseNodes(node, node->next);
            node->next = tail;
        }
        else
        {
            head = tail;
        }
    }

    // Merge Linked List linkedList into the existing Linked List.
    // Both linked lists should be sorted.
    // Resulting linked list is sorted.
    void LinkedList::MergeLinkedList(LinkedList& linkedList)
    {
        std::shared_ptr<Node> first = head;
        std::shared_ptr<Node> second = linkedList.getHead();
        std::shared_ptr<Node> last = nullptr;

        if (first != nullptr && second != nullptr)
        {
            if (first->data < second->data)
            {
                last = first;
                first = first->next;
                last->next = nullptr;
            }
            else
            {
                last = second;
                second = second->next;
                last->next = nullptr;
            }

            head = last;
        }
        else
        {
            return;
        }


        while (first != nullptr && second != nullptr)
        {
            if (first->data < second->data)
            {
                last->next = first;
                last = first;
                first = first->next;
                last->next = nullptr;
            }
            else
            {
                last->next = second;
                last = second;
                second = second->next;
                last->next = nullptr;
            }
        }

        if (first != nullptr)
        {
            last->next = first;
        }

        if (second != nullptr)
        {
            last->next = second;
        }

    }

    // Time complexity -> o(n)
    // Space complexity -> o(n) -> n + 1 calls -> + 1 for nullptr at the end of the list
    void LinkedList::DisplayInReverse(std::shared_ptr<Node> node) const
    {
        if (node != nullptr)
        {
            DisplayInReverse(node->next);
            std::cout << node->data << " ";
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] unsigned int LinkedList::countNodes() const
    {
        unsigned int cnt = 0;
        std::shared_ptr<Node> node = head;

        while (node != nullptr)
        {
            cnt++;
            node = node->next;
        }

        return cnt;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] int LinkedList::sumOfAllElements() const
    {
        int sumOfElements = 0;
        std::shared_ptr<Node> node = head;

        while (node != nullptr)
        {
            sumOfElements += node->data;
            node = node->next;
        }

        return sumOfElements;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] int LinkedList::findMaxElement() const
    {
        int maxElement = 0;
        std::shared_ptr<Node> node = head;

        while (node != nullptr)
        {
            if (node->data >= maxElement)
            {
                maxElement = node->data;
            }

            node = node->next;
        }

        return maxElement;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(n) -> n + 1 calls
    [[nodiscard]] int LinkedList::rFindMaxElement(const std::shared_ptr<Node> node) const
    {
        if (node == nullptr)
        {
            return INT_MIN;
        }
        else
        {
            int x = rFindMaxElement(node->next);

            return x <= node->data ? node->data : x;
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<Node> LinkedList::findMaxElementAddress() const
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> maxNode = head;

        while (node != nullptr)
        {
            if (node->data >= maxNode->data)
            {
                maxNode = node;
            }

            node = node->next;
        }

        return maxNode;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] int LinkedList::findMinElement() const
    {
        std::shared_ptr<Node> node = head;
        int minElement = node->data;

        while (node != nullptr)
        {
            if (node->data <= minElement)
            {
                minElement = node->data;
            }

            node = node->next;
        }

        return minElement;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(n) -> n + 1 calls
    [[nodiscard]] int LinkedList::rFindMinElement(const std::shared_ptr<Node> node) const
    {
        if (node == nullptr)
        {
            return INT_MAX;
        }
        else
        {
            int x = rFindMinElement(node->next);

            return x <= node->data ? x : node->data;
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<Node> LinkedList::findMinElementAddress() const
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> minNode = head;

        while (node != nullptr)
        {
            if (node->data <= minNode->data)
            {
                minNode = node;
            }

            node = node->next;
        }

        return minNode;
    }

    // Linear search
    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] bool LinkedList::findElement(const int x) const
    {
        std::shared_ptr<Node> node = head;

        while(node != nullptr)
        {
            if(node->data == x)
            {
                return true;
            }

            node = node->next;
        }

        return false;
    }

    // Linear search
    // Time complexity -> o(n)
    // Space complexity -> o(n)
    [[nodiscard]] bool LinkedList::rFindElement(std::shared_ptr<Node> node, const int x) const
    {
        if (node == nullptr)
        {
            return false;
        }
        else
        {
            return node->data == x ? true : rFindElement(node->next, x);
        }
    }

    // Optimized Linear Search
    // Optimization is done by Move-to-Head method,
    // where the found element is moved to the front of the linked list.
    // If we search it again it will be the first element in the list
    // Time complexity -> worst case o(n)
    // Time complexity -> best case o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool LinkedList::findElementOptimized(const int x)
    {
        std::shared_ptr<Node> headPtr = head;
        std::shared_ptr<Node> tailPtr = nullptr;

        while (headPtr != nullptr)
        {
            if (headPtr->data == x)
            {
                tailPtr->next = headPtr->next;
                headPtr->next = head;
                head = headPtr;
                return true;
            }

            tailPtr = headPtr;
            headPtr = headPtr->next;
        }

        return false;
    }

    // Time complexity -> min - o(1)
    // Time complexity -> max - o(n)
    // Space complexity -> o(1)
    [[nodiscard]] bool LinkedList::checkIfSortedAscending() const
    {
        if (head == nullptr)
        {
            return false;
        }
        else
        {
            int previousValue = INT_MIN;
            std::shared_ptr<Node> node = head;

            while (node != nullptr)
            {
                if (previousValue > node->data)
                {
                    return false;
                }

                previousValue = node->data;
                node = node->next;
            }

            return true;
        }
    }

    // Time complexity -> min - o(1)
    // Time complexity -> max - o(n)
    // Space complexity -> o(1)
    [[nodiscard]] bool LinkedList::checkIfSortedDescending() const
    {
        if (head == nullptr)
        {
            return false;
        }
        else
        {
            int previousValue = INT_MAX;
            std::shared_ptr<Node> node = head;

            while (node != nullptr)
            {
                if (previousValue < node->data)
                {
                    return false;
                }
                previousValue = node->data;
                node = node->next;
            }

            return true;
        }
    }

    [[nodiscard]] bool LinkedList::checkIfLoop() const
    {
        std::shared_ptr<Node> node = head;
        std::shared_ptr<Node> tail = head;

        do
        {
            node = node->next;
            tail = tail->next;

            node = (node == nullptr) ? nullptr : node->next;

        } while (node && tail && node != tail);

        return (node == tail) ? true : false;
    }

    std::ostream& operator<<(std::ostream& os, const LinkedList& ll)
    {
        std::shared_ptr<Node> element = ll.getHead();

        os << "Linked list elements: " << std::endl;

        while (element != nullptr)
        {
            os << element->data << " ";
            element = element->next;
        }

        return os;
    }
}