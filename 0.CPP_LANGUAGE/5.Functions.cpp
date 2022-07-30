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

/*
-> Functions have two things :-
1. declaration / function signature --> for compiler to know that this function exists and its the syntax
2. definition :- the actual body of function with data and instruction inside it.
*/

/*
- > Declartion of function should be always present inside CPP file , it is required for compiler to genrate object code

-> However actual body of function may or may not be present in the same file , it could be in some other file or it
could be present in dynamic linked libraries and is taken care by linker and loader and operating system software

-> but point to be noted , function body is always present somewhere may be in your source code or may be in operating
system code or present in some predefinded location in harddisk.
*/