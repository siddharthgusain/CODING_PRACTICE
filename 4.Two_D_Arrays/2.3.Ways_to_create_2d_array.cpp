#include <iostream>
#include <vector>
#include <array>

int main()
{
    /*
        BASIC STATIC ARRAY -> Stack Allocation
        Size should be given at compile time
    */
    int arr[2][3] = {0};

    std::cout << "STATIC 2D ARRAY ALLOCATED ON STACK" << std::endl;

    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << arr[row][col] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "--------------------------------" << std::endl;

    std::cout << "STATIC 2D ARRAY ALLOCATED ON STACK USING ARRAY CLASS" << std::endl;
    std::array<std::array<int, 3>, 2> arr_obj = {0};

    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << arr_obj[row][col] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "--------------------------------" << std::endl;

    /*
        Dynamic Array using Heap Memory
        -> Array of Pointers
        -> Size Can be Given at runtime
    */
    int rows, cols;
    std::cout << "DYNAMIC 2D ARRAY ALLOCATED ON HEAP" << std::endl;
    std::cout << "ENTER ROWS AND COLS:";
    std::cin >> rows >> cols;
    int **double_pointer = new int *[rows]; // Allocated Space for pointers equal to rows (1D Array of Pointers)
    // E.g rows =2 , 2 Pointer Block of Memory

    // Allocation
    for (int i = 0; i < rows; i++)
    {
        double_pointer[i] = new int[cols]; // Creating New Heap Memory of Col Size(1D array of values) -> This contains Actual Elements
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            double_pointer[row][col] = 1;
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            std::cout << double_pointer[row][col] << "\t";
        }
        std::cout << "\n";
    }

    // Deallocation
    for (int i = 0; i < rows; i++)
    {
        delete[] double_pointer[i]; // Deleting Individual Row Pointer Memory -> i.e Column Memory
    }

    delete[] double_pointer;

    std::cout << "--------------------------------" << std::endl;

    std::cout << "DYNAMIC 2D ARRAY ALLOCATED ON HEAP USING STL VECTOR CLASS WHICH GIVES USEFUL METHODS" << std::endl;

    std::vector<std::vector<int>> vec(rows, std::vector<int>(cols));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            vec[row][col] = 2;
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            std::cout << vec[row][col] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}

/*
Two ways :
1. Stack Allocation Static Array -> Normal array or array STL class
2. Heap Allocated Array -> Using pointer  or Vector STL class
*/