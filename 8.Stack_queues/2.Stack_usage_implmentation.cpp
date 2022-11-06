#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(4);
    st.push(6);
    cout << "TOP:" << st.top() << endl;
    cout << "SIZE:" << st.size() << endl;
    // pop end element
    st.pop();

    cout << "TOP:" << st.top() << endl;
    cout << "SIZE:" << st.size() << endl;
    // with pointers
    stack<int> *ptr = new stack<int>[5];

    (*ptr).push(4);
    cout << "TOP" << (*ptr).top();
    return 0;
}