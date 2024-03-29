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
class linklist
{
private:
    unique_ptr<node> head;
    node *tail;

public:
    node *getHead() const
    {
        return head.get();
    }
    int countNode()
    {
        int count = 0;
        node *temp = head.get();
        while (temp != nullptr)
        {
            count++;
            temp = temp->next.get();
        }
        return count;
    }

    void removeDuplicate()
    {
        node *p = head.get();
        node *q = head->next.get();
        while (q != nullptr)
        {
            if (p->data != q->data)
            {
                p = q;
                q = q->next.get();
            }
            else
            {
                p->next = move(q->next);
                if (!p->next)
                {
                    tail = p;
                }
                q = p->next.get();
            }
        }
    }
    void connectTwo(linklist &l2)
    {
        if (!l2.getHead())
        {
            return; // Nothing to connect if l2 is empty
        }

        if (!head)
        {
            head = move(l2.head);
            tail = l2.tail;
        }
        else
        {
            tail->next = move(l2.head);
            tail = l2.tail;
        }

        l2.head = nullptr; // Ensure l2 is in a valid empty state
    }
    void insertAtHead(int val)
    {
        unique_ptr<node> newnode = make_unique<node>(val);
        newnode->next = move(head);
        head = move(newnode);
    }
    void insert(int pos, int val)
    {

        if (pos == 0)
        {
            insertAtHead(val);
        }
        else
        {
            unique_ptr<node> newnode = make_unique<node>(val);
            node *p = head.get();
            for (int i = 0; i < pos - 1 && p; i++)
            {
                p = p->next.get();
            }
            newnode->next = move(p->next);
            p->next = move(newnode);
        }
    }
    void insertAtTail(int value)
    {
        unique_ptr<node> newnode = make_unique<node>(value);

        if (!head)
        {
            head = move(newnode);
            tail = head.get(); // Initialize tail when the first node is added
        }
        else
        {
            tail->next = move(newnode);
            tail = tail->next.get();
        }
    }
    void createFromVector(vector<int> v)
    {
        for (auto &value : v)
        {
            insertAtTail(value);
        }
    }
    void reverseList()
    {
        node *prev = nullptr;
        node *current = head.get();
        node *nextptr;

        while (current != nullptr)
        {
            nextptr = current->next.get();
            current->next = move(unique_ptr<node>(prev));
            prev = current;
            current = nextptr;
        }

        head = move(unique_ptr<node>(prev));
        tail = prev; // Update tail to the new head
    }

    void display() const
    {
        node *current = head.get();

        while (current != nullptr)
        {
            std::cout << current->data << "-->";
            current = current->next.get();
        }
        cout << "NULL" << endl;
    }
    bool search(int key)
    {
        node *temp = head.get();
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next.get();
        }
        return false;
    }
    void deletion(int key)
    {
        if (!head)
        {
            return;
        }
        if (head->data == key)
        {
            head = move(head->next);
            if (!head)
            {
                tail = nullptr;
            }
        }
        node *temp = head.get();
        while (temp->next && temp->next->data != key)
        {
            temp = temp->next.get();
        }
        if (temp->next)
        {
            temp->next = move(temp->next->next);
            // Update tail if the last element is deleted
            if (!temp->next)
            {
                tail = temp;
            }
        }
    }
    void recursiveDisplay(node *current)
    {
        if (current != nullptr)
        {
            cout << current->data << "->";
            recursiveDisplay(current->next.get());
        }
    }

    int recursiveCountNode(node *temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }
        else
        {
            return recursiveCountNode(temp->next.get()) + 1;
        }
    }
    int recursiveSum(node *temp)
    {
        if (temp == nullptr)
        {
            return 0;
        }
        else
        {
            return recursiveSum(temp->next.get()) + temp->data;
        }
    }
    int sumOfList()
    {
        int sum = 0;
        node *temp = head.get();
        while (temp != nullptr)
        {
            sum += temp->data;
            temp = temp->next.get();
        }
        return sum;
    }
    int maxNum()
    {
        node *temp = head.get();
        int max = 0;
        while (temp != nullptr)
        {
            if (temp->data > max)
            {
                max = temp->data;
            }
            temp = temp->next.get();
        }
        return max;
    }
    bool search1(int key)
    {
        node *temp = head.get();
        node *q = nullptr;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                if (q) // If q is not nullptr, meaning temp is not the head
                {
                    // Remove temp from its current position
                    q->next = move(temp->next);

                    // Move temp to the front
                    temp->next = move(head);
                    head.reset(temp);

                    return true;
                }
                else
                {
                    // temp is already the head, no need to move
                    return true;
                }
            }
            q = temp;
            temp = temp->next.get();
        }
        return false;
    }
    void mergeTwoList(linklist &l2)
    {
        unique_ptr<node> newHead = nullptr;
        node *last = nullptr;

        node *p = head.get();
        node *q = l2.head.get();

        if (!p)
        {
            head = move(l2.head);
            tail = l2.tail;
            return;
        }
        else if (!q)
        {
            return; // Nothing to merge if l2 is empty
        }

        if (p->data < q->data)
        {
            newHead = move(head);
            last = p;
            p = p->next.get();
        }
        else
        {
            newHead = move(l2.head);
            last = q;
            q = q->next.get();
        }

        while (p && q)
        {
            if (p->data < q->data)
            {
                last->next = move(make_unique<node>(p->data));
                last = last->next.get();
                p = p->next.get();
            }
            else
            {
                last->next = move(make_unique<node>(q->data));
                last = last->next.get();
                q = q->next.get();
            }
        }

        // Append the remaining nodes from p or q
        // Append the remaining nodes from p or q
        while (p)
        {
            last->next = move(make_unique<node>(p->data));
            last = last->next.get();
            p = p->next.get();
        }

        while (q)
        {
            last->next = move(make_unique<node>(q->data));
            last = last->next.get();
            q = q->next.get();
        }

        head = move(newHead);
        // Update tail to the last node in the merged list
        while (last->next)
        {
            last = last->next.get();
        }
        tail = last;
    }
    bool checkIfLoop()
    {
        node *p = head.get();
        node *q = head.get();
        while (q && p)
        {

            p = p->next.get();

            q = q->next->next.get();
            if (p == q)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    linklist l1;
    vector<int> v = {2, 4, 6, 8, 10};
    // vector<int> v1 = {1, 3, 5, 7, 9};
    l1.createFromVector(v);
    // linklist l2;
    // l2.createFromVector(v1);
    cout << "it is "
         << l1.checkIfLoop() << endl;
    // l1.mergeTwoList(l2);
    // l1.connectTwo(l2);
    // l1.reverseList();
    // l1.removeDuplicate();
    // l1.reverseList();
    l1.display();
    // l1.insertAtTail(1);
    // l1.insertAtTail(2);
    // l1.insertAtTail(4);
    // l1.insertAtTail(6);
    // l1.insertAtTail(8);
    // l1.insertAtTail(10);
    // l1.insertAtTail(3);
    // l1.insertAtTail(7);
    // l1.insert(4, 100);

    // // l1.createFromVector(v1);
    // cout << l1.search(10) << endl;
    // cout << l1.search(5) << endl;
    // l1.display();
    // l1.insertAtTail(1);
    // l1.insertAtTail(2);
    // l1.insertAtTail(3);
    // l1.insertAtTail(4);
    // l1.insertAtHead(5);
    // l1.display();
    // cout << l1.search(5) << endl;
    // l1.deletion(5);
    // l1.deletion(4);
    // l1.display();
    // l1.recursiveDisplay(l1.getHead());

    // cout << "the total node are : " << l1.countNode() << endl;
    // cout << "the total node are : " << l1.recursiveCountNode(l1.getHead()) << endl;
    // cout << "the sum of list : " << l1.sumOfList() << endl;
    // cout << "the sum of list : " << l1.recursiveSum(l1.getHead()) << endl;
    // cout << " max num is " << l1.maxNum() << endl;

    return 0;
};