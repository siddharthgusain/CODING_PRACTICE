#include <iostream>

int main()
{
    int arr[4][5] = {
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0}};

    int direction = 0; // [0,1,2,4] --> [east,south,west,north]
    int i = 0, j = 0;  // entry point

    while (true)
    {
        direction = (direction + arr[i][j]) % 4;
        if (direction == 0)
        { // east
            j++;
        }
        else if (direction == 1)
        { // south

            i++;
        }
        else if (direction == 2)
        { // west
            j--;
        }
        else if (direction == 3)
        { // north
            i--;
        }

        if (i < 0)
        {
            i++;
            break;
        }
        else if (j < 0)
        {
            j++;
            break;
        }
        else if (i == 4)
        {
            i--;
            break;
        }
        else if (j == 5)
        {
            j--;
            break;
        }
    }

    std::cout << "Exit Point:" << i << "," << j;

    return 0;
}

/*
Problem:- https://nados.io/question/exit-point-of-a-matrix
Articles:-https://nados.io/article/exit-point-of-a-matrix
Videos:-https://www.youtube.com/watch?v=FUBlb360kqU
*/