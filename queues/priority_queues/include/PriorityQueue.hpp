#pragma once 
#include <iostream>
#include <memory>
#include "QueueInterface.hpp"

namespace PriorityQueues
{
    class PriorityQueue final : public QueueInterface
    {
    public:
        PriorityQueue()
        { }

        void enqueue(const int x) override;
        [[nodiscard]] int dequeue() override;
    };
}