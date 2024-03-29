#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q1;
    q1.push(30);
    q1.push(12);
    q1.pop();
    cout << q1.front();
    return 0;
}