#include <iostream>
#include <string>
using namespace std;
int main()
{
    // string name = {"KESHAV"};
    // for (int i = 0; i < name.length(); i++)
    // {
    //     name[i] += 32;
    // }
    // cout << name;
    string a = "wElCoMe";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
        {
            a[i] += 32;
        }
        else if (a[i] <= 122 && a[i] >= 97)
        {
            a[i] -= 32;
        }
    }
    cout << a << endl;

    return 0;
}