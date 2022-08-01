#include <iostream>

template <typename T, size_t s>
class Array
{
private:
    T m_data[s];

public:
    Array()
    {
        for (int i = 0; i < s; i++)
        {
            m_data[i] = 0;
        }
    }

    size_t size() const
    {
        return s;
    }

    T &operator[](size_t index)
    {
        return m_data[index];
    }
};

int main()
{
    Array<int, 5> arr;
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}