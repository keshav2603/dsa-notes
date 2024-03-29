#include <iostream>
using namespace std;
class array
{
private:
    int a[10] = {2, 4, 6, 8, 10, 12};
    int length = 6;
    int size = 10;

public:
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << a[i] << endl;
        }
        cout << "\n\n";
    }
    void append(int x)
    {
        if (length < size)
        {
            a[length++] = x;
            // ar->length++;
        }
    }
    void insert(int x, int key)
    {
        if (x >= 0 && x < length)
        {
            for (int i = length; i > x; i--)
            {
                a[i] = a[i - 1];
            }
            a[x] = key;
            length++;
        }
    }
    void remove(int index)
    {
        if (index >= 0 && index < length)
        {
            int x = a[index];
            for (int i = index; i < length - 1; i++)
            {
                a[i] = a[i + 1];
            }
            length--;
            cout << x << "  has been removed from array from index :" << index << endl;
        }
    }
    int get(int index)
    {
        if (index >= 0 && index < length)
        {
            return a[index];
        }
    }
    void set(int index, int x)
    {
        if (index >= 0 && index < length)
        {
            a[index] = x;
        }
    }
    int max()
    {
        int Max = a[0];
        for (int i = 1; i < length; i++)
        {
            if (Max < a[i])
            {
                Max = a[i];
            }
        }
        return Max;
    }
};
int main()
{
    array arr;
    arr.append(100);
    cout << arr.get(2) << endl;

    arr.display();

    // // display(arr);
    // // append(&arr, 10);
    // // insert(&arr, 4, 200);cout << get(arr, 4) << endl;
    // set(&arr, 4, 3);
    // display(arr);
    // cout << "maximum number is :  " << max(arr) << endl;
    // // remove(&arr, 3);

    return 0;
}