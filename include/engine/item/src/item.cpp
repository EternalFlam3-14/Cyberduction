#include <random>
#include <iostream>

void Itemise()
{
    srand(time(NULL));
    int A[5];
    for (auto element : A)
    {
        element = rand() % 1 + 1000;
    }
    for (auto element : A)
    {
        std::cout << element << std::endl;
    }
};