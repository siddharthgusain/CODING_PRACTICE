#include <iostream>

int main()
{
    int arr[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}};

    int min_row = 0, min_col = 0, max_row = 3, max_col = 4;
    int total_elements = 4 * 5, count = 0;
    while (count < total_elements)
    {
        // print left wall of current ring
        for (int i = min_row; i <= max_row && count < total_elements; i++)
        {
            std::cout << arr[i][min_col] << "->";
            count++;
        }

        min_col++; // to change the ring

        // print bottom wall of current ring
        for (int i = min_col; i <= max_col && count < total_elements; i++)
        {
            std::cout << arr[max_row][i] << "->";
            count++;
        }

        max_row--; // to change ring

        // print right wall of current ring
        for (int i = max_row; i >= min_row && count < total_elements; i--)
        {
            std::cout << arr[i][max_col] << "->";
            count++;
        }

        max_col--;

        // print top wall of current ring
        for (int i = max_col; i >= min_col && count < total_elements; i--)
        {
            std::cout << arr[min_row][i] << "->";
            count++;
        }

        min_row++;
    }

    return 0;
}