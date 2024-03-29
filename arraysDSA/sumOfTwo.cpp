#include <iostream>
using namespace std;
int main()
{
    int a[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int target = 10;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (a[i] + a[j] == target)
            {
                cout << a[i] << " + " << a[j] << " = " << target << endl;
            }
        }
    }
}