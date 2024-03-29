#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec = {2, 4, 6, 8, 10, 12, 14, 16};
    vec.pop_back(); // remove one last element
    vec.erase(vec.begin() + 2);
    // vec.erase(vec.begin(), vec.begin() + 3); // remove element of certaion range
    // vec.clear();                             // clear all element

    for (int element : vec)
    {
        cout << element << endl;
    }
    return 0;
}