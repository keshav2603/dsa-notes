#include <iostream>
#include <vector>
using namespace std;
class heapsort
{
    std::vector<int> arr;

public:
    heapsort() { arr.push_back(0); }
    void createfromvector(vector<int> v1)
    {
        for (auto x : v1)
        {
            insert(x);
        }
    }
    void insert(int val)
    {
        arr.push_back(val);
        int i = arr.size() - 1;

        // Compare with the parent and swap if necessary to maintain the max-heap property
        while (i > 1 && val > arr[i / 2])
        {
            std::swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }
    void heapify(int i, int n)
    {
        int largest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        if (leftChild <= n && arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }

        if (rightChild <= n && arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest, n);
        }
    }

    void heapSort()
    {
        int n = arr.size() - 1;

        // Build max heap
        for (int i = n / 2; i >= 1; i--)
        {
            heapify(i, n);
        }

        // Extract elements one by one from the heap
        for (int i = n; i > 1; i--)
        {
            swap(arr[1], arr[i]);
            heapify(1, i - 1);
        }
    }

    void display()
    {
        for (int num : arr)
        {
            std::cout << num << " ";
        }
    }
};
int main()
{
    vector<int> a = {40, 35, 30, 15, 10, 25, 5};
    heapsort h1;
    h1.createfromvector(a);
    h1.display();
    h1.heapSort();
    h1.display();

    return 0;
}
