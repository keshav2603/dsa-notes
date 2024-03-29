#include <iostream>
#include <vector>
void merge(std::vector<int> &arr, int left, int mid, int right)
{

    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];
    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void iterativeMergeSort(std::vector<int> &arr)
{
    int n = arr.size();

    // Start from 1 to n-1, and double the size in each iteration
    for (int currentSize = 1; currentSize <= n - 1; currentSize = 2 * currentSize)
    {
        // Pick starting point of different subarrays of current size
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize)
        {
            int mid = std::min(leftStart + currentSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currentSize - 1, n - 1);

            // Merge subarrays arr[leftStart...mid] and arr[mid+1...rightEnd]
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

void recursiveMergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        recursiveMergeSort(arr, left, mid);
        recursiveMergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    std::vector<int> arr = {8, 3, 7, 4, 5, 2, 6, 9};

    std::cout << "Original array: ";
    for (auto &x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    recursiveMergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (auto &x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}