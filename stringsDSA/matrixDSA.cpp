#include <iostream>
#include <vector>
using namespace std;
class diagonal
{
private:
    vector<vector<int>> dig;

public:
    diagonal(vector<int> a)
    {
        int n = a.size();

        // Resize dig vector to the size of input vector
        dig.resize(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dig[i][i] = a[i];
        }
    }
    void display()
    {
        for (int i = 0; i < dig.size(); i++)
        {
            for (int j = 0; j < dig.size(); j++)
            {
                cout << dig[i][j] << "  ";
            }
            cout << endl;
        }
    }
};
class lowerTriangle
{
private:
};
int main()
{
    // diagonal d({1, 2, 3, 4, 5});
    // d.display();
    return 0;
}