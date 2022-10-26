#include <iostream>

void print_subsequence(std::string ques, std::string ans)
{
    if (ques.length() == 0)
    {
        std::cout << ans << std::endl;
        return;
    }

    char ch = ques.at(0);
    std::string rest = ques.substr(1);

    print_subsequence(rest, ans + "_ "); // dont include the character
    print_subsequence(rest, ans + ch);   // include the character
}

int main()
{
    std::string str;
    std::cin >> str;

    print_subsequence(str, "");
    return 0;
}

/*
Question :- https://nados.io/question/print-subsequence
Article:- https://nados.io/article/print-subsequence
Video:- https://www.youtube.com/watch?v=Ke8TPhHdHMw
*/
