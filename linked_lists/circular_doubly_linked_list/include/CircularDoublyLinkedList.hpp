#pragma once
#include <iostream>
#include <memory>

namespace CircularDoublyLinkedList
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> previous;
    };

    class CircularDoublyLinkedList final
    {
        public:
            CircularDoublyLinkedList() : head(nullptr)
            { }

            CircularDoublyLinkedList(std::shared_ptr<Node> first) : head(first)
            { }

            std::shared_ptr<Node> getHead() const;
            std::shared_ptr<Node>& getHeadRef();

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
            void DisplayInReverse() const;
            [[nodiscard]] unsigned int countNodes() const;

            friend std::ostream& operator<<(std::ostream& os, const CircularDoublyLinkedList& cdll);
        private:
            std::shared_ptr<Node> head;
    };
}