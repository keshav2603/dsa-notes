#include <iostream>
using namespace std;
void fun1(int n);
void fun(int n)
{
    if (n > 0)
    {
        cout << n << " " << endl;
        fun1(n - 1);
    }
}
void fun1(int n)
{
    if (n > 0)
    {
        cout << n << " " << endl;
        fun(n / 2);
    }
}

int main()
{
    fun(20);
    return 0;
}
