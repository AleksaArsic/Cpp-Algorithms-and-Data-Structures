#include "LinkedListStack.hpp"

namespace LinkedListStack
{
    void Stack::push(const char data, const char precedence)
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(Data(data, precedence), top);

        top = newNode;
    }

    const Data& Stack::pop()
    {
        std::shared_ptr<Node> node = top;
        Data poppedData (CHAR_MIN, CHAR_MIN);

        if (node != nullptr)
        {
            poppedData = top->data;

            top = top->next;
            node.reset(); // delete node;

        }

        return poppedData;
    }

    const Data& Stack::stackTop() const
    {
        return (top == nullptr) ? Data(CHAR_MIN, CHAR_MIN) : top->data;
    }

    const Data& Stack::peek(const unsigned int position) const
    {
        std::shared_ptr<Node> node = top;

        if (node != nullptr && position < nodeCount())
        {
            for (unsigned int i = 0; node != nullptr && i < position; ++i)
            {
                node = node->next;
            }

            return (node == nullptr) ? Data(CHAR_MIN, CHAR_MIN) : node->data;
        }

        return Data(CHAR_MIN, CHAR_MIN);
    }

    bool Stack::isFull() const
    {
        Node* node = new Node(Data(CHAR_MIN, CHAR_MIN), nullptr);
        bool isFull = false;

        if (!node)
        {
           isFull = true;
        }

        delete node;

        return isFull;
    }

    bool Stack::isEmpty() const
    {
        return (top == nullptr);
    }

    [[nodiscard]] unsigned int Stack::nodeCount() const
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

    std::ostream& operator<<(std::ostream& os, const Stack& s)
    {
        std::shared_ptr<Node> node = s.top;

        while (node != nullptr)
        {
            os << node->data.character << " ";
            node = node->next;
        }

        return os;
    }

}