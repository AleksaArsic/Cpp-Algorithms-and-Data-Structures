#include "PriorityQueue.hpp"

namespace PriorityQueues
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    // Insert the data as it comes
    void PriorityQueue::enqueue(const int x)
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(x, nullptr);

        if (!isFull())
        {
            if (isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = rear->next;
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
    // Dequeue lowest priority first.
    [[nodiscard]] int PriorityQueue::dequeue()
    {
        int data = INT_MAX;
        std::shared_ptr<Node> node = front;
        std::shared_ptr<Node> savedNode = nullptr;

        if (!isEmpty())
        {
            while (node != nullptr)
            {
                if (data > node->data)
                {
                    savedNode = node;
                    data = node->data;
                }
                node = node->next;
            }

            node = front;

            if (node != nullptr)
            {
                if (node == savedNode)
                {
                    node = node->next;
                    front.reset();
                    front = node;
                }
                else
                {
                    while (node->next != savedNode)
                    {
                        node = node->next;
                    }

                    node->next = node->next->next;
                    savedNode.reset();
                }

            }
            else
            {
                data = INT_MIN;
            }
        }
        else
        {
            std::cout << "The queue is empty." << std::endl;
        }
        

        return data;
    }
}