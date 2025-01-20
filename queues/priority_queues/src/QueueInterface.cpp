#include "QueueInterface.hpp"

namespace PriorityQueues
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    QueueInterface::QueueInterface() : front(nullptr), rear(nullptr)
    { }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool QueueInterface::isFull() const
    {
        std::shared_ptr<Node> node = std::make_shared<Node>(INT_MIN, nullptr);

        return (node == nullptr);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] bool QueueInterface::isEmpty() const
    {
        return (front == nullptr && rear == nullptr);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int QueueInterface::first() const
    {
        return ((front == nullptr) ? INT_MIN : front->data);
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int QueueInterface::last() const
    {
        return ((rear == nullptr) ? INT_MIN : rear->data);
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const QueueInterface& queue)
    {
        std::shared_ptr<Node> node = queue.front;

        while (node != nullptr)
        {
            os << node->data << " ";
            node = node->next;
        }

        return os;
    }
}