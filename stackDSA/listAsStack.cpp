#include <iostream>
#include <forward_list>
using namespace std;
class Stack
{
    forward_list<int> str;

public:
    void popTop()
    {
        if (!str.empty())
        {
            str.pop_front();
        }
        else
        {
            cout << "stack is already empty" << endl;
        }
    }
    void pushTop(int x)
    {
        str.push_front(x);
    }
    int peek(int pos)
    {
        auto it = str.begin();
        advance(it, pos - 1);
        return *it;
    }
    bool Empty()
    {
        return str.empty();
    }
    int getTop()
    {
        return str.front();
    }
};
int main()
{
    return 0;
}
