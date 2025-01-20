#include <iostream>

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

// Comparation of strings can be done by putting the string in the same "case" and 
// determining if all the characters are the same, if not the same we can check 
// which character is greater and based on that determine which string is greater or smaller
unsigned int checkIfEqual(char* firstArray, char* secondArray)
{
    stringToLowercase(firstArray);
    stringToLowercase(secondArray);

    unsigned int i, j;

    for(i = 0, j = 0; firstArray[i] != '\0' && secondArray[j] != '\0'; ++i, ++j)
    {
        if(firstArray[i] != secondArray[j])
        {
            break;
        }
    }

    if (firstArray[i] == secondArray[j])
    {
        return 0;
    }
    else if (firstArray[i] < secondArray[j])
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


// Without making copies or changing the original string we check if the 
// given string array is a palindrome.
// All characters in the string need to be of the same "case" (lowercase or uppercase)
// If we want to be case insensitive we need to modify the existing string or make a copy of it.
bool checkIfPalindrome(const char* array)
{
    unsigned int j = 0;

    for(j = 0; array[j] != '\0'; ++j);

    j = j - 1;
    for(unsigned int i = 0; i < j; ++i, --j)
    {
        if(array[i] != array[j])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char array[] = "anavolimilovana";
    char firstArray[] = "aleksa";
    char secondArray[] = "aa";

    if (checkIfPalindrome(array))
    {
        std::cout << "The string: \"" << array << "\" is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The string: \"" << array << "\" is not a palindrome." << std::endl;
    }

    if (checkIfEqual(firstArray, secondArray) == 0)
    {
        std::cout << "Strings are equal." << std::endl;
    }
    else if (checkIfEqual(firstArray, secondArray) == 1)
    {
        std::cout << "The first string is smaller than the second string." << std::endl;
    }
    else 
    {
        std::cout << "The first string is greater than the second string." << std::endl;
    }

    return 0;
}