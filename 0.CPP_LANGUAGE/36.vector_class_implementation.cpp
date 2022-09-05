#include <iostream>

template <typename T>
class Vector
{
public:
    Vector()
    {
        reallocate(2); // default size of vector = 2
    }

    void push_back(const T &value)
    {
        if (m_size >= m_capacity)
        {
            reallocate(m_capacity + m_capacity / 2);
        }

        m_data[m_size] = value;
        m_size++;
    }

    size_t size() const { return m_size; }

    const T &operator[](size_t index) const
    {
        return m_data[index];
    }

    T &operator[](size_t index)
    {
        return m_data[index];
    }

private:
    void reallocate(size_t new_capacity)
    {
        // 1.Allocate a new block of memory
        // 2. Copy the old to new memory
        // 3. Delete old memory
        T *new_block = new T[new_capacity];

        if (new_capacity < m_size)
            m_size = new_capacity;

        for (size_t i = 0; i < m_size; i++)
            new_block[i] = m_data[i];

        delete[] m_data;
        m_data = new_block;
        m_capacity = new_capacity;
    }

private:
    T *m_data = nullptr;
    size_t m_size = 0;
    size_t m_capacity = 0;
};

int main()
{
    Vector<std::string> vec;
    vec.push_back("hello");
    vec.push_back("world");
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}