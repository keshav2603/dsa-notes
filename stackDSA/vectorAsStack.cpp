#include <iostream>
#include <vector>
using namespace std;
class stack
{
    vector<int> str;
    int top = str.size() - 1;

public:
    void popTop()
    {
        str.pop_back();
        top = str.size() - 1;
    }
    void pushTop(int x)
    {
        str.push_back(x);
        top = str.size() - 1;
    }
    int peek(int pos)
    {
        return str[top - pos + 1];
    }
    bool Empty()
    {
        return str.empty();
    }
    int getTop()
    {
        return str[top];
    }
};
int main()
{
    stack s1;
    s1.pushTop(12);
    s1.pushTop(13);
    cout << s1.peek(2) << endl;
    cout << s1.getTop() << endl;
    return 0;
}