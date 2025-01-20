#include "LinkedListDequeue.hpp"

namespace LinkedListDequeue
{
    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    Dequeue::Dequeue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    void Dequeue::pushFront(const int data)
    {
        if (!isFull())
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(data, nullptr);

            if (isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                newNode->next = front;
                front = newNode;
            }
        }
        else
        {
            std::cout << "[pushFront()] Dequeue is full." << std::endl;
        }
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    void Dequeue::pushRear(const int data)
    {
        if (!isFull())
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(data, nullptr);

            if (isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
        else
        {
            std::cout << "[pushRear()] Dequeue is full." << std::endl;
        }
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Dequeue::popFront()
    {
        int data = INT_MIN;

        if (!isEmpty())
        {
            data = front->data;
            front = front->next;
        }
        else
        {
            std::cout << "[popFront()] Dequeue is empty." << std::endl;
        }

        return data;
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    [[nodiscard]] int Dequeue::popRear()
    {
        int data = INT_MIN;

        if (!isEmpty())
        {
            std::shared_ptr<Node> node = front;

            while (node->next != rear)
            {
                node = node->next;
            }

            data = rear->data;
            rear.reset();
            rear = node;
            rear->next = nullptr;
        }
        else
        {
            std::cout << "[popRear()] Dequeue is empty." << std::endl;
        }

        return data;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool Dequeue::isFull() const
    {
        std::shared_ptr<Node> node = std::make_shared<Node>(INT_MIN, nullptr);

        return (node == nullptr) ? true : false;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool Dequeue::isEmpty() const
    {
        return ((front == nullptr) && (rear == nullptr));
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Dequeue::first() const
    {
        return (front == nullptr) ? INT_MIN : front->data;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Dequeue::last() const
    {
        return (rear == nullptr) ? INT_MIN : rear->data;
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Dequeue& dequeue)
    {
        std::shared_ptr<Node> node = dequeue.front;

        while (node != nullptr)
        {
            os << node->data << " ";
            node = node->next;
        }

        return os;
    }
}