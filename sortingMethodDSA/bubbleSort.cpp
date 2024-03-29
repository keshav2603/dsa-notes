#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {8, 8, 3, 2, 5, 1};

    for (int i = 0; i < vec.size() - 1; i++)
    {
        int count = 0;
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                count = 1;
            }
        }
        if (count == 0)
        {
            break;
        }
    }
    // time os O(n^2)
    // if already sorted time O(n)
    // is adaptive
    // is stable

    for (auto &x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}