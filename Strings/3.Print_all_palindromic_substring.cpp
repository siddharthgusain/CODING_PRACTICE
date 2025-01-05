#include <iostream>
#include <string>

bool isPalindrome(std::string str)
{
    for (int i = 0, j = str.length() - 1; i < str.length() / 2; i++, j--)
    {
        if (str.at(i) != str.at(j))
            return false;
    }

    return true;
}

int main()
{
    std::string str;
    std::cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length() - 1; j++)
        {
            std::string substr = str.substr(i, j);
            if (isPalindrome(substr))
                std::cout << substr << std::endl;
        }
    }
}

// A substring is a contiguous sequence of characters within a string.