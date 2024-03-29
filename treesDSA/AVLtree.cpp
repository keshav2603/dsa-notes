#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct node
{
    unique_ptr<node> left;
    int data;
    int height;
    unique_ptr<node> right;

    node(int value)
    {
        data = value;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
    unique_ptr<node> root = nullptr;

public:
    int getRootData() { return root->data; }
    node *getRoot() { return root.get(); }

    node *rinsert(node *temp, int val);
    int countHeight(node *temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }
        int x = countHeight(temp->left.get());
        int y = countHeight(temp->right.get());
        return max(x, y) + 1;
    }

    int balance(node *p)
    {
        if (p == nullptr)
        {
            return 0;
        }
        int x = countHeight(p->left.get());
        int y = countHeight(p->right.get());
        return x - y;
    }

    node *LLRotation(node *root);
    node *LRRotation(node *root);
    node *RRRotation(node *root);
    node *RLRotation(node *root);
};

int main()
{
    Tree mytree;
    mytree.rinsert(mytree.getRoot(), 20);
    cout << "Root value after insertion: " << mytree.getRootData() << endl;
    mytree.rinsert(mytree.getRoot(), 10);
    cout << "Root value after insertion: " << mytree.getRootData() << endl;
    mytree.rinsert(mytree.getRoot(), 5);
    cout << "Root value after insertion: " << mytree.getRootData() << endl;
    mytree.rinsert(mytree.getRoot(), 4);
    cout << "Root value after insertion: " << mytree.getRootData() << endl;
    mytree.rinsert(mytree.getRoot(), 3);
    cout << "Root value after insertion: " << mytree.getRootData() << endl;
    mytree.rinsert(mytree.getRoot(), 2);
    cout << "Root value after insertion: " << mytree.getRootData() << endl;

    return 0;
}

node *Tree::rinsert(node *temp, int val)
{
    if (temp == nullptr)
    {
        return new node(val);
    }

    if (val < temp->data)
    {
        if (temp->left == nullptr)
        {
            temp->left.reset(new node(val));
        }
        else
        {
            temp->left.reset(rinsert(temp->left.release(), val));
        }
    }
    else if (val > temp->data)
    {
        if (temp->right == nullptr)
        {
            temp->right.reset(new node(val));
        }
        else
        {
            temp->right.reset(rinsert(temp->right.release(), val));
        }
    }

    // Update height after insertion
    temp->height = countHeight(temp);

    // Check and perform rotations
    if (balance(temp) == 2)
    {
        if (balance(temp->left.get()) == 1)
        {
            return LLRotation(temp);
        }
        else if (balance(temp->left.get()) == -1)
        {
            return LRRotation(temp);
        }
    }
    else if (balance(temp) == -2)
    {
        if (balance(temp->right.get()) == -1)
        {
            return RRRotation(temp);
        }
        else if (balance(temp->right.get()) == 1)
        {
            return RLRotation(temp);
        }
    }

    return temp;
}

node *Tree::LLRotation(node *root)
{
    node *newRoot = root->left.get();
    root->left = std::move(newRoot->right);
    newRoot->right.reset(root);
    root->height = countHeight(root);
    newRoot->height = countHeight(newRoot);
    return newRoot;
}

node *Tree::LRRotation(node *root)
{
    root->left.reset(LLRotation(root->left.get()));
    return RRRotation(root);
}

node *Tree::RRRotation(node *root)
{
    node *newRoot = root->right.get();
    root->right = std::move(newRoot->left);
    newRoot->left.reset(root);
    root->height = countHeight(root);
    newRoot->height = countHeight(newRoot);
    return newRoot;
}

node *Tree::RLRotation(node *root)
{
    root->right.reset(RRRotation(root->right.get()));
    return LLRotation(root);
}
