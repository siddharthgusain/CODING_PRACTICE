#include <iostream>

void print(int a) // user defined functions
{
    std::cout << a; // cout is a library ostream object which in turn has system call inside it
} // system call are functions/Routines written inside OS kernel

int main()
{
    int a = 10;
    print(a); // function call
    return 0;
}

// Functions are just block of instruction
// Used for reusability
// used for modularity and maintainability