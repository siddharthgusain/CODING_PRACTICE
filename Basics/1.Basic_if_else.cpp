#include <iostream>

int main()
{
    int marks;
    std::cin >> marks;
    if (marks > 90)
        std::cout << "Excellent";
    else if (marks > 80 && marks <= 90)
        std::cout << "Good";
    else if (marks >= 0 && marks <= 80)
        std::cout << "Average";
    else
        std::cout << "Invalid Input";

    return 0;
}