#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    std::string final_result = "";

    final_result.push_back(str.at(0));
    char gap_char;
    for (int i = 1; i < str.length(); i++)
    {
        char curr = str.at(i);
        char prev = str.at(i - 1);

        int gap = curr - prev;

        if (gap < 0) // negative gap case handling
        {
            std::string negative_char = "-";
            gap_char = '0' + (-gap);
            negative_char.push_back(gap_char);
            final_result.append(negative_char);
        }
        else // if gap is positive conversion to character is easy
        {
            gap_char = '0' + gap;
            final_result.push_back(gap_char);
        }
        final_result.push_back(curr);
    }

    std::cout << final_result;

    return 0;
}

/*
Question :- https://nados.io/question/string-with-difference-of-every-two-consecutive-characters
Article :- https://nados.io/article/string-with-difference-of-every-two-consecutive-characters-in-java
Video:- https://www.youtube.com/watch?v=PHtNm0B9Ig4
*/