#pragma once
#include <iostream>
#include <memory>

namespace LinkedList
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
    };

    class LinkedList final
    {
        public:
            LinkedList()
            {
                head = nullptr;
            }

            LinkedList(std::shared_ptr<Node> first)
            {
                head = first;
            }

            std::shared_ptr<Node> getHead() const;

            // Manipulate Linked List elements.
            void AddElements(const unsigned int noOfElements, std::shared_ptr<int[]> elements);
            void Insert(const unsigned int position, const int x);
            void InsertLast(const int x);
            void InsertInASortedList(const int x);
            void DeleteElement(const int x);
            void DeleteAtPosition(const int position);
            void DeleteDuplicates();
            void ReverseElements();
            void ReverseNodes();
            void rReverseNodes(std::shared_ptr<Node> tail, std::shared_ptr<Node> node);
            void MergeLinkedList(LinkedList& linkedList);

            // Basic algorithms and information retrieval 
            void DisplayInReverse(std::shared_ptr<Node> node) const;
            [[nodiscard]] unsigned int countNodes() const;
            [[nodiscard]] int sumOfAllElements() const;
            [[nodiscard]] int findMaxElement() const;
            [[nodiscard]] int rFindMaxElement(const std::shared_ptr<Node> node) const;
            [[nodiscard]] std::shared_ptr<Node> findMaxElementAddress() const;
            [[nodiscard]] int findMinElement() const;
            [[nodiscard]] int rFindMinElement(const std::shared_ptr<Node> node) const;
            [[nodiscard]] std::shared_ptr<Node> findMinElementAddress() const;
            [[nodiscard]] bool findElement(const int x) const;
            [[nodiscard]] bool rFindElement(std::shared_ptr<Node> node,const int x) const;
            [[nodiscard]] bool findElementOptimized(const int x);
            [[nodiscard]] bool checkIfSortedAscending() const;
            [[nodiscard]] bool checkIfSortedDescending() const;
            [[nodiscard]] bool checkIfLoop() const;

            // Find the middle node
            [[nodiscard]] std::shared_ptr<Node> findMiddleNodeSimple() const;
            [[nodiscard]] std::shared_ptr<Node> findMiddleNode() const;
            [[nodiscard]] std::shared_ptr<Node> findMiddleNodeAdvanced() const;

            friend std::ostream& operator<<(std::ostream& os, const LinkedList& ll);

        private:
            std::shared_ptr<Node> head;
    };
}