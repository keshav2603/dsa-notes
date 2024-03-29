#include <iostream>
#include <stack>
using namespace std;
bool isBalance(string a)
{
    stack<char> sta;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 40 || a[i] == 91 || a[i] == 123)
        //'('=40,'['=91,'{'=123
        {
            sta.push(a[i]);
        }
        else if (a[i] == 41 || a[i] == 93 || a[i] == 125)
        {
            //')'=41,']'=93,'}'=125
            if (!sta.empty())
            {
                char x = sta.top();
                if (a[i] - x != 1 && a[i] - x != 2)
                {
                    return false;
                }
                else
                    sta.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (sta.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string a = "{((a+b)*[(c-d))]}";
    cout << isBalance(a) << endl;
    return 0;
}