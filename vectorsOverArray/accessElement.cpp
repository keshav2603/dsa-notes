#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec = {2, 4, 6, 8, 10};
    // cout << vec[2] << endl;
    cout << vec.at(2) << endl;
    // cout << vec.front() << endl;
    // cout << vec.back() << endl;
    // cout << "loop" << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    return 0;
}