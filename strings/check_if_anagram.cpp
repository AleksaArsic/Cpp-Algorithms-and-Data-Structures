#include <iostream>
#include <memory>

unsigned int findLengthOfAString(const char* array)
{
    int len = 0;

    //for(len = 0; array[len] != '\0'; ++len);
    while(array[len++] != '\0');

    return len - 1;
}

// Two strings are anagram if they are formed from same alphabet characters
// Two strings cannot be anagram if they are not of the same size.
// If there are duplicate characters we need to count them and that 
// will leave us with the time complexity of o(n^2).
// If space is not a problem, then it is better to go with the 
// hash table as it will reduce the time complexity to o(n)
bool isAnagram(const char* firstArray, const char* secondArray)
{
    constexpr int noOfAlpabetCharacters = 25;
    std::unique_ptr<int[]> hashTable = std::make_unique<int[]>(noOfAlpabetCharacters);

    if(findLengthOfAString(firstArray) != findLengthOfAString(secondArray))
    {
        return false;
    }

    for(unsigned int i = 0; firstArray[i] != '\0'; ++i)
    {
        hashTable[(firstArray[i] - 'a')]++;
    }

    for(unsigned int i = 0; secondArray[i] != '\0'; ++i)
    {
        hashTable[(secondArray[i] - 'a')]--;

        if(hashTable[secondArray[i] - 'a'] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char firstArray[] = "observe";
    char secondArray[] = "verbose";

    if(isAnagram(firstArray, secondArray))
    {
        std::cout << "Strings form an anagram." << std::endl;
    }
    else
    {
        std::cout << "Strings do not form an anagram." << std::endl;
    }

    return 0;
}