#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Postfix
{
    vector<char> ans;
    stack<char> sta;
    stack<int> staint;

public:
    int pre(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
        return 0;
    }
    int isOperent(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return 0;
        else
        {
            return 1;
        }
    }
    vector<char> change(string a)
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (isOperent(a[i]))
            {
                ans.push_back(a[i]);
            }
            else
            {
                if (sta.empty())
                {
                    sta.push(a[i]);
                }
                else if (pre(sta.top()) < pre(a[i]))
                {
                    sta.push(a[i]);
                }
                else
                {
                    while (!sta.empty() && pre(sta.top()) >= pre(a[i]))
                    {
                        ans.push_back(sta.top());
                        sta.pop();
                    }
                    sta.push(a[i]);
                }
            }
        }
        while (!sta.empty())
        {
            ans.push_back(sta.top());
            sta.pop();
        }
        return ans;
    }
    int evaluvate()
    {
        int x1, x2, r;
        for (int i = 0; i < ans.size(); i++)
        {
            if (isOperent(ans[i]))
            {
                staint.push(ans[i] - '0');
            }
            else
            {
                x2 = staint.top();
                staint.pop();
                x1 = staint.top();
                staint.pop();
                switch (ans[i])
                {
                case '+':
                    r = x1 + x2;
                    staint.push(r);
                    break;
                case '-':
                    r = x1 - x2;
                    staint.push(r);
                    break;
                case '*':
                    r = x1 * x2;
                    staint.push(r);
                    break;
                case '/':
                    r = x1 / x2;
                    staint.push(r);
                    break;
                default:
                    break;
                }
            }
        }
        return staint.top();
    }
};
int main()
{
    cout << "Enter the expression you wont to solve :" << endl;
    string a;
    cin >> a;
    Postfix p1;
    vector<char> b = p1.change(a);

    cout << endl;
    cout << "its value is :" << p1.evaluvate() << endl;

    return 0;
}