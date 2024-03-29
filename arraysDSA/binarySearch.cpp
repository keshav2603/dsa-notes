#include <iostream>
using namespace std;
class array
{
private:
    int a[15] = {2, 4, 6, 8, 10, 12, 14, 16, 17, 18, 10, 20, 22, 24, 26};
    int capacity = 15;
    int length = 15;

public:
    int getlength()
    {
        return length;
    }
    int searchKey(int key)
    {
        int l = 0, h = length, mid = 0;

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (key == a[mid])
            {
                return mid;
            }
            else if (key > a[mid])
            {
                l = mid + 1;
            }
            else if (key < a[mid])
            {
                h = mid - 1;
            }
        }
        cout << key << "  not found" << endl;
    }
    int searchKey1(int l, int h, int key)
    {
        int mid;
        if (l <= h)
        {
            mid = (l + h) / 2;
            if (key == a[mid])
            {
                return mid;
            }
            else if (key > a[mid])
            {
                return searchKey1(mid + 1, h, key);
            }
            else if (key < a[mid])
            {
                return searchKey1(l, mid - 1, key);
            }
        }
        else
        {
            return -1;
        }
    }
    // int searchkey2(struct array arr, int key)
    // {
    //     static int l = 0, h = arr.length, mid = 0;
    //     if (l <= h)
    //     {
    //         mid = (l + h) / 2;
    //         if (key == arr.a[mid])
    //         {
    //             return mid;
    //         }
    //         else if (key > arr.a[mid])
    //         {
    //             l = mid + 1;
    //             return searchkey2(arr, key);
    //         }
    //         else if (key < arr.a[mid])
    //         {
    //             h = mid - 1;
    //             return searchkey2(arr, key);
    //         }
    //     }
    //     else
    //     {
    //         return -1;
    //     }
    // }
};
int main()
{
    array arr1;
    cout << arr1.searchKey1(0, arr1.getlength(), 20) << endl;
    cout << arr1.searchKey(20) << endl;

    return 0;
}