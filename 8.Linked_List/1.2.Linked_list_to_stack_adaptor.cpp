#include <iostream>
#include <forward_list>

class Stack
{
public:
    void push(int data)
    {
        this->singly_linked_list.push_front(data);
    }

    int pop()
    {
        if (this->size() == 0)
        {
            return -1;
        }
        int value = this->peek();
        this->singly_linked_list.pop_front();
        return value;
    }

    int peek()
    {
        if (this->size() == 0)
        {
            return -1;
        }
        return this->singly_linked_list.front();
    }

    int size()
    {
        int count = 0;
        for (const auto &item : this->singly_linked_list)
        {
            ++count; // Increment count for each element
        }
        return count; // Return the total count
    }

private:
    std::forward_list<int> singly_linked_list;
};

void main()
{
    Stack st;
    st.push(1);
    st.push(2);
    std::cout << st.peek() << std::endl;
    std::cout << st.pop() << std::endl;
    std::cout << st.size();
}