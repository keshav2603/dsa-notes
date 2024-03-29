#include <iostream>
#include <vector>

void shellSort(std::vector<int> &arr)
{
    int n = arr.size();

    // Start with a large gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform gapped insertion sort
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            // Shift earlier gap-sorted elements up until the correct position for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            // Place arr[i] at its correct position
            arr[j] = temp;
        }
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

    shellSort(arr);

    std::cout << "Sorted array: ";
    for (auto &x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
