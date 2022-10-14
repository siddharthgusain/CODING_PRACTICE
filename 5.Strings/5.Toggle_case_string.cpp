#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);
        if (ch >= 'a' && ch <= 'z')
        {
            char upper = (char)('A' + ch - 'a');
            str[i] = upper;
        }
        else
        {
            char lower = (char)('a' + ch - 'A');
            str[i] = lower;
        }
    }

    std::cout << str;
    return 0;
}

/*
Question :- https://nados.io/question/toggle-optica-document
Article :- https://nados.io/article/toggle-case
Video:- https://www.youtube.com/watch?v=VQnWqpHpKnE
*/