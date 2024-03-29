#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec = {12, 22, 3, 44};
    vec.push_back(23);
    vec.push_back(43);
    vec.emplace_back(400);          // all element at back of vector
    vec.insert(vec.begin() + 2, 0); // insert any element at amy index
    vector<int> vec1 = {9, 8, 7};
    vec.insert(vec.end(), vec1.begin(), vec1.end());
    vec.resize(5);
    vec.resize(7); // it add defoult value as 0 to complete size
    vec.resize(9, 100);
    vec.reserve(5); // reserve 5 space extra for future
    for (int x : vec)
    {
        cout << x << endl;
    }
    return 0;
}
