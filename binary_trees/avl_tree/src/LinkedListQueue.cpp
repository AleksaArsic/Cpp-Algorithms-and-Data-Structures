#include "LinkedListQueue.hpp"

namespace LinkedListQueue
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Queue::Queue() : front(nullptr), back(nullptr)
    { }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Queue::enqueue(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node)
    {
        if (!isFull())
        {
            std::shared_ptr<ComplexTypes::TreeNode> newNode = std::make_shared<ComplexTypes::TreeNode>(false, node, nullptr);

            if (isEmpty())
            {
                front = back = newNode;
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

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> Queue::dequeue()
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> node = nullptr;

        if (!isEmpty())
        {
            node = front->treeNode;
            front = front->next;

            if (front == nullptr)
            {
                back.reset();
                back = nullptr;
            }
        }
        else
        {
            std::cout << "Queue is empty." << std::endl;
        }

        return node;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Queue::isFull() const
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> treeNode = std::make_shared<ComplexTypes::AVLTreeNode>(INT_MIN, INT_MAX, nullptr, nullptr);
        std::shared_ptr<ComplexTypes::TreeNode> node = std::make_shared<ComplexTypes::TreeNode>(false, nullptr, nullptr);

        return (treeNode == nullptr || node == nullptr);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Queue::isEmpty() const
    {
        return front == nullptr;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> Queue::first() const
    {
        return (front == nullptr) ? nullptr : front->treeNode;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> Queue::last() const
    {
        return (back == nullptr) ? nullptr : back->treeNode;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Queue& queue)
    {
        std::shared_ptr<ComplexTypes::TreeNode> node = queue.front;

        while (node != nullptr)
        {
            os << "(" << node->treeNode->data << ", " << node->treeNode->height << ") ";
            node = node->next;
        }

        return os;
    }
}