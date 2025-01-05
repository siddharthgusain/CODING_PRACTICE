#include <iostream>

void tower_of_hanoi(int num_of_disk, char source, char destination, char helper)
{
    if (num_of_disk == 0)
        return;
    tower_of_hanoi(num_of_disk - 1, source, helper, destination);
    std::cout << "Mov " << source << "->" << destination << std::endl;
    tower_of_hanoi(num_of_disk - 1, helper, destination, source);
}

int main()
{
    int num_of_disk;
    char source, destination, helper;
    std::cin >> num_of_disk >> source >> destination >> helper;

    tower_of_hanoi(num_of_disk, source, destination, helper);
    return 0;
}