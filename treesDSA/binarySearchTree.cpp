#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct node
{
    unique_ptr<node> left;
    int data;
    unique_ptr<node> right;
    node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BSTree
{
    unique_ptr<node> root;

public:
    node *getRoot() { return root.get(); }
    void insert(int val);
    node *rinsert(node *temp, int val);
    node *rSearch(node *temp, int key)
    {
        // the tree must be binnary search tree
        if (temp == nullptr)
        {
            return nullptr;
        }
        if (temp->data == key)
        {
            return temp;
        }
        else if (temp->data > key)
        {
            return rSearch(temp->left.get(), key);
        }
        else
        {
            return rSearch(temp->right.get(), key);
        }
    }
    node *iSearch(int key)
    {
        node *temp = root.get();
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return temp;
            }
            else if (temp->data > key)
            {
                temp = temp->left.get();
            }
            else
            {
                temp = temp->right.get();
            }
        }
        return nullptr;
    }

    void createTreeFromVector(vector<int> a)
    {
        for (auto &x : a)
        {
            insert(x);
        }
    }
    node *deleteNode(node *temp, int key);
    void inorder(node *t)
    {
        if (t != nullptr)
        {
            inorder(t->left.get());
            cout << t->data << " ";
            inorder(t->right.get());
        }
    }
};

int main()
{
    BSTree mytree;
    vector<int> a = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    mytree.createTreeFromVector(a);
    mytree.inorder(mytree.getRoot());
    cout << endl;
    mytree.rinsert(mytree.getRoot(), 4);
    // mytree.deleteNode(mytree.getRoot(), 9);
    mytree.inorder(mytree.getRoot());

    return 0;
}
node *BSTree::deleteNode(node *temp, int key)
{
    // Base case: If the tree is empty
    if (temp == nullptr)
    {
        return temp;
    }

    // Recursive cases
    if (key < temp->data)
    {
        temp->left.reset(deleteNode(temp->left.release(), key));
    }
    else if (key > temp->data)
    {
        temp->right.reset(deleteNode(temp->right.release(), key));
    }
    else
    {
        // Node with only one child or no child
        if (temp->left == nullptr)
        {
            return temp->right.release();
        }
        else if (temp->right == nullptr)
        {
            return temp->left.release();
        }

        // Node with two children: Get the in-order successor (smallest
        // in the right subtree) or in-order predecessor (largest in the
        // left subtree)
        node *successor = temp->right.get();
        while (successor->left != nullptr)
        {
            successor = successor->left.get();
        }

        // Replace the node's data with the in-order successor's data
        temp->data = successor->data;

        // Delete the in-order successor
        temp->right.reset(deleteNode(temp->right.release(), temp->data));
    }

    return temp;
}

void BSTree::insert(int val)
{

    if (root == nullptr)
    {
        root = make_unique<node>(val);
        return;
    }
    node *temp = root.get(), *followptr;
    while (temp != nullptr)
    {
        followptr = temp;
        if (val == temp->data)
        {
            return;
        }
        else if (val < temp->data)
        {

            temp = temp->left.get();
        }
        else
        {

            temp = temp->right.get();
        }
    }
    unique_ptr<node> newnode = make_unique<node>(val);
    if (val < followptr->data)
    {
        followptr->left = move(newnode);
    }
    else
    {
        followptr->right = move(newnode);
    }
}
node *BSTree::rinsert(node *temp, int val)
{
    if (temp == nullptr)
    {
        return make_unique<node>(val).release();
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

    return temp;
}
