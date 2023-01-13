#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next , *prev;
   
};
struct node *head = NULL, *newnode, *p, *temp;
class LinkedList
{
public:
    void insertAtBeginning(int data)
    {
        newnode = new node;
        newnode->data = data;
        if (head == NULL)
            head = newnode;
        else
        {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAtEnd(int data)
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
        newnode->prev = temp;
        newnode->data = data;
        newnode->next = NULL;
    }

    void insertAfterNthNode(int nthNode, int data)
    {
        newnode = new node;
        temp = head;
        int count = 1;
        while (count < nthNode)
        {
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->data = data;
        temp->next = newnode;
        newnode->prev = temp;
    }

    void insertBeforeNthNode(int nthNode, int data)
    {
        newnode = new node;

        temp = head;

        if (nthNode == 1)
        {
            newnode->next = temp;
            temp->prev = newnode;
            newnode->data = data;
            head = newnode;
        }
        else
        {
            int count = 1;

            while (count < nthNode - 1)
            {
                temp = temp->next;
                count++;
            }

            newnode->next = temp->next;
            temp->next->prev = newnode;
            newnode->data = data;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    void deleteFromBeginning()
    {
        temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }

    void deleteFromEnd()
    {
        temp = head;
        if (head == NULL)
        {
            cout << "list empty can be deleted" << endl;
            exit(1);
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deleteAfterNthNode(int nthNode)
    {
        temp = head;
        int count = 1;

        while (count < nthNode)
        {
            temp = temp->next;
            count++;
        }

        p = temp->next;
        p->next->prev = temp;
        temp->next = temp->next->next;
        delete p;
    }
    void deleteBeforeNthNode(int nthNode)
    {
        temp = head;
        int count = 1;

        while (count < (nthNode-2))
        {
            temp = temp->next;
            count++;
        }

        p = temp->next;
        p->next->prev = temp;
        temp->next = temp->next->next;
        delete p;
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
            cout << "Linked List is empty" << endl;
        }
    }
};

int main()
{

    LinkedList l;
    cout << "Insertion : "<<endl;
    l.insertAtBeginning(3);
    l.insertAtEnd(2);
    l.insertAtBeginning(1);
    l.insertAtEnd(5);
     l.display();
    l.insertAfterNthNode(3, 699);
    l.insertAfterNthNode(2, 744);
    l.display();
    l.insertBeforeNthNode(2, 255);
    l.insertBeforeNthNode(4, 9777);
    l.display();

    cout << "Deletion : "<<endl;
    l.deleteFromBeginning();
    l.deleteFromEnd();
     l.display();
    l.deleteAfterNthNode(3);
    l.deleteBeforeNthNode(3);
    l.display();
    return 0;
}