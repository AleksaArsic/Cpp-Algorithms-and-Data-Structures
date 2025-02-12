#include "ChainHashing.hpp"

namespace ChainHashing
{
    // Time complexity -> o(1)
    // Space complexity -> o(1) - technically we do allocate n = size shared pointers to Nodes
    Hash::Hash(const unsigned int size) : hashSize(size)
    {
        hashMap = std::make_unique<std::shared_ptr<Node>[]>(hashSize);
    }

    // Implements open hashing techinque -> chaining (usage of linked lists)
    // Loading factor lambda = n / hashSize, n -> number of values
    // we are assuming that the keys are uniformly distributed with the factor lambda
    // 
    // Time complexity -> o(1 + lambda)
    // Space complexity -> o(1)
    void Hash::SortedInsert(const int data)
    {
        std::shared_ptr<Node> newData = std::make_shared<Node>(data, nullptr);

        unsigned int hashedData = hashFunction(newData->data);
        std::shared_ptr<Node> hashList = hashMap[hashedData];

        if (hashList == nullptr)
        {
            hashList = newData;
            hashMap[hashedData] = hashList;
        }
        else
        {
            std::shared_ptr<Node> hashListNode = hashList;
            std::shared_ptr<Node> hashListNodeTail = nullptr;

            while (hashListNode != nullptr && hashListNode->data < newData->data)
            {
                hashListNodeTail = hashListNode;
                hashListNode = hashListNode->next;
            }

            newData->next = hashListNode;
            (hashListNodeTail == nullptr) ? hashMap[hashedData] = newData : hashListNodeTail->next = newData;
        }

    }

    // Loading factor lambda = n / hashSize, n -> number of values
    // we are assuming that the keys are uniformly distributed with the factor lambda
    // 
    // Time complexity -> avg. successfull delete -> t = 1 + lambda/2 -> o(t)
    //                 -> avg. unsuccessfull delete -> t = 1 + lambda -> o(t)
    // Space complexity -> o(1)
    [[nodiscard]] int Hash::DeleteElement(const int data)
    {
        int deletedData = INT_MIN;
        int hashedData = hashFunction(data);
        std::shared_ptr<Node> hashListNode = hashMap[hashedData];
        std::shared_ptr<Node> hashListNodeTail = nullptr;

        while (hashListNode != nullptr && hashListNode->data != data)
        {
            hashListNodeTail = hashListNode;
            hashListNode = hashListNode->next;
        }

        if (hashListNode != nullptr && hashListNode->data == data)
        {
            deletedData = hashListNode->data;

            if (hashListNodeTail == nullptr)
            {
                hashMap[hashedData] = hashListNode->next;
                hashListNode.reset();
            }
            else
            {
                hashListNodeTail->next = hashListNode->next;
                hashListNode.reset();
            }
        }
        

        return deletedData;
    }

    // Loading factor lambda = n / hashSize, n -> number of values
    // we are assuming that the keys are uniformly distributed with the factor lambda
    // 
    // Time complexity -> avg. successfull search -> t = 1 + lambda/2 -> o(t)
    //                 -> avg. unsuccessfull search -> t = 1 + lambda -> o(t)
    // Space complexity -> o(1)
    [[nodiscard]] bool Hash::Search(const int data) const
    {
        bool dataFound = false;
        int hashedData = hashFunction(data);
        std::shared_ptr<Node> hashListNode = hashMap[hashedData];

        while (hashListNode != nullptr && hashListNode->data != data)
        {
            hashListNode = hashListNode->next;
        }

        if (hashListNode != nullptr && hashListNode->data == data)
        {
            dataFound = true;
        }

        return dataFound;
    }

    [[nodiscard]] int Hash::hashFunction(const int data) const
    {
        return data % hashSize;
    }

    // Time complexity -> o(n^2)
    // Space complexity -> o(1)
    std::ostream& operator<<(std::ostream& os, const Hash& hash)
    {
        std::shared_ptr<ChainHashing::Node> node = nullptr;

        os << "HashMap -> (" << hash.hashMap << "):" << std::endl;
        for (unsigned int i = 0U; i < hash.hashSize; ++i)
        {
            os << "(" << hash.hashMap[i] << "): " << std::endl;
            node = hash.hashMap[i];

            while (node != nullptr)
            {
                os << node->data << " ";
                node = node->next;
            }

            os << std::endl;
        }

        return os;
    }
}