#include <iostream>
#include <string>

std::string find_consecutive_diff(const std::string &str)
{
    if (str.empty())
        return "";

    std::string result;
    result += str[0];

    for (int i = 1; i < str.length(); i++)
    {
        int diff = str[i] - str[i - 1];
        result += std::to_string(diff);
        result += str[i];
    }

    return result;
}

int main()
{
    std::string str;
    std::cin >> str;

    str = find_consecutive_diff(str);

    std::cout << str << std::endl;

    return 0;
}