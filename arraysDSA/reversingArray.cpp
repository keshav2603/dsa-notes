#include <iostream>
using namespace std;
class array
{
private:
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int length = 10;

public:
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << endl;
        }
        cout << "\n\n";
    }
    void reverse()
    {
        int b[size];
        for (int i = 0, j = length - 1; j >= 0; i++, j--)
        {
            b[i] = A[j];
        }
        for (int i = 0; i < length; i++)
        {
            A[i] = b[i];
            cout << A[i] << "  ";
        }
        cout << endl;
    }
    void reverse1()
    {
        for (int i = 0, j = length - 1; i <= j; i++, j--)
        {
            swap(A[i], A[j]);
        }
        for (int i = 0; i < length; i++)
        {

            cout << A[i] << "  ";
        }
    }
    void leftshift()
    {
        int x = A[0];
        for (int i = 1; i < length; i++)
        {
            A[i - 1] = A[i];
        }

        A[length - 1] = 0;

        for (int i = 0; i < length; i++)
        {

            cout << A[i] << "  ";
        }
        cout << endl;
    }
    void leftrotate()
    {
        int x = A[0];
        for (int i = 1; i < length; i++)
        {
            A[i - 1] = A[i];
        }

        A[length - 1] = x;

        for (int i = 0; i < length; i++)
        {

            cout << A[i] << "  ";
        }
        cout << endl;
    }
    void rightshift()
    {
        int x = A[length - 1];
        for (int i = length - 1; i >= 0; i--)
        {
            A[i] = A[i - 1];
        }

        A[0] = 0;

        for (int i = 0; i < length; i++)
        {

            cout << A[i] << "  ";
        }
        cout << endl;
    }
    void rightrotate()
    {
        int x = A[length - 1];
        for (int i = length - 1; i >= 0; i--)
        {
            A[i] = A[i - 1];
        }

        A[0] = x;

        for (int i = 0; i < length; i++)
        {

            cout << A[i] << "  ";
        }
        cout << endl;
    }
};
int main()
{
    array arr;
    arr.reverse();
    arr.reverse1();
    arr.display();
    return 0;
}