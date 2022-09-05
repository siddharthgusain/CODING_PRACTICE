#include <iostream>
#include <math.h>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    int limit = pow(2, vec.size()); // calculating the number of subsets
    for (int i = 0; i < limit; i++)
    {
        // convert i to binary and use 0's and 1's
        // to check if an array's element is to be printed or not
        std::string set = "";
        // we make use of set to print in required order
        int temp = i;
        // we store i because we need to use value
        // of i without manipulating the actual i
        // as i is the outer loop iterator
        for (int j = vec.size() - 1; j >= 0; --j)
        {
            // calculating the binary, extracting //
            //  the remainder one and by one
            //  and putting required element
            //  in the String to be printed.
            int rem = temp % 2;
            temp = temp / 2;
            if (rem == 0) // nothing to be printed
            {
                set = "-    " + set;
            }
            else
            {
                // we print the element, so we add it to our answer string
                set = vec[j] + "    " + set;
            }
        }
        std::cout << set << std::endl;
        // printing the required pattern line-by-line
    }
}

/*
Time Comp :- O((2^n)*n)
space comp:- O(n);
/*

/*
Problem:- https://nados.io/question/subsets-of-array
Articles:-https://nados.io/article/subsets-of-array
Videos:- https://www.youtube.com/watch?v=vk8sfizNtsY
*/