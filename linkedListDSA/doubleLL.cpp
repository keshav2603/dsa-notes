#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // list<int> mylist = {10, 20, 30, 40, 50};
    // list<int> l2 = {5, 15, 25, 35, 45};

    // mylist.push_front(10);
    // mylist.push_back(20);
    // mylist.push_back(30);

    // auto it = mylist.begin();
    // advance(it, 2); // it is used to move the iterator by given step
    // mylist.insert(it, 25); // inserting a element at index 2
    // mylist.remove(25);  // remove element by value

    // auto it = find(mylist.begin(), mylist.end(), 40);
    // cout << distance(mylist.begin(), it) << endl;
    // // auto a = find_if(mylist.begin(), mylist.end(), [](int val)
    // //                  { return val > 25; });
    // cout << distance(mylist.begin(), a) << endl;
    // mylist.merge(l2);
    // auto it = mylist.begin();
    // advance(it, 5);
    // mylist.splice(it, l2);

    // mylist.sort();

    // Creating a sample list: 1 -> 2 -> 3 -> 4 -> 5
    std::list<int> myList = {1, 2, 3, 4, 5};

    // Finding the middle of the list
    auto slow = myList.begin();
    auto fast = myList.begin();

    while (fast != myList.end() && std::next(fast) != myList.end())
    {
        ++slow;
        std::advance(fast, 2);
    }

    // Printing the middle element
    if (slow != myList.end())
    {
        std::cout << "Middle element: " << *slow << std::endl;
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }

    return 0;

    for (auto &x : myList)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}