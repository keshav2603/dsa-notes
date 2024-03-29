#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> mylist;
    mylist.push_front(1);
    mylist.insert_after(mylist.before_begin(), 12);
    mylist.insert_after(mylist.before_begin(), 14);
    mylist.insert_after(mylist.before_begin(), 16);
    mylist.insert_after(mylist.before_begin(), 18);
    mylist.insert_after(mylist.before_begin(), 20);
    mylist.insert_after(mylist.before_begin(), 22);
    for (auto &x : mylist)
    {
        cout << x << "-->";
    }
    cout << "NULL" << endl;
    return 0;
}