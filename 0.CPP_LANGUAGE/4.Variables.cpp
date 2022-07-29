#include <iostream>

int main()
{
    int a = 10; // a is variable of type int(size of int depend on OS and CPU architecture)
    std::cout << a;
    float b = 1.222;
    char c = 'a';
    long d = 11121313;
    long long e = 201230103;
    unsigned int f = 10201993;
    signed int g = -122112;
    return 0;
}

// variables are just space(bytes) in memory to store data.
/*
 Data types ares just way to tell compiler how much size of memory is required which further is allocated according
to operating system and computer architecture.
Inbuilt Data type like int , float are reserved keyword in compiler , so when source file is parsed ,the size is
known by compiler
User defined data type like structure and class defines block which describes the total size required by the object
according to that compiler generates assembly code.
AS CPP is statically typed , means if we try to put wrong data type into a variable declared , then it will give
error thats how it is written. so we get error/bugs in compile time , rather than runtime.
*/