#include <iostream>
#include <forward_list>
#include <vector>
#include <algorithm>

// Specialized function for int
void insertInSortedOrder(std::forward_list<int> &myList, int newElement)
{
    auto prev = myList.before_begin();
    auto current = myList.begin();

    while (current != myList.end() && *current < newElement)
    {
        ++prev;
        ++current;
    }

    myList.insert_after(prev, newElement);
}

bool searchInList(const std::forward_list<int> &myList, int target)
{
    auto it = std::find(myList.begin(), myList.end(), target);
    return it != myList.end();
}

int main()
{
    std::vector<int> keys = {12, 3, 45, 75, 7, 89, 87, 43, 1, 21, 56, 76, 43, 34};
    std::vector<std::forward_list<int>> hashTable(10);

    for (auto &key : keys)
    {
        insertInSortedOrder(hashTable[key % 10], key);
    }

    std::cout << "Enter the key to be found: " << std::endl;
    int target;
    std::cin >> target;

    bool result = searchInList(hashTable[target % 10], target);

    if (result)
    {
        std::cout << "Target is found." << std::endl;
    }
    else
    {
        std::cout << "Target is not found." << std::endl;
    }

    return 0;
}
