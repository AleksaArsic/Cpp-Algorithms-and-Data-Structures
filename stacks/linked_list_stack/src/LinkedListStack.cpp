#include "LinkedListStack.hpp"

namespace LinkedListStack
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Stack::push(const int data)
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(data, top);

        if (newNode == nullptr)
        {
            std::cout << "Stack is full." << std::endl;
        }
        else
        {
            top = newNode;
        }

    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    int Stack::pop()
    {
        std::shared_ptr<Node> node = top;
        int data = 0;

        if (top != nullptr)
        {
            data = top->data;
            top = top->next;

            node.reset();

            return data;
        }
        else
        {
            std::cout << "Stack is empty." << std::endl;
        }

        return INT_MIN;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::peek(int index) const
    {
        unsigned int nodeCount = countNodes();
        std::shared_ptr<Node> node = top;

        if (index < nodeCount)
        {
            for (unsigned int i = 0; i < index; ++i)
            {
                node = node->next;
            }
        }

        return node->data;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::stackTop() const
    {
        return (top == nullptr) ? INT_MIN : top->data;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodisacrd]] bool Stack::isEmpty() const
    {
        return top == nullptr;;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isFull() const
    {
        std::shared_ptr<Node> node = std::make_shared<Node>();

        return (node == nullptr) ? true : false;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] unsigned int Stack::countNodes() const
    {
        std::shared_ptr<Node> node = top;
        unsigned int nodeCount = 0;

        while (node != nullptr)
        {
            nodeCount++;
            node = node->next;
        }

        return nodeCount;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Stack& s)
    {
        std::shared_ptr<Node> node = s.top;

        while (node != nullptr)
        {
            os << node->data << " ";
            node = node->next;
        }

        return os;
    }

}