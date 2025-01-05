#include <iostream>
#include <string>

std::string compression_one(std::string str)
{
    if (str.length() == 0)
    {
        std::cout << "Empty String";
        return "";
    }
    else if (str.length() == 1)
    {
        return str;
    }

    std::string compressed_str(1, str.at(0));

    for (int i = 1; i < str.length(); i++)
    {
        char curr = str.at(i);
        char prev = str.at(i - 1);

        if (curr != prev)
            compressed_str += curr;
    }

    return compressed_str;
}

std::string compression_two(std::string str)
{
    if (str.length() == 0)
    {
        std::cout << "Empty String";
        return "";
    }
    else if (str.length() == 1)
    {
        return str + std::to_string(1);
    }

    std::string compressed_str(1, str.at(0));
    int count = 1;

    for (int i = 1; i < str.length(); i++)
    {
        char curr = str.at(i);
        char prev = str.at(i - 1);

        if (curr != prev)
        {
            std::string stringify_count = std::to_string(count);
            compressed_str += stringify_count + curr;
            count = 1;
        }
        else
            count++;
    }

    if (count >= 1)
    {
        std::string stringify_count = std::to_string(count);
        compressed_str += stringify_count;
    }

    return compressed_str;
}

int main()
{
    std::string str;
    std::cin >> str;

    std::cout << compression_one(str) << std::endl;
    std::cout << compression_two(str) << std::endl;
}