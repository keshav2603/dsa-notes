#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // int a[11] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    // int s = 0;
    // for (int i = 0; i < 11; i++)
    // {
    //     s += a[i];
    // }
    // int sum = 12 * 13 / 2;
    // cout << "element missing is " << sum - s;

    // int a[10] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18};
    // int diff = a[0] - 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     if (a[i] - i != diff)
    //     {
    //         while (diff < a[i] - i)
    //         {
    //             cout << i + diff << "  element is missing" << endl;
    //             diff++;
    //         }
    //     }
    // }

    // int a[10] = {3,
    //              7,
    //              9,
    //              12,
    //              6,
    //              1,
    //              11,
    //              2,
    //              10};
    // vector<int> h;
    // h.resize(12, 0);
    // for (int i = 0; i < 10; i++)
    // {
    //     h[a[i]]++;
    // }
    // for (int i = 1; i < 12; i++)
    // {
    //     if (h[i] == 0)
    //     {
    //         cout << i << "  element is missing" << endl;
    //     }
    // }

    // int a[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 18};
    // int lastdupl = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     if (a[i] == a[i + 1] && a[i] != lastdupl)
    //     {
    //         cout << a[i] << "  element is duplicate" << endl;
    //         lastdupl = a[i];
    //     }
    // }

    // int a[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 18};
    // int lastdupl = 0;
    // for (int i = 0; i < 9; i++)
    // {
    //     if (a[i] == a[i + 1] && a[i] != lastdupl)
    //     {
    //         lastdupl = a[i];
    //         int j = i + 1;
    //         while (a[i] == a[j])
    //         {
    //             j++;
    //         }
    //         cout << lastdupl << "  repeat " << j - i << "  times" << endl;
    //         i = j - 1;
    //     }
    // }

    // int a[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 18};
    // vector<int> vec;
    // vec.resize(20, 0);
    // for (int i = 0; i < 10; i++)
    // {
    //     vec[a[i]]++;
    // }
    // for (int i = 0; i < 20; i++)
    // {
    //     if (vec[i] >= 2)
    //     {
    //         cout << i << "  repeat  " << vec[i] << "  times  " << endl;
    //     }
    // }

    int a[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int Count;
    for (int i = 0; i < 9; i++)
    {
        Count = 1;
        if (a[i] != -1)
            for (int j = i + 1; j < 10; j++)
            {
                if (a[i] == a[j])
                {
                    Count++;
                    a[j] = -1;
                }
            }
        if (Count > 1)
        {
            cout << a[i] << "  repeat  " << Count << "  times" << endl;
        }
    }
    return 0;
}