#include "ProbeHashing.hpp"
#include <algorithm>

namespace ProbeHashing
{
    // Time complexity -> o(1)
    // Space complexity -> o(n) - theoretically we are allocatin array of 'size' number of ints
    Hash::Hash(const unsigned int size) : hashSize(size)
    {
        hashMap = std::make_unique<int[]>(hashSize);

        std::fill(hashMap.get(), hashMap.get() + hashSize, INT_MIN);
    }

    // loading factor lambda <= 0.5
    // otherwise the uniform distribution assumption fails
    void Hash::Insert(const int data)
    {
        if ((static_cast<double>(numberOfFilledElements()) / static_cast<double>(hashSize)) < 0.5)
        {
            int hashedIdx = INT_MIN;
            int i = 0L;

            do
            {
                hashedIdx = Probe(data, i++);
            } while (hashMap[hashedIdx] != INT_MIN);

            hashMap[hashedIdx] = data;
        }
        else
        {
            std::cout << "[Insert()]: Loading factor - lambda > 0.5. Uniform distribution assumption fails." << std::endl;
        }
    }

    [[nodiscard]] int Hash::DeleteElement(const int data)
    {
        int deletedData = INT_MIN;

        int hashedIdx = Probe(data, 0L);
        unsigned int i = 0;

        while (hashMap[hashedIdx] != data && hashMap[hashedIdx] != INT_MIN)
        {
            hashedIdx = Probe(data, i++);
        }

        if (hashMap[hashedIdx] == data)
        {
            deletedData = data;
            hashMap[hashedIdx] = INT_MIN;

            int tailIdx = Probe(deletedData, i);
            int headIdx = Probe(deletedData, ++i);

            while (hashMap[headIdx] != INT_MIN && Probe(hashMap[headIdx], i - 1L) == tailIdx)
            {
                hashMap[tailIdx] = hashMap[headIdx];

                tailIdx = headIdx;
                headIdx = Probe(deletedData, ++i);
            }
            
            hashMap[tailIdx] = INT_MIN;
        }

        return deletedData;
    }

    // Time complexity -> o(t), t = 1 / lambda * ln(1/(1 - lambda))
    // Space complexity -> o(1)
    [[nodiscard]] bool Hash::Search(const int data) const
    {
        int hashedIdx = INT_MIN;
        int i = 0;

        do
        {
            hashedIdx = Probe(data, i++);
        } while (hashMap[hashedIdx] != data && hashMap[hashedIdx] != INT_MIN);

        return (hashMap[hashedIdx] == data) ? true : false;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Hash::Probe(const int data, const int i) const
    {
        return (hashFunction(data) + probeFunction(i)) % hashSize;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Hash::hashFunction(const int data) const
    {
        return data % hashSize;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int Hash::probeFunction(const int data) const
    {
        return data * data;
    }

    [[nodiscard]] int Hash::numberOfFilledElements() const
    {
        unsigned int elementCnt = 0U;

        for (unsigned int i = 0; i < hashSize; ++i)
        {
            if (hashMap[i] != INT_MIN)
            {
                elementCnt++;
            }
        }

        return elementCnt;
    }

    // Time complexity -> o(n)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Hash& hash)
    {
        for (unsigned int i = 0; i < hash.hashSize; ++i)
        {
            os << hash.hashMap[i] << " ";
        }

        return os;
    }
}