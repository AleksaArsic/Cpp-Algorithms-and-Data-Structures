#include "Queue.hpp"

namespace LinkedListQueue
{
    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    void Queue::enqueue(const std::shared_ptr<ComplexTypes::TreeNode>& treeNode)
    {
        if (!isFull())
        {
            std::shared_ptr<ComplexTypes::Node> newNode = std::make_shared<ComplexTypes::Node>(treeNode, nullptr);

            if (isEmpty())
            {
                front = newNode;
                back = front;
            }
            else
            {
                back->next = newNode;
                back = back->next;
                
            }
        }
        else
        {
            std::cout << "Queue is full." << std::endl;
        }
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodicasrd]] std::shared_ptr<ComplexTypes::TreeNode> Queue::dequeue()
    {
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = nullptr;

        if (!isEmpty())
        {
            std::shared_ptr<ComplexTypes::Node> node = front;
            
            treeNode = front->data;
            front = front->next;
            node.reset();
        }
        else
        {
            std::cout << "Queue is empty." << std::endl;
        }

        return treeNode;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool Queue::isFull() const
    {
        std::shared_ptr<ComplexTypes::Node> node = std::make_shared<ComplexTypes::Node>(nullptr, nullptr);
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>(INT_MIN, nullptr, nullptr);

        return (node == nullptr || treeNode == nullptr);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] bool Queue::isEmpty() const
    {
        return (front == nullptr);
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Queue::first() const
    {
        return (front == nullptr) ? INT_MIN : front->data->data;
    }

    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    [[nodiscard]] int Queue::last() const
    {
        return (back == nullptr) ? INT_MIN : back->data->data;
    }

    // Time Complexity -> o(n)
    // Space Complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Queue& queue)
    {
        std::shared_ptr<ComplexTypes::Node> node = queue.front;

        while (node != nullptr && node->data != nullptr)
        {
            os << node->data->data << " ";
            node = node->next;
        }

        return os;
    }
}