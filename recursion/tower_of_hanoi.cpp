#include <iostream>

// Problem:
// There are three towers called A, B and C
// on the tower A there are n disks each smaller than the previous
// the task is to move the disks from tower A to the tower C by 
// using (or by help) of tower B
// The rules are as follows:
// 1) Only one disk can be moved at a time.
// 2) Each move consists of taking the upper disk from one of the stacks and
//     placing it on top of another stack or on an empty rod.
// 3) Larger disks cannot be kept on top of the smaller ones. 
// https://en.wikipedia.org/wiki/Tower_of_Hanoi

// Solution:
// We should start by dividing a problem to smaller bits
// Analyze how to move the disks in the following cases:
// - 1 Disk 
//      -- 1) Move a disk from A to C
// - 2 Disks
//      -- 1) Move a disk from A to B
//      -- 2) Move a disk from A to C
//      -- 3) Move a disk from B to C
// - 3 Disks
//      -- 1) Move two disks from A to B
//      -- 2) Move a disk from A to C
//      -- 3) Move two disks from B to C
// We can now generalize the solution to the problem
// - n Disks
//      -- 1) Move (n - 1) disks from A to B
//      -- 2) Move a disk from A to C
//      -- 3) Move (n - 1) disks from B to C
enum class Towers
{
    towerA,
    towerB,
    towerC
};

std::ostream& operator<<(std::ostream& os, const Towers& tower)
{
    switch(tower)
    {
        case Towers::towerA:
            os << "A";
            break;
        case Towers::towerB:
            os << "B";
            break;
        case Towers::towerC:
            os << "C";
            break;
        default:
            os << "Something went wrong.";
            break;
    }

    return os;
}

// Time complexity ->
// we need to analyse at least one problem for 'n' number of disks to analyse time complexity
// we will come to a conclusion that it is 
// n = 3, calls = 15 -> 1 + 2 + 2^2 + 2^3 = 2^4 - 1
// n = n, implies -> 1 + 2 + 2^2 + 2^3  + ... = 2^n - 1
// o(2^n) -> which is a time complexity for recurisive functions that are calling
// their self for two times. 
void towerOfHanoi(const unsigned int noOfDisks, const Towers towerA, 
                    const Towers towerB, const Towers towerC)
{
    if(noOfDisks >= 1)
    {
        towerOfHanoi(noOfDisks - 1, towerA, towerC, towerB);
        std::cout << "(" << towerA << ", " << towerC << ")" << std::endl;
        towerOfHanoi(noOfDisks - 1, towerB, towerA, towerC);
    }
}

int main()
{
    Towers A = Towers::towerA, B = Towers::towerB, C = Towers::towerC;
    unsigned int noOfDisks = 3;

    std::cout << "Tower of Hanoi steps for " << noOfDisks << " disks:" << std::endl;
    towerOfHanoi(noOfDisks, A, B, C);

    return 0;
}