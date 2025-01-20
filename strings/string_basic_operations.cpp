#include <iostream>

unsigned int findLengthOfAString(const char* array)
{
    int len = 0;

    //for(len = 0; array[len] != '\0'; ++len);
    while(array[len++] != '\0');

    return len - 1;
}

void stringToUppercase(char* array)
{
    for(unsigned int i = 0; array[i] != '\0'; ++i)
    {
        if(array[i] >= 'a' && array[i] <= 'z')
        {
            array[i] -= ('a' - 'A'); // ('a' - 'A') = 32
        }
    } 
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

unsigned int countWords(char* array)
{
    unsigned int wordCount = 0;
    unsigned int i;
    for(i = 1; array[i] != '\0'; ++i)
    {
        if(array[i - 1] != ' ' && array[i] == ' ')
        {
            wordCount++;
        }
    } 

    if(i > 1) wordCount++;

    return wordCount;
}

bool validateString(const char* array)
{
    for(unsigned int i = 0; array[i] != '\0'; ++i)
    {
        if(!(array[i] >= 'a' && array[i] <= 'z') && 
           !(array[i] >= 'A' && array[i] <= 'Z') && 
           !(array[i] >= '0' && array[i] <= '9') &&
           !(array[i] == ' '))
        {
            return false;
        }
    }

    return true;
}

void reverseString(char* array)
{
    //unsigned int length = findLengthOfAString(array);
    unsigned int j = 0;
    char temp;

    for(unsigned int i = 0; array[i] != '\0'; ++i, ++j);

    j = j - 1;
    for(unsigned int i = 0; i < j; ++i, --j)
    {
        temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

int main()
{
    // In C++ it is better to use string objects instead of C-like strings
    // The representation of C-like string 
    //char array[10] = { 'p', 'y', 't', 'h', 'o', 'n', '\0'};
    //char array[] = { 'p', 'y', 't', 'h', 'o', 'n', '\0'};
    char array[] = "aleksa arsica"; // has '\0' automatically added

    std::cout << "Length of an string: " << findLengthOfAString(array) << std::endl;
    stringToUppercase(array);
    std::cout << "stringToUppercase: " << array << std::endl;
    stringToLowercase(array);
    std::cout << "stringToLowercase: " << array << std::endl;
    std::cout << "Word count: " << countWords(array) << std::endl;

    if(validateString(array))
    {
        std::cout << "String: \"" << array << "\" is a valid string." << std::endl;
    }
    else
    {
        std::cout << "String: \"" << array << "\" is not a valid string." << std::endl;
    }

    reverseString(array);
    std::cout<< "String: reversed: \"" << array << "\"" << std::endl;

    return 0;
}