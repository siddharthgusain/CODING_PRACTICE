#include <iostream>

void tower_of_hanoi(int num_disk, char tower_1, char tower_2, char tower_3)
{
    if (num_disk == 0)
        return;

    tower_of_hanoi(num_disk - 1, tower_1, tower_3, tower_2);
    std::cout << num_disk << ":[" << tower_1 << "->" << tower_2 << "]" << std::endl;
    tower_of_hanoi(num_disk - 1, tower_3, tower_2, tower_1);
}

int main()
{
    int num_of_disk;
    std::cin >> num_of_disk;

    char tower_1, tower_2, tower_3;
    std::cin >> tower_1 >> tower_2 >> tower_3;

    tower_of_hanoi(num_of_disk, tower_1, tower_2, tower_3);

    return 0;
}

/*
Question :- https://nados.io/question/tower-of-hanoi
Article :- https://nados.io/article/tower-of-hanoi
Videos:- https://www.youtube.com/watch?v=QDBrZFROuA0
*/