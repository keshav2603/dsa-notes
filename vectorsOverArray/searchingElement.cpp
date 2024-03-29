#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool greaterThan(int a, int b)
{
    return a > b;
}
int main()
{
    // vector<int> vec = {2, 4, 61, 8, 1, 12, 14, 23, 18, 3};
    // sort(vec.begin(), vec.end(), greaterThan);
    // for (int i : vec)
    // {
    //     cout << i << endl;
    // }
    vector<int> vec = {3, 6, 8, 8, 10, 12, 15, 15, 15, 18};
    int Count = 0;
    int lastdup = 0;
    for (int i = 0; i < vec.size(); i++)
    {

        Count = count(vec.begin(), vec.end(), vec[i]);

        if (Count >= 2 && vec[i] != lastdup)
        {
            lastdup = vec[i];
            cout << lastdup << "  repeat  " << Count << "  times" << endl;
        }
    }
    return 0;
}
