#pragma once
#include <iostream>
#include <memory>

namespace CircularLinkedList
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
    };

    class CircularLinkedList final
    {
        public:
            CircularLinkedList()
            {
                head = nullptr;
            }

            CircularLinkedList(std::shared_ptr<Node> first)
            {
                head = first;
            }

            std::shared_ptr<Node> getHead() const;

            // Manipulate Linked List elements.
            void AddElements(const unsigned int noOfElements, const std::shared_ptr<int[]> elementArray);
            void Insert(const unsigned int position, const int x);
            void InsertLast(const int x);
            void InsertInASortedList(const int x);
            void DeleteElement(const int x);
            void DeleteAtPosition(const int position);
            void DeleteDuplicates();
            void DeleteHead();

            // Basic algorithms and information retrieval 
            void DisplayInReverse(const std::shared_ptr<Node>& node) const;
            [[nodiscard]] unsigned int countNodes() const;

            friend std::ostream& operator<<(std::ostream& os, const CircularLinkedList& cll);
        private:
            std::shared_ptr<Node> head;
    };
}