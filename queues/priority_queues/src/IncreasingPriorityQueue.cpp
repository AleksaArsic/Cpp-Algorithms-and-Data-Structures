#include "IncreasingPriorityQueue.hpp"

namespace PriorityQueues
{
    // Time complexity -> o(n)
    // Space complexity -> o(1)
    // Enqueue in increasing order (non-decreasing order)
    void IncreasingPriorityQueue::enqueue(const int x)
    {
        std::shared_ptr<Node> head = front;
        std::shared_ptr<Node> tail = nullptr;

        if (!isFull())
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr);

            if (isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                while (head != nullptr && x > head->data)
                {
                    tail = head;
                    head = head->next;
                }

                if (tail != nullptr)
                {
                    tail->next = newNode;
                    newNode->next = head;


                    if (newNode->next == nullptr)
                    {
                        rear = newNode;
                    }
                }
                else
                {
                    front = newNode;
                    front->next = head;
                }
                
            }
        }
        else
        {
            std::cout << "Queue is full." << std::endl;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    // Higher the number lower the priority.
    // Dequeue front as the data is sorted in increasing order (non-decreasing order).
    [[nodiscard]] int IncreasingPriorityQueue::dequeue()
    {
        std::shared_ptr<Node> node = front;
        int data = INT_MIN;

        if (!isEmpty())
        {
            data = front->data;
            front = front->next;
            if (front == rear)
            {
                front.reset();
                rear.reset();
            }
            node.reset();
        }
        else
        {
            std::cout << "The queue is empty." << std::endl;
        }

        return data;
    }
}