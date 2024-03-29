#include <iostream>
#include <deque>
#include <memory>
#include <stack>
#include <queue>

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
class Tree
{
    unique_ptr<node> root;
    deque<node *> q;

public:
    node *getRoot() { return root.get(); }
    void createTree(int val);
    void preorder(node *t);
    void postorder(node *t);
    void inorder(node *t);
    void iterativePreorder();
    void iterativeinorder();
    void iterativepostorder();
    void levelTransverse();
    int countNode(node *temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }
        int x = countNode(temp->left.get());
        int y = countNode(temp->right.get());
        return x + y + 1;
    }
    int countHeight(node *temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }
        int x = countHeight(temp->left.get());
        int y = countHeight(temp->right.get());
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    int countLeaf(node *temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }
        if (temp->left == nullptr && temp->right == nullptr)
        {
            return 1;
        }
        int x = countLeaf(temp->left.get());
        int y = countLeaf(temp->right.get());
        return y + x;
    }
    int countNonLeaf(node *temp)
    {
        if (temp == nullptr || (temp->left == nullptr && temp->right == nullptr))
        {
            return 0;
        }

        int x = countNonLeaf(temp->left.get());
        int y = countNonLeaf(temp->right.get());
        return x + y + 1;
    }
};
int main()
{
    Tree myTree;
    int rootValue;

    cout << "Enter the value for the root node: ";
    cin >> rootValue;
    myTree.createTree(rootValue);
    cout << myTree.countNonLeaf(myTree.getRoot());
    // cout << "preorder is : ";
    // myTree.preorder(myTree.getRoot());
    // cout << endl;
    // cout << "postorder is : ";
    // myTree.postorder(myTree.getRoot());
    // cout << endl;
    // myTree.inorder(myTree.getRoot());
    // cout << endl;
    // myTree.iterativePreorder();
    // myTree.iterativeinorder();
    // myTree.iterativepostorder();
    // myTree.levelTransverse();

    // Now you have a binary tree created using user input

    return 0;
}

void Tree::createTree(int val)
{
    root = make_unique<node>(val);
    q.push_back(root.get());
    int x;

    while (!q.empty())
    {
        node *currentNode = q.front();
        q.pop_front();

        cout << "Enter the value of left child for node with data " << currentNode->data
             << " (input -1 if there is no left child): ";
        cin >> x;

        if (x != -1)
        {
            unique_ptr<node> newnode = make_unique<node>(x);
            currentNode->left = move(newnode);
            q.push_back(currentNode->left.get());
        }

        cout << "Enter the value of right child for node with data " << currentNode->data
             << " (input -1 if there is no right child): ";
        cin >> x;

        if (x != -1)
        {
            unique_ptr<node> newnode = make_unique<node>(x);
            currentNode->right = move(newnode);
            q.push_back(currentNode->right.get());
        }
    }
    cout << endl;
}
void Tree::preorder(node *t)
{
    if (t != nullptr)
    {
        cout << t->data << " ";
        preorder(t->left.get());
        preorder(t->right.get());
    }
}
void Tree::postorder(node *t)
{
    if (t != nullptr)
    {
        postorder(t->left.get());
        postorder(t->right.get());
        cout << t->data << " ";
    }
}
void Tree::inorder(node *t)
{
    if (t != nullptr)
    {
        inorder(t->left.get());
        cout << t->data << " ";
        inorder(t->right.get());
    }
}
void Tree::iterativePreorder()
{
    if (root == nullptr)
        return;

    std::stack<node *> nodeStack;
    nodeStack.push(root.get());

    while (!nodeStack.empty())
    {
        node *currentNode = nodeStack.top();
        nodeStack.pop();

        std::cout << currentNode->data << " ";

        // Push the right child first (since we want to process left child first)
        if (currentNode->right != nullptr)
            nodeStack.push(currentNode->right.get());

        // Push the left child (processed next)
        if (currentNode->left != nullptr)
            nodeStack.push(currentNode->left.get());
    }
    cout << endl;
}
void Tree::iterativeinorder()
{
    if (root == nullptr)
        return;

    std::stack<node *> nodeStack;
    node *currentNode = root.get();

    while (currentNode != nullptr || !nodeStack.empty())
    {
        while (currentNode != nullptr)
        {
            nodeStack.push(currentNode);
            currentNode = currentNode->left.get();
        }

        currentNode = nodeStack.top();
        nodeStack.pop();

        std::cout << currentNode->data << " ";

        currentNode = currentNode->right.get();
    }
    cout << endl;
}

void Tree::iterativepostorder()
{
    if (root == nullptr)
        return;

    std::stack<node *> nodeStack;
    nodeStack.push(root.get());

    while (!nodeStack.empty())
    {
        node *currentNode = nodeStack.top();
        nodeStack.pop();

        // std::cout statement is here

        // Push the left child first (since we want to process right child first)
        if (currentNode->left != nullptr)
            nodeStack.push(currentNode->left.get());

        // Push the right child (processed next)
        if (currentNode->right != nullptr)
            nodeStack.push(currentNode->right.get());
    }
}

void Tree::levelTransverse()
{
    if (root == nullptr)
        return;
    queue<node *> p;
    node *currentNode = root.get();
    p.push(currentNode);
    cout << currentNode->data << " ";
    while (!p.empty())
    {
        currentNode = p.front();
        p.pop();
        if (currentNode->left)
        {
            cout << currentNode->left->data << " ";
            p.push(currentNode->left.get());
        }
        if (currentNode->right)
        {
            cout << currentNode->right->data << " ";
            p.push(currentNode->right.get());
        }
    }
    cout << endl;
}
