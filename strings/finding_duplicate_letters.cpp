#include <iostream>
#include <memory>

unsigned int findLengthOfAString(const char* array)
{
    int len = 0;

    //for(len = 0; array[len] != '\0'; ++len);
    while(array[len++] != '\0');

    return len - 1;
}

void stringToLowercase(char* array)
{
    for(unsigned int i = 0; array[i] != '\0'; ++i)
    {
        if(array[i] >= 'A' && array[i] <= 'Z')
        {
            array[i] += ('a' - 'A'); // ('a' - 'A') = 32
        }
    } 
}

void findDuplicateLetters(char* array)
{
    constexpr unsigned int alphabetSize = 25;
    std::unique_ptr<unsigned int[]> hashTable = std::make_unique<unsigned int[]>(alphabetSize);

    stringToLowercase(array);

    for(unsigned int i = 0; array[i] != '\0'; ++i)
    {
        hashTable[array[i] - 'a']++;
    }

    for(unsigned int i = 0; i < alphabetSize; ++i)
    {
        if(hashTable[i] > 1)
        {
            std::cout << "Duplicate letter - " << static_cast<char>(i + 'a') << " - found: " << hashTable[i] << std::endl;
        }
    }

}


// By using bitwise method we can know if a letter is duplicate, but we cannot count it
// We need a 32bit variable for hashing and masking as there are 25 letters of the english alphabet.
// As int can be interpreted as 2 bytes by some compilers, take the long int for masking
void findDuplicateLettersBitwise(char* array)
{
    stringToLowercase(array);

    long int hash = 0;
    long int mask = 1;

    for(unsigned int i = 0; array[i] != '\0'; ++i)
    {
        // Take each letter and check if the corresponding bit in hash is already set
        // by doing bitwise and operation on it with the mask shifted by the number of bits that 
        // represent the alphabet letter
        mask = 1;
        mask = (mask << (array[i] - 'a'));

        if((hash & mask) > 0)
        {
            std::cout << "The letter \'" << array[i] << "\' is a duplicate." << std::endl;
        }
        else
        {
            hash |= mask;
        }
    }

}

int main()
{
    char array[] = "finding";

    findDuplicateLetters(array);
    findDuplicateLettersBitwise(array);

    return 0;
}