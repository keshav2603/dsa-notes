#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int searchKey(int key)
{
    vector<int> v1 = {2, 3, 4, 6, 8, 9, 10, 12, 14, 16, 18, 20};
    int l = 0, h = v1.size() - 1;
    int mid1 = 0, mid2 = 0;
    while (l <= h)
    {
        mid1 = (l + h) / 3;
        mid2 = 2 * (l + h) / 3;
        if (v1[mid1] == key)
        {
            return mid1;
        }
        else if (v1[mid2] == key)
        {
            return mid2;
        }
        if (v1[mid1] < key && v1[mid2] > key)
        {
            l = mid1 + 1;
            h = mid2 - 1;
        }
        else if (v1[mid2] < key)
        {
            l = mid2 + 1;
        }
        else
        {
            h = mid1 - 1;
        }
    }
    return -1;
}
int main()
{
    cout << searchKey(20);
}