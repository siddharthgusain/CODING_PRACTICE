#include <iostream>
#include <string>

bool is_palindrome(std::string substr)
{
    bool is_palindrome = true;
    for (int i = 0, j = substr.length() - 1; i <= j; i++, j--)
    {
        if (substr[i] != substr[j])
        {
            is_palindrome = false;
            break;
        }
    }
    return is_palindrome;
}

int main()
{
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j <= s.length(); j++)
        {
            std::string substr = s.substr(i, j - i);
            if (is_palindrome(substr))
                std::cout << substr << std::endl;
        }
    }
    return 0;
}