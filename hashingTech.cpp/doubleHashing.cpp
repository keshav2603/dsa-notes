#include <iostream>
#include <vector>
void insert(std::vector<int> &table, int key)
{
    int x = key % 10;
    int r = 7; // the last prime number in hastable in my case 7
    int x2 = r - (x % r);
    for (int i = 0; i < 10; i++)
    {
        if (table[(x + i * x2) % 10] == 0)
        {
            table[(x + i * x2) % 10] = key;
            break;
        }
    }
}
bool searchInList(const std::vector<int> &list, int key)
{
    int x = key % 10;
    int r = 7; // the last prime number in hastable in my case 7
    int x2 = r - (x % r);
    for (int i = 0; i < 10; i++)
    {
        int index = (x + i * x2) % 10;
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
    std::vector<int> keys{25, 5, 3, 6, 15, 35};
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