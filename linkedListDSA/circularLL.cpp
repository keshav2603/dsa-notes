#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct node
{
    int data;
    unique_ptr<node> next;

    node(int value) : data(value), next(nullptr) {}
};

class circularll
{
private:
    unique_ptr<node> head;
    node *tail;

public:
    void create(int val)
    {
        unique_ptr<node> newnode = make_unique<node>(val);

        if (!head)
        {
            head = move(newnode);
            head->next = move(head); // Set the next pointer to itself for a single node circular list
            tail = head.get();
        }
        else
        {
            node *temp = head.get();
            do
            {
                temp = temp->next.get();
            } while (temp->next != head);
            temp->next = move(newnode);
            newnode->next = move(head);
            tail = newnode.get();
        }
    }

    void createFromVector(const vector<int> &v1)
    {
        for (const auto &x : v1)
        {
            create(x);
        }
    }

    void display() const
    {
        const node *p = head.get();
        if (p)
        {
            do
            {
                cout << "Node " << p->data << " at address: " << p << " --> ";
                p = p->next.get();
            } while (p != head.get());
        }
        cout << "..." << endl; // Indicate that it's a circular list
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    circularll c1;
    c1.createFromVector(v);
    c1.display();
    return 0;
}
