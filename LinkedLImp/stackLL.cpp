
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *newnode, *p, *temp;

template <class T>
class LinkedList
{

public:
    int getTop()
    {

         temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void showTop()
    {
        int t = getTop();
        
        cout << t << " is at top \n";
    }
    void push(T data)
    {
        newnode = new node;
        if (head == NULL)
        {
            head = newnode;
            newnode->data = data;
            newnode->next = NULL;
        }
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->data = data;
        newnode->next = NULL;
    }

    void pop()
    {
        temp = head;
        if (head == NULL)
        {
            cout << "list empty cannt be deleted" << endl;
            exit(1);
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete temp->next;
    }

    void display()
    {
        if (head != nullptr)
        {
            temp = head;
            while (temp->next != nullptr)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
        else
        {
            cout << "stack is empty" << endl;
        }
    }
};

int main()
{

    LinkedList<int> l;

    l.push(10);
    l.push(500);
    l.push(1);
    l.push(5);
    l.display();
    l.showTop();

    l.pop();
    l.pop();

    l.display();
    l.showTop();
    l.push(333);

    l.push(22);

    l.display();
    l.showTop();
    return 0;
}