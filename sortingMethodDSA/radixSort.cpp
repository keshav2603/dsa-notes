#include <iostream>
#include <vector>

// Function to find the maximum number to determine the number of digits
int getMax(std::vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(std::vector<int> &arr, int exp)
{
    const int base = 10;
    int n = arr.size();

    std::vector<int> output(n, 0);
    std::vector<int> count(base, 0);

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % base]++;

    // Update count[i] to store the position of the next occurrence
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix sort function
void radixSort(std::vector<int> &arr)
{
    int max = getMax(arr);

    // Perform counting sort for every digit place
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    for (auto &x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (auto &x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
