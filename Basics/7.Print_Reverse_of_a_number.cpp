#include <iostream>

int main()
{
    int number;
    std::cin >> number;
    while (number)
    {
        int digit = number % 10;
        std::cout << digit << std::endl;
        number = number / 10;
    }
}

/*
Time Comp:- O(log10(number))
Space Comp:- O(1)
*/

/*
Problem:-https://www.pepcoding.com/resources/online-java-foundation/getting-started/reverse-a-number-official/ojquestion
Articles:- https://www.pepcoding.com/resources/online-java-foundation/getting-started/reverse_a_number/topic
Videos:- https://www.youtube.com/watch?v=D_yKIOnhMRc&list=TLGGVMmfSBfrFEswOTA2MjAyMg
*/