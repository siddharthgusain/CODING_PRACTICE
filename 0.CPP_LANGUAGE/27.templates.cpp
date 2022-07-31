#include <iostream>

template <typename T>
struct Player
{
    T x;
    T y;
};

int main()
{
    Player<int> p;
    Player<float>;
    p.x = 10;
    p.y = 20;
    return 0;
}

/*
-> templates are just decalration for generics to reduce code redundancy
-> Compiler genrates specific class type internnally based on template type provided by us in source code
*/