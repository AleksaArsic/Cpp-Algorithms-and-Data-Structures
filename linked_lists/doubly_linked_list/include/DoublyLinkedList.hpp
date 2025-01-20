#pragma once
#include <iostream>
#include <memory>

namespace DoublyLinkedList
{
    struct Node final
    {
        int data;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> previous;
    };

    class DoublyLinkedList final
    {
        public:
            DoublyLinkedList()
            {
                head = nullptr;
            }

            DoublyLinkedList(std::shared_ptr<Node> first) : head(first)
            { }

            std::shared_ptr<Node> getHead() const;

            // Manipulate Linked List elements.
            void AddElements(const unsigned int noOfElements, std::shared_ptr<int[]> elementArray);
            void Insert(const unsigned int position, const int x);
            void InsertLast(const int x);
            void InsertInASortedList(const int x);
            void DeleteElement(const int x);
            void DeleteAtPosition(const unsigned int position);
            void DeleteDuplicates();
            void ReverseElements();
            void ReverseNodes();

            // Basic algorithms and information retrieval 
            [[nodiscard]] unsigned int countNodes() const;
            void DisplayInReverse() const;

            friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& ll);

        private:
            std::shared_ptr<Node> head;
    };

}