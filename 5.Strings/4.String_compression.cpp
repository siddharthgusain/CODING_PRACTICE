#include <iostream>
#include <string>

std::string compression1(std::string str)
{
    std::string final_string = "";
    final_string.push_back(str.at(0));

    for (int i = 1; i < str.length(); i++)
    {
        char curr_char = str.at(i);
        char prev_char = str.at(i - 1);

        if (curr_char != prev_char)
            final_string.push_back(str.at(i));
    }
    return final_string;
}

std::string compression2(std::string str)
{
    std::string final_string = "";
    final_string.push_back(str.at(0));
    int count = 1;

    for (int i = 1; i < str.length(); i++)
    {
        char curr_char = str.at(i);
        char prev_char = str.at(i - 1);

        if (curr_char == prev_char)
            count++;
        else
        {
            if (count > 1)
            {
                char c = '0' + count;
                final_string.push_back(c);
                count = 1;
            }

            final_string.push_back(curr_char);
        }
    }

    if (count > 1)
    {
        char c = '0' + count;
        final_string.push_back(c);
    }

    return final_string;
}

int main()
{
    std::string str;
    std::cin >> str;

    std::cout << "Compression 1:" << compression1(str);
    std::cout << "Compression 2:" << compression2(str);

    return 0;
}