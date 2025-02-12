#pragma once
#include <iostream>
#include <memory>

namespace ChainHashing
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
    };

    class Hash final
    {
        public:
            Hash(const int size = 10L);

            void SortedInsert(const int data);
            [[nodiscard]] int DeleteElement(const int data);
            [[nodiscard]] bool Search(const int data) const;

            friend std::ostream& operator<<(std::ostream& os, const Hash& hash);
        private:
            unsigned int hashSize;
            std::unique_ptr<std::shared_ptr<Node>[]> hashMap;

            [[nodiscard]] int hashFunction(const int data) const;
    };
}