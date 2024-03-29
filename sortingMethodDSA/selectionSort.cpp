#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {8, 6, 3, 2, 5, 4};

    for (int i = 0; i < vec.size(); i++)
    {
        auto min = std::min_element(vec.begin() + i, vec.end());
        if (min != vec.begin() + i)
        {
            std::swap(vec[i], *min);
        }
    }
    // tie O(n^2)
    //  not adaptive
    //  and not stable
    for (auto &x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}