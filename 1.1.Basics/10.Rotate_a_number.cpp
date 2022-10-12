#include <iostream>
#include <math.h>

int find_rotated_number(int times_to_rotate, int total_digits, int number)
{
    int divisor = pow(10, times_to_rotate);
    int multiplier = pow(10, total_digits - times_to_rotate);
    int right_partition = number % divisor;
    int left_partition = number / divisor;
    int rotated_number = right_partition * multiplier + left_partition;
    return rotated_number;
}

int main()
{
    int number, rotated_number;
    int total_digits = 0, times_to_rotate;

    std::cin >> number >> times_to_rotate;

    int temp = number;

    while (temp)
    {
        temp = temp / 10;
        total_digits++;
    }

    times_to_rotate = times_to_rotate % total_digits;
    
    if (times_to_rotate == 0)
        std::cout << number;
    else if (times_to_rotate > 0) // positive rotate
    {
        std::cout << find_rotated_number(times_to_rotate, total_digits, number);
    }
    else // negative rotate
    {
        times_to_rotate = times_to_rotate + total_digits;
        std::cout << find_rotated_number(times_to_rotate, total_digits, number);
    }
    return 0;
}

/*
Time Comp:- O(log10(number))
Space Comp:- O(1)
*/

/*
Problem:- https://nados.io/question/rotate-a-number
Articles:- https://nados.io/article/rotate-a-number
Videos:- https://www.youtube.com/watch?v=lt8oCGqYMGg
*/