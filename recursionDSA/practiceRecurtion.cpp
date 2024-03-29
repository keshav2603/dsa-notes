#include <iostream>
#include <vector>
using namespace std;
int sum(int n) // sum of n number by recurtion
{
    if (n > 0)
    {

        return sum(n - 1) + n;
    }
}
int sum1(int n) // sum of n number by formula
{
    return n * (n + 1) / 2;
}
int sum2(int n) // sum of n number by loop
{
    int total = 0;
    while (n > 0)
    {
        total += n;
        n--;
    }
    return total;
}

int factorial(int n) // factorial of n number by recurtion
{
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        return factorial(n - 1) * n;
    }
}

int power(int m, int n) // power of number by recurtion
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return power(m, n - 1) * m;
    }
}
int power1(int m, int n) // power by recurtion but faster thanpower
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return power(m * m, n / 2);
    }
    else if (n % 2 == 1)
    {
        return m * power(m * m, (n - 1) / 2);
    }
}

int taylor(int m, int n) // taylor series epowerx by approch no 1
{
    static int p = 1, f = 1;
    int r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = taylor(m, n - 1);
        p *= m;
        f *= n;
        return r + p / f;
    }
}
int taylor1(int m, int n) // taylor using loops and horner rule
{
    int s = 1;
    for (; n > 0; n--)
    {
        s = 1 + m / n * s;
    }
    return s;
}
int taylor2(int x, int n) // horner rule recurtion
{
    static int s = 1;
    if (n == 0)
    {
        return s;
    }
    s = 1 + x / n * s;
    return taylor2(x, n - 1);
}

int fib(int n) // fibonacci series with recurtion
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}
int fib1(int n) // fibonacci series with loop
{
    int t = 0, t1 = 1, s;
    if (n <= 1)
    {
        return n;
    }
    for (int i = 2; i <= n; i++)
    {
        s = t + t1;
        t = t1;
        t1 = s;
    }
    return s;
}
int fib2(int n) // fibonacci series with the help of memoization
{
    static int f[10];
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
        {
            f[n - 2] = fib2(n - 2);
        }
        if (f[n - 1] == -1)
        {
            f[n - 1] = fib2(n - 1);
        }
        return fib2(n - 2) + fib2(n - 1);
    }
}

int combination(int n, int r) // combination nCr using recurtion simple function
{
    int t1, t2, t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n - r);
    return t1 / (t2 * t3);
}
int combination1(int n, int r) // by usinf pascl's triangle
{
    static int comb[11][11];

    if (n == r || r == 0)
    {
        if (n == r)
        {
            comb[n][r] = 1;
            return 1;
        }
        else if (r == 0)
        {
            comb[n][r] = 1;
            return 1;
        }
    }
    else
    {
        if (comb[n - 1][r - 1] == -1)
        {
            comb[n - 1][r - 1] = combination1(n - 1, r - 1);
        }
        if (comb[n - 1][r] == -1)
        {
            comb[n - 1][r] = combination1(n - 1, r);
        }
        return combination1(n - 1, r - 1) + combination1(n - 1, r);
    }
}

void toh(int n, char a, char b, char c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        toh(n - 1, b, a, c);
    }
}
void printpeg(const vector<int> &peg)
{
    for (int disk : peg)
    {
        cout << " " << disk << " ";
    }
    cout << endl;
}
void toh1(int n, vector<int> &a, vector<int> &b, vector<int> &c)
{
    if (n > 0)
    {
        toh1(n - 1, a, c, b);
        c.push_back(a.back());
        a.pop_back();
        printpeg(a);
        printpeg(b);
        printpeg(c);
        cout << "----------" << endl;
        toh1(n - 1, b, a, c);
    }
}
int main()
{
    int n;
    cout << "enter the number if disk" << endl;
    cin >> n;
    vector<int> pegA, pegB, pegC;
    for (int i = n; i >= 1; i--)
    {
        pegA.push_back(i);
    }
    cout << "initial state:" << endl
         << "----------" << endl;
    printpeg(pegA);
    printpeg(pegB);
    printpeg(pegC);
    cout << "----------" << endl;
    toh1(n, pegA, pegB, pegC);
    cout << "final state:" << endl
         << "----------" << endl;
    printpeg(pegA);
    printpeg(pegB);
    printpeg(pegC);

    // toh(3, 'a', 'b', 'c');
    // cout << combination(5, 2) << endl;
    // cout << combination1(5, 2) << endl;
    // cout << fib(6) << endl;
    // cout << fib1(6) << endl;
    // cout << fib2(6) << endl;
    // cout << taylor(1, 10) << endl;
    // cout << taylor1(1, 10) << endl;
    // cout << taylor2(1, 10) << endl;
    // cout << power(10, 5) << endl;
    // cout << power1(10, 5) << endl;
    // cout << factorial(5) << endl;

    // cout << sum(10) << endl;
    // cout << sum1(10) << endl;
    // cout << sum2(10) << endl;

    return 0;
}