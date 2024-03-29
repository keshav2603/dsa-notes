#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {8, 5, 7, 3, 2};
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (vec[j + 1] < vec[j])
            {
                std::swap(vec[j + 1], vec[j]);
            }
        }
    }
    // time O(n^2)
    // adaptive
    // stable

    for (auto &x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}