#include <iostream>
#include <vector>

// static arrays -> in stack
// dynamically allocated arrays(pointer to space in memory) --> in heap
// dynamic arrays (vector) -> in heap

int main()
{
    int arr[5];                       // static allocated array in stack i.e 5 * sizeof(int), arr is just a pointer to base
    std::cout << arr << std::endl;    // address of first array element or base address
    std::cout << *arr << std::endl;   // value at base address / first element
    std::cout << arr[1] << std::endl; // arrays 2nd element (behind the scenes offset of 2nd element is calculated using base address only)
    int *ptr = new int[5];            // dynamic memory allocation (5 * sizeof(int) bytes of memory allocated by OS and pointer to starting address is returned)
    *ptr = 10;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    std ::cout << *(ptr + 3) << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5}; // template class vector, vec is object
    vec.push_back(10);
    std::cout << vec[0] << std::endl;
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    delete ptr;
    return 0;
}