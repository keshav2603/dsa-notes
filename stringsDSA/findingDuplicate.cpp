#include <iostream>
using namespace std;
int main()
{
    // finding duplicate using bit operation
    // string a = "finding";
    // long h = 0, x;
    // for (int i = 0; i < a.length(); i++)
    // {
    //     x = 1;
    //     x = x << (a[i] - 97);
    //     if ((x & h) > 0)
    //     {
    //         cout << a[i] << "  is duplicate" << endl;
    //     }
    //     else
    //     {
    //         h = h | x;
    //     }
    // }
    string a = "decomal";
    string b = "medical";
    int h[26] = {0};
    for (int i = 0; i < a.length(); i++)
    {
        h[a[i] - 97]++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        h[b[i] - 97]--;
        if (h[b[i] - 97] < 0)
        {
            cout << "not it is not same" << endl;
            break;
        }
    }
    return 0;
}