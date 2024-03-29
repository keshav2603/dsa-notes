#include <iostream>
#include <vector>
void insert(std::vector<int> &table, int key)
{
    for (int i = 0; i < 10; i++)
    {
        if (table[((key % 10) + i) % 10] == 0)
        {
            table[((key % 10) + i) % 10] = key;
            break;
        }
    }
}
bool searchInList(const std::vector<int> &list, int key)
{
    for (int i = 0; i < 10; i++)
    {
        int index = (key % 10 + i) % 10;
        if (list[index] == 0)
        {
            return false;
        }
        else if (list[index] == key)
        {
            return true;
        }
    }
    return false; // This line is added for completeness
}

int main()
{
    std::vector<int> keys{23, 56, 78, 96, 10, 21};
    std::vector<int> hashTable(10, 0);
    for (auto &x : keys)
    {
        insert(hashTable, x);
    }

    std::cout << "Enter the key to be found: " << std::endl;
    int target;
    std::cin >> target;

    bool result = searchInList(hashTable, target);

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