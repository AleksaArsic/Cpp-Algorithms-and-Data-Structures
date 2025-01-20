#include <iostream>
#include <memory>
#include <algorithm>

// Finding all permutations of the string is equal to n!
// where n denotes the length of the string
// The method used here is a brute force method 
// with back tracking and recursion
// The tree is called state space tree
//          |
//  A       B       C
// B  C    A C     A  B
// C  B    C A     B  A
// In the example the n = 3, therefore there are 
// 3! permutations. 3! = 6. 

constexpr unsigned int maximalStringSize = 10;

void findAllStringPermutations(const unsigned int k, const char* array)
{
    static std::unique_ptr<unsigned int[]> hash = std::make_unique<unsigned int[]>(maximalStringSize);
    static char result[maximalStringSize];

    if(array[k] == '\0')
    {
        result[k] = '\0';

        std::cout << result << std::endl;
        return;
    }
    else
    {
        for(unsigned int i = 0; array[i] != '\0'; ++i)
        {
            if(hash[i] == 0)
            {
                result[k] = array[i];
                hash[i]++;
                findAllStringPermutations(k + 1, array);
                hash[i]--;
            }
        }
    }
}

void findAllStringPermutationsSwaping(unsigned int l, unsigned int h, char* array)
{
    if(l == h)
    {
        std::cout << array << std::endl;
    }
    else
    {
        for(unsigned int i = l; i < h; ++i)
        {
            std::swap(array[l], array[i]);
            findAllStringPermutationsSwaping(l + 1, h, array);
            std::swap(array[l], array[i]);
        }
    }

}

int main()
{
    constexpr int length = 4;
    char array[length] = "ABC";

    findAllStringPermutations(0, array);
    std::cout << std::endl;
    findAllStringPermutationsSwaping(0, length - 1, array);

    return 0;
}