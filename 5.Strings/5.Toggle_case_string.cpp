#include <iostream>
#include <string>

std::string convert_case(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        { // IF UPPERCASE
            str[i] = str[i] + 'a' - 'A';
        }
        else // LOWERCASE
        {
            str[i] = str[i] + 'A' - 'a';
        }
    }

    return str;
}

int main()
{
    std::string str;
    std::cin >> str;

    str = convert_case(str);

    std::cout << str;

    return 0;
}