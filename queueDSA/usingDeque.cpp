#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> mydeque;
    mydeque.push_back(12);
    mydeque.push_front(13);
    mydeque.insert(mydeque.begin() + 1, 10);
    mydeque.erase(mydeque.end());
    mydeque.emplace_back(100);

    for (auto x : mydeque)

    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}