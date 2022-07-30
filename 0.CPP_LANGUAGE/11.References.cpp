#include <iostream>

void increment(int &ref)
{
    ref++;
}

int main()
{
    int a = 10;
    int &ref = a; // ref is alias for "a", can be used for large variable name
    increment(a);
    std::cout << ref;
    return 0;
}