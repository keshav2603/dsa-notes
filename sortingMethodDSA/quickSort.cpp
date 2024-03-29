#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T> &arr, int low, int high)
{
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quick_sort(std::vector<T> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);

        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main()
{
    std::vector<int> my_vector = {3, 6, 8, 10, 1, 2, 5};

    int size = my_vector.size();
    quick_sort(my_vector, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << my_vector[i] << " ";
    }

    return 0;
}
