#include "arrayADT.h"

int main()
{
    arrayADT::arrayADT<int> array(8, 6, { 1, 2, 3, 4, 5, 6 });

    array.Display();

    std::cout << "Append 9" << std::endl;
    array.Append(9);
    std::cout << "Insert 33 at index 2" << std::endl;
    array.Insert(2, 33);
    
    std::cout << "Append 7" << std::endl;
    array.Append(7);
    std::cout << "Insert 55 at index 2" << std::endl;
    array.Insert(2, 55);

    array.Display();

    std::cout << "Delete 33" << std::endl;
    array.Delete(2);
    std::cout << "Insert 55 at index 2" << std::endl;
    array.Insert(2, 55);
    std::cout << "Append 7" << std::endl;
    array.Append(7);

    array.Display();

    std::cout << "Element 4 is at index: " << array.LinearSearch(4) << std::endl;
    std::cout << "Element 12 is at index: " << array.LinearSearch(12) << std::endl;

    array.Display();

    std::cout << "Element 3 is at index: " << array.LinearSearchTransposition(3) << std::endl;
    std::cout << "Element 3 is at index: " << array.LinearSearchTransposition(3) << std::endl;
    std::cout << "Element 3 is at index: " << array.LinearSearchTransposition(3) << std::endl;

    array.Display();

    std::cout << "Element 5 is at index: " << array.LinearSearchMoveToHead(5) << std::endl;

    array.Display();

    std::cout << "Element 4 is at index: " << array.LinearSearchMoveToHead(4) << std::endl;

    array.Display();

    std::cout << "Element 5 is at index: " << array.LinearSearchMoveToHead(5) << std::endl;

    array.Display();

    std::cout << "[GetElement] Element at index 3 is equal to: " << array.GetElement(3) << std::endl;
    std::cout << "[SetElement] Element at index 3 is set to 33." << std::endl;
    array.SetElement(3, 33);
    std::cout << "[GetElement] Element at index 3 is equal to: " << array.GetElement(3) << std::endl;
    std::cout << "[MaxElement] Maximal element in the array is equal to: " << array.GetMaxElement() << std::endl;
    std::cout << "[MinElement] Minimal element in the array is equal to: " << array.GetMinElement() << std::endl;
    std::cout << "[GetElementSum] Sum of all elements is equal to: " << array.GetElementSum() << std::endl;
    std::cout << "[GetElementAvg] Avg of all elements is equal to: " << array.GetElementAvg() << std::endl;

    // For Binary Search array needs to be sorted
    arrayADT::arrayADT<int> arraySorted(8, 6, { 1, 2, 3, 4, 5, 6 });

    // Loop Binary search
    std::cout << "[BinarySearch] Element 4 is at index: " << arraySorted.BinarySearch(4) << std::endl;
    std::cout << "[BinarySearch] Element 1 is at index: " << arraySorted.BinarySearch(1) << std::endl;
    std::cout << "[BinarySearch] Element 6 is at index: " << arraySorted.BinarySearch(6) << std::endl;
    std::cout << "[BinarySearch] Element 7 is at index: " << arraySorted.BinarySearch(7) << std::endl;

    // Recursive Binary search
    std::cout << "[RBinarySearch] Element 4 is at index: " << arraySorted.BinarySearchRecursive(4) << std::endl;
    std::cout << "[RBinarySearch] Element 1 is at index: " << arraySorted.BinarySearchRecursive(1) << std::endl;
    std::cout << "[RBinarySearch] Element 6 is at index: " << arraySorted.BinarySearchRecursive(6) << std::endl;
    std::cout << "[RBinarySearch] Element 7 is at index: " << arraySorted.BinarySearchRecursive(7) << std::endl;

    arraySorted.Display();

    std::cout << "Array is sorted ascending: " << arraySorted.IsSortedAscending() << std::endl;
    std::cout << "Array is sorted descending: " << arraySorted.IsSortedDescending() << std::endl;

    arraySorted.Reverse();
    arraySorted.Display();

    std::cout << "Array is sorted ascending: " << arraySorted.IsSortedAscending() << std::endl;
    std::cout << "Array is sorted descending: " << arraySorted.IsSortedDescending() << std::endl;

    arraySorted.LeftRotate();
    arraySorted.RightRotate();
    arraySorted.LeftShift();
    arraySorted.RightShift();

    arraySorted.Display();

    arrayADT::arrayADT<int> arrayWithNegatives(8, 6, { 1, -2, 3, -4, 5, -6 });

    arrayWithNegatives.Display();
    arrayWithNegatives.PlaceNegativeLeft();
    arrayWithNegatives.Display();

    arrayADT::arrayADT<int> sortedArrayOne(8, 6, { 1, 3, 19, 23, 31, 33 });
    arrayADT::arrayADT<int> sortedArrayTwo(8, 3, { 1, 18, 22 });

    sortedArrayOne.Display();
    sortedArrayTwo.Display();
    sortedArrayOne.MergeArray(sortedArrayTwo);
    sortedArrayOne.Display();

    std::cout << "UNION: " << std::endl;
    arrayADT::arrayADT<int> arrayForUnionOne(8, 6, { 1, 3, 19, 23, 2, 8 });
    arrayADT::arrayADT<int> arrayForUnionTwo(8, 5, { 1, 18, 23, 7, 11 });
    arrayADT::arrayADT<int> arrayForUnionThree(8, 5, { 1, 3, 5, 7, 11 });
    arrayADT::arrayADT<int> arrayForUnionFour(8, 6, { 2, 3, 6, 7, 13, 15 });

    arrayForUnionOne.Display();
    arrayForUnionTwo.Display();
    arrayForUnionOne.OperationUnion(arrayForUnionTwo); // Union: 1 3 19 23 2 8 18 7 11
    arrayForUnionOne.Display();

    arrayForUnionThree.Display();
    arrayForUnionFour.Display();
    arrayForUnionThree.OperationUnion(arrayForUnionFour); // Union: 1 2 3 5 6 7 11 13 15
    arrayForUnionThree.Display();

    std::cout << "INTERSECTION: " << std::endl;
    arrayADT::arrayADT<int> arrayForIntersectionOne(8, 5, { 1, 3, 5, 7, 11 });
    arrayADT::arrayADT<int> arrayForIntersectionTwo(8, 6, { 2, 3, 6, 7, 13, 15 });
    arrayADT::arrayADT<int> arrayForIntersectionThree(8, 6, { 1, 3, 19, 23, 2, 8 });
    arrayADT::arrayADT<int> arrayForIntersectionFour(8, 5, { 1, 18, 23, 7, 11 });

    arrayForIntersectionOne.Display();
    arrayForIntersectionTwo.Display();
    arrayForIntersectionOne.OperationIntersection(arrayForIntersectionTwo); // Intersection: 3 7
    arrayForIntersectionOne.Display();

    arrayForIntersectionThree.Display();
    arrayForIntersectionFour.Display();
    arrayForIntersectionThree.OperationIntersection(arrayForIntersectionFour); // Intersection: 1 23
    arrayForIntersectionThree.Display();

    std::cout << "DIFFERENCE: " << std::endl;
    arrayADT::arrayADT<int> arrayForDifferenceOne(8, 5, { 1, 3, 5, 7, 11 });
    arrayADT::arrayADT<int> arrayForDifferenceTwo(8, 6, { 2, 3, 6, 7, 13, 15 });
    arrayADT::arrayADT<int> arrayForDifferenceThree(8, 6, { 1, 3, 19, 23, 2, 8 });
    arrayADT::arrayADT<int> arrayForDifferenceFour(8, 5, { 1, 18, 23, 7, 11 });

    arrayForDifferenceOne.Display();
    arrayForDifferenceTwo.Display();
    arrayForDifferenceOne.OperationDifference(arrayForDifferenceTwo); // Difference: 1 5 11
    arrayForDifferenceOne.Display();

    arrayForDifferenceThree.Display();
    arrayForDifferenceFour.Display();
    arrayForDifferenceThree.OperationDifference(arrayForDifferenceFour); // Difference: 3 19 2 8
    arrayForDifferenceThree.Display();

    // arrayADT class gymnastic
    std::cout << "arrayADT gymnastic: " << std::endl;
    arrayADT::arrayADT<int> arrayGymnastic(8, 5, { 1, 3, 5, 7, 11 });
    arrayADT::arrayADT<int> arrayGymnasticTest(8, 3, { 5, 7, 11 });
    arrayADT::arrayADT<int> arrayGymnasticCopy(arrayGymnastic);
    arrayADT::arrayADT<int> arrayGymnasticAssigned(arrayGymnasticCopy);

    arrayGymnasticAssigned = arrayGymnasticTest;

    arrayGymnasticCopy.Display();
    arrayGymnasticAssigned.Display();

    return 0;
}