#include <iostream>

void test()
{
    std::cout << "hello" << std::endl;
}

int main()
{
    auto a = &test; // address of function to "a"
    a();
    void (*ptr)() = &test;
    (*ptr)();
    return 0;
}

/*
-> function name is actually a address in machine code which corresponds to
address of function inside code segment of a process , so functions have address
, thats why function pointer is just a variable pointing to function address

-> function pointer are more usefull for asynchronous programming , as they are a form of
callbacks that we use frequently in GUI programming.
*/