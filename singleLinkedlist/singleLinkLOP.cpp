#include<iostream>
using namespace std;
struct node{
int data;
 struct node *next;
};
struct node *head=NULL,*newnode,*p,*temp;

template <class T>
class LinkedList
{
  
public:
  
    void insertAtBeginning(T data)
    {
       newnode=new node;
       newnode->data=data;
       newnode->next=head;
       head=newnode;
       
    }

    void insertAtEnd(T data)
    {
        newnode=new node;
         if(head==NULL){
            head=newnode;
            newnode->data=data;
            newnode->next=NULL;
        

         }
         temp=head;
         while(temp->next!=NULL)
         {
            temp=temp->next;
         }
         temp->next=newnode;
         newnode->data=data;
         newnode->next=NULL;
        
        
    }

    void insertAfterNthNode(int nthNode, T data)
    { 
        newnode=new node;
        temp=head;
        int count=1;
        while(count<nthNode){
            temp=temp->next;
            count++;
        }
       newnode->next=temp->next;
       newnode->data=data;
       temp->next=newnode;


    }

    void insertBeforeNthNode(int nthNode, T data)
    {
         newnode = new node;

         temp = head;

        if (nthNode == 1)
        {
            newnode->next = temp;
            newnode->data=data;
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
            newnode->data=data;
            temp->next = newnode;
        }
        
    }

    void deleteFromBeginning()
    {
        temp=head;
        head=temp->next;
        delete temp;

    }

    void deleteFromEnd()
    {
       temp=head;
       if(head==NULL){
        cout<<"list empty can be deleted"<<endl;
        exit(1);
       }
       while(temp->next->next !=NULL){
        temp=temp->next;
       }
        temp->next=NULL;
        delete temp->next;
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

    LinkedList<int> l;
    l.insertAtBeginning(10);
    l.insertAtEnd(500);
    l.insertAtBeginning(16);
    l.insertAtBeginning(2);

    l.insertAtEnd(60);

    l.insertAfterNthNode(3, 5);
    l.insertAfterNthNode(1, 8);

    l.insertBeforeNthNode(2, 9);
    l.insertBeforeNthNode(1, 6);
      l.display();
    l.deleteFromBeginning();
    l.deleteFromEnd();
    l.deleteAfterNthNode(3);

    l.display();
    return 0;

}