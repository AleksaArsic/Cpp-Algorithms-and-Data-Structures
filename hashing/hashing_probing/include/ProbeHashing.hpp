#pragma once
#include <iostream>
#include <memory>

namespace ProbeHashing
{

    class Hash final
    {
        public:
            Hash(const unsigned int size = 10L);

            void Insert(const int data);
            [[nodiscard]] int DeleteElement(const int data);
            [[nodiscard]] bool Search(const int datas) const;

            friend std::ostream& operator<<(std::ostream& os, const Hash& hash);
        private:
            unsigned int hashSize;
            std::unique_ptr<int[]> hashMap;

            [[nodiscard]] int Probe(const int data, const int i) const;
            [[nodiscard]] int hashFunction(const int data) const;
            [[nodiscard]] int probeFunction(const int data) const;

            [[nodiscard]] int numberOfFilledElements() const;
    };
}