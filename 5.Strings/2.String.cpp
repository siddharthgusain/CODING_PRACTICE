#include <iostream>
#include <string> // can be ommited as in my compiler iostream file contains string too , but may not work in other compiler libraries

int main()
{
    char str[] = "sid";
    char str1[] = {'s',
                   'i',
                   'd',
                   '\0'};     // Stored in Stack
    std::string str3 = "sid"; // note here string is a class written inside library, so str3 is an object
    std::cout << str << std::endl;
    std::cout << str1 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << str3.at(0) << std::endl; // classes makes the source code more readable and maintainable

    return 0;
}

/*
 * String class stores Data in Heap => Dynamic Size
 * Normal C++ String is stored in Stack -> Static Size
 */