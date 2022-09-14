// how to make const char pointer to modifiable char array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::cout << "const char pointer to modifiable char array\n";

    // You need to be able to modify the value at the adress of a constant char pointer.
    // We will solve this problem by making a regular pointer and a regular pointer to the same adress.
    // Then we can modify the content at the adress trough the regular pointer;
    // however, we can not modify the actual size of the alocated memmory.

    // Because we canot change the actual size, of the value at the adress, 
    // we need to have a size (number of chars) constant 
    const int MAX_CHAR_N{ 100 };
    
    // Now we create something that is easily put into a char array (string),
    // and is shorter than the constant number of chars we have chosen
    std::string s{ "abc" };

    // Here we create the char array on the heap with pointer we can use to modify the array,
    // and we create the constant pointer that same char array that we can not use to modify the array (but you need)
    char* pRandW{ new char[MAX_CHAR_N] };
    const char* pR{ pRandW };
    std::cout << "\n";
    std::cout << "\tconst char* pR;";
    std::cout << "\n";

    // Now we put the string into the char array.
    // The end of a string is signified by a null char ('\0');
    // therefor, we need to make shure that we put '\0' at the end of the content we put into the char array
    for (int i{ 0 }; i <= s.length(); i++)
    {
        if (i == s.length())
        {
            pRandW[i] = '\0';
        }
        else
        {
            pRandW[i] = s[i];
        }
    }

    // Now we can see that the const char* array is interpreted the same as the string content 
    std::cout << "\n";
    std::cout << "\tcout << pR; -> ";
    std::cout << pR;
    std::cout << "\n";

    // Now we modify the string
    s = "Jesus is my lord";

    // Then we put the content of the modified string into the char array
    for (int i{ 0 }; i <= s.length(); i++)
    {
        if (i == s.length())
        {
            pRandW[i] = '\0';
        }
        else
        {
            pRandW[i] = s[i];
        }
    }
    std::cout << "\n\t The the array was modified!\n";

    // Now we can see that the pointed to content of the const char* is modified!
    std::cout << "\n";
    std::cout << "\tcout << pR; -> ";
    std::cout << pR;
    std::cout << "\n";

    // Remember that we can not add more than the MAX_CHAR_N number of char into the array 
    std::cout << "\nSuccess!\n";

}
