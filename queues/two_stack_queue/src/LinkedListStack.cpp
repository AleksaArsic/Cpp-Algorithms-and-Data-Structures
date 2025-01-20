#include "LinkedListStack.hpp"

namespace LinkedListStack
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Stack::Stack() : top(nullptr)
    { }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Stack::push(const int data)
    {
        if (!isFull())
        {
            std::shared_ptr<Node> newNode = std::make_shared<Node>(data, top);
            top = newNode;
        }
        else
        {
            std::cout << "The stack is full." << std::endl;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::pop()
    {
        int data = INT_MIN;

        if (!isEmpty())
        {
            data = top->data;
            top = top->next;
        }
        else
        {
            std::cout << "The stack is empty." << std::endl;
        }

        return data;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::stackTop() const
    {
        return (top == nullptr) ? INT_MIN : top->data;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::peek(const unsigned int position) const
    {
        std::shared_ptr<Node> node = top;
        int data = INT_MIN;

        if (position <= countNodes())
        {
            for (unsigned int i = 0; i < position; ++i)
            {
                node = node->next;
            }
            data = node->data;
        }
        else
        {
            std::cout << "Peek index out of range." << std::endl;
        }
        
        return data;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isEmpty() const
    {
        return (top == nullptr);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isFull() const
    {
        std::shared_ptr<Node> node = std::make_shared<Node>(INT_MIN, nullptr);

        return (node == nullptr);
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] int Stack::stackSize() const
    {
        return countNodes();
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
    std::ostream& operator<<(std::ostream& os, const Stack stack)
    {
        std::shared_ptr<Node> node = stack.top;

        while (node != nullptr)
        {
            std::cout << node->data << " ";
            node = node->next;
        }

        return os;
    }
}