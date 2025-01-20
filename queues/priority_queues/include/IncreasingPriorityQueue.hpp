#pragma once 
#include <iostream>
#include <memory>
#include "QueueInterface.hpp"

namespace PriorityQueues
{
    class IncreasingPriorityQueue final : public QueueInterface
    {
        public:
            IncreasingPriorityQueue() 
            { }

            void enqueue(const int x) override;
            [[nodiscard]] int dequeue() override;
    };
}