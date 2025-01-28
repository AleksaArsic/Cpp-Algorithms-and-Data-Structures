#include "LinkedListStack.hpp"

namespace LinkedListStack
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    Stack::Stack() : top(nullptr)
    { }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void Stack::push(const std::shared_ptr<ComplexTypes::AVLTreeNode>& treeNode, bool isAlreadyPushed)
    {
        if (!isFull())
        {
            std::shared_ptr<ComplexTypes::TreeNode> node = top;

            top = std::make_shared<ComplexTypes::TreeNode>(isAlreadyPushed, treeNode, top);
            top->next = node;
        }
        else
        {
            std::cout << "Stack is full." << std::endl;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> Stack::pop()
    {
        std::shared_ptr<ComplexTypes::TreeNode> node = top;
        std::shared_ptr<ComplexTypes::AVLTreeNode> avlNode = nullptr;

        if (!isEmpty())
        {
            avlNode = top->treeNode;
            top = top->next;
            node.reset();
        }
        else
        {
            std::cout << "Stack is empty." << std::endl;
        }

        return avlNode;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> Stack::stackTop() const
    {
        return (top == nullptr) ? nullptr : top->treeNode;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> Stack::peek(const unsigned int position) const
    {
        std::shared_ptr<ComplexTypes::TreeNode> node = top;

        if (position < stackSize())
        {
            for (unsigned int i = 0; i < position; ++i)
            {
                node = node->next;
            }
        }

        return (node == nullptr) ? nullptr : node->treeNode;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isFull() const
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> avlTreeNode = std::make_shared<ComplexTypes::AVLTreeNode>(0L, 1U, nullptr, nullptr);
        std::shared_ptr<ComplexTypes::TreeNode> node = std::make_shared<ComplexTypes::TreeNode>(false, avlTreeNode, nullptr);

        return (avlTreeNode == nullptr || node == nullptr);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isEmpty() const
    {
        return (top == nullptr);
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] unsigned int Stack::stackSize() const
    {
        unsigned int nodeCount = INT_MIN;
        std::shared_ptr<ComplexTypes::TreeNode> node = top;

        while (node != nullptr)
        {
            nodeCount++;
            node = node->next;
        }

        return nodeCount;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool Stack::isTopAlreadyPushed() const
    {
        return (top == nullptr) ? false : top->alreadyPushed;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Stack& stack)
    {
        std::shared_ptr<ComplexTypes::TreeNode> node = stack.top;

        while (node != nullptr)
        {
            os << "(" << node->treeNode->data << ", " << node->treeNode->height << ") ";
            node = node->next;
        }

        return os;
    }
}