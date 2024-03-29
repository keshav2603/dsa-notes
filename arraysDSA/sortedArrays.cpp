#include <iostream>
using namespace std;
class Array
{
private:
    int A[10] = {
        2,
        -4,
        6,
        8,
        10,
        -12,
        -14,
        16,
    };
    int size = 10;
    int length = 8;

public:
    void insertsort(int x) // inserting an element in an sorted array at its right place
    {

        int i = length;
        while (x < A[i - 1])
        {
            A[i] = A[i - 1];
            i--;
        }
        A[i] = x;
        length++;
        for (int j = 0; j < length; j++)
        {
            cout << A[j] << "   ";
        }
    }
    bool issorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    void rearange()
    {
        int i = 0, j = length;
        while (i < j)
        {
            while (A[i] < 0)
            {
                i++;
            }
            while (A[j] >= 0)
            {
                j--;
            }
            swap(A[i], A[j]);
        }
    }
};
int main()
{
    Array arr;
    // cout << issorted(arr);
    // int a[10] = {1, 2, -3, 4, 5, -9, -18, 27, 35, -43};
    // rearange(&arr);
    // insertsort(&arr, 11);
    // insertsort(&arr, 3);
}