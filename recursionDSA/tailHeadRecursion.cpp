#include <iostream>
using namespace std;
void fun(int n) // tail recursion
{
    cout << "this is tail recursive function" << endl;
    // tail recursion
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1);
    }
}
void fun1(int n) // loop of tail recursion
{
    cout << "this is loop of tail recursion" << endl;
    while (n > 0)
    {
        cout << n << endl;
        n--;
    }
}
void fun2(int n) // head recursion
{

    if (n > 0)
    {
        fun2(n - 1);
        cout << n << endl;
    }
    else
    {
        cout << "this is head recursion" << endl;
    }
}
void fun3(int n) // loop of head recursion
{
    cout << "this is loop of head recursion" << endl;
    int i = 1;
    while (i <= n)
    {
        cout << i << endl;
        i++;
    }
}
int main()
{
    fun2(5);
    fun3(5);
    // fun(5);
    // fun1(5);
    return 0;
}