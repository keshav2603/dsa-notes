#include <iostream>
using namespace std;
void fun(int n)
{
    if (n > 0)
    {
        cout << n << "\trecursion while going:assending" << endl;
        fun(n - 1);
        cout << n << "\trecursion while returning:desending" << endl;
    }
}
int fun1(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return fun1(n - 1) + x;
    }
}
int main()
{
    cout << fun1(5) << endl;
    // int x = 3;
    // fun(x);
}