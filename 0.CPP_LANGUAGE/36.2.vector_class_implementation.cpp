#include <iostream>

template <typename T>
class Vector
{
public:
private: // Member Functions
    Vector()
    {
        reallocate(2);
    }

    ~Vector()
    {
        delete[] m_data;
    }

    void reallocate(size_t size)
    {
        /*
            1. Create New Memory in heap
            2. Copy old Memory to new memory
            3. Delete Old Memory
            4. Save New Memory Address in old pointer
        */
    }

private:       // Data
    T *m_data; // Pointer to Memory in Heap(Address of Space Allocated in Heap Memory)
    size_t capacity;
    size_t m_size;
};

int main()
{
    Vector<int> vec;

    return 0;
}

/*
1. Data is Stored in Heap
2. Could be Slow as On Reallocation a lot of things are done
3. Dynamic as new Heap Allocated Memory is allocated using OS system call during runtime
*/