#include <iostream>
using namespace std;
int main()
{
    int *p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 6;
    int *q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
        cout << q[i] << endl;
    }

    delete[] p;
    p = q;
    q = NULL;
    delete[] p;
    return 0;
}