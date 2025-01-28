#include "Stack.hpp"

namespace LinkedListStack
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Stack::Stack() : top(nullptr)
    { }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Stack::push(const std::shared_ptr<ComplexTypes::TreeNode>& node, const bool alreadyPushed)
    {
        if (!isFull())
        {
            std::shared_ptr<ComplexTypes::Node> newNode = std::make_shared<ComplexTypes::Node>(alreadyPushed, node, top);

            top = newNode;
        }
        else
        {
            std::cout << "[stack.push()] Stack is full." << std::endl;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::pop()
    {
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = nullptr;

        if (!isEmpty())
        {
            std::shared_ptr<ComplexTypes::Node> node = top;

            treeNode = node->dataNode;
            top = top->next;
            node.reset();
        }
        else
        {
            std::cout << "[stack.pop()] Stack is empty." << std::endl;
        }

        return treeNode;
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
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>(INT_MIN, nullptr, nullptr);
        std::shared_ptr<ComplexTypes::Node> node = std::make_shared<ComplexTypes::Node>(false, nullptr, nullptr);

        return (treeNode == nullptr || node == nullptr);
    }

    // Time complexity  -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isTopAlreadyPushed() const
    {
        return top->isAlreadyPushed;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[noidscard]] unsigned int Stack::stackSize() const
    {
        std::shared_ptr<ComplexTypes::Node> node = top;
        unsigned int stackSize = 0;

        while (node != nullptr)
        {
            stackSize++;
            node = node->next;
        }

        return stackSize;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::stackTop() const
    {
        return (top == nullptr) ? nullptr : top->dataNode;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Stack::peek(const unsigned int position) const
    {
        std::shared_ptr<ComplexTypes::Node> node = nullptr;

        if (position < stackSize())
        {
            node = top;

            for (unsigned int i = 0; i < position; ++i)
            {
                node = node->next;
            }
        }

        return node->dataNode;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Stack& stack)
    {
        std::shared_ptr<ComplexTypes::Node> node = stack.top;

        while (node != nullptr)
        {
            os << node->dataNode->data << " ";
            node = node->next;
        }

        return os;
    }
}