#include <iostream>

static int a = 10;
/*
this variable is visible or can be accessed only inside
this file/transation unit
*/

static void print()
{
    std::cout << "hello";
}

/*
this function is visible or can be accessed only inside
this file/transation unit
*/

/*
global static variables are only accessible inside this file only
If we create another file having varaible with same name  , linker will
not give error as this "a" is only accessible inside this file.
Same goes for the static functions
*/

class Player
{
    static int a; // shared by every object of this class
    int b;

public:
    Player(int b)
    {
        this->a = 0;
        this->b = b;
    }
    void increment()
    {
        this->a = 10;
        this->b += 1;
    }
    void print()
    {
        std::cout << this->a << " " << this->b << std::endl;
    }
};

int Player::a;
// this is important to let compiler know about this static varaible
// "a" is not considered as member of class

int main()
{
    Player p1(10); // "a" varaible is shared but not "b"
    Player p2(20);
    p1.increment();
    p2.increment();
    p1.print();
    p2.print();
    return 0;
}