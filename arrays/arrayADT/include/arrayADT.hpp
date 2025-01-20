#pragma once
#include <iostream>
#include <concepts>
#include <memory>
#include <string>
#include <algorithm>

// Implementation of Array Abstract Data type
// Supported operations are: Display/Print, Add(x)/Append(x)
//      Insert(index, x), Delete(index), Search(x), Get(index), 
//      Set(index, x), Max()/Min(), Reverse(), Shift()/Rotate()

namespace arrayADT
{
    template <typename T>
    concept isANumber = std::integral<T> || std::floating_point<T>;

    template <typename T> requires isANumber<T>
    class arrayADT final
    {
        public:
            arrayADT() = delete;

            arrayADT(const unsigned int size, const unsigned int length, const std::initializer_list<T>& list);

            void Display() const noexcept;
            void Append(const int x);
            void Insert(const unsigned int index, const int x);
            void Delete(const unsigned int index);
            void Reverse();
            void LeftShift();
            void RightShift();
            void LeftRotate();
            void RightRotate();

            void SetElement(const unsigned int index, const T element);
            [[nodiscard]] T GetElement(const unsigned int index) const;
            [[nodiscard]] T GetMaxElement() const;
            [[nodiscard]] T GetMinElement() const;
            [[nodiscard]] T GetElementSum() const;
            [[nodiscard]] double GetElementAvg() const;

            [[nodiscard]] bool IsSortedAscending() const;
            [[nodiscard]] bool IsSortedDescending() const;

            [[nodiscard]] int LinearSearch(const T key) const;
            [[nodiscard]] int LinearSearchTransposition(const T key);
            [[nodiscard]] int LinearSearchMoveToHead(const T key);
            [[nodiscard]] int BinarySearch(const T key) const;
            [[nodiscard]] int BinarySearchRecursive(const T key) const;

            void PlaceNegativeLeft();
            void MergeArray(const arrayADT<T>& array);
            void OperationUnion(const arrayADT<T>& array);
            void OperationIntersection(const arrayADT<T>& array);
            void OperationDifference(const arrayADT<T>& array);

        private:
            std::shared_ptr<T[]> container;
            unsigned int size;
            unsigned int length;

            class InitializerListAndLengthNotEqual : public std::exception
            {
                public: 
                    InitializerListAndLengthNotEqual() = delete;

                    explicit InitializerListAndLengthNotEqual(const int listSize, const int arrayLength);
                    const char* what() const noexcept override;

                private:
                    std::string errorMessage;

                    void buildErrorMessage(const int listSize, const int arrayLength);
            };

            [[nodiscard]] int RBinarySearch(const unsigned int low, const unsigned int high, const T key) const;
            [[nodiscard]] T RGetElementSum(const unsigned int idx) const;

    };
}