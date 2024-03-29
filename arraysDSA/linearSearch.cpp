#include <iostream>
using namespace std;
class array
{
private:
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int length = 10;
    int size = 10;

public:
    int searchkey(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (key == a[i])
            {
                return i;
            }
        }
        return -1;
    }
    int searchkey1(array *arr, int key) // improved of linear by transposition
    {
        for (int i = 0; i < arr->length; i++)
        {
            if (key == arr->a[i])
            {
                swap(arr->a[i], arr->a[i - 1]);
                return i - 1;
            }
        }
        return -1;
    }
    int searchkey2(array *arr, int key) // improved of linear by move to head
    {
        for (int i = 0; i < arr->length; i++)
        {
            if (key == arr->a[i])
            {
                swap(arr->a[i], arr->a[0]);
                return 0;
            }
        }
        return -1;
    }

    int searchkey3(int key) // this is my introduced method
    {
        for (int i = 0, j = length - 1; i <= j; i++, j--)
        {
            if (key == a[i])
            {
                return i;
            }
            else if (key == a[j])
            {
                return j;
            }
        }
        return -1;
    }
};
int main()
{
    array arr;
    cout << arr.searchkey(16) << endl;
    cout << arr.searchkey1(&arr, 16) << endl;
    cout << arr.searchkey2(&arr, 16) << endl;

    return 0;
}