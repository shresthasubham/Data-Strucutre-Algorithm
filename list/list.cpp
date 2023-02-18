#include<iostream>
using namespace std;
class List
{
private:
    struct node
    {

        int data;
        int next;
    };
    node arr[10];
    int start;
    int avail;
public:
    List()
    {
        avail =0;
        start= -1;
        for(int i=0;i<10;i++)
        {
            arr[i].next= i+1;
        }
        arr[9].next= -1;
    }
    int getNode(int a)
    {
        if(avail== -1)
        {
            cout<<"overflow"<<endl;
            return 0;
        }
        else
            {
                int index= avail;
                avail= arr[index].next;
                arr[index].data=a;
                arr[index].next = -1;
                return index;
            }
    }
    void freeNode(int index)
    {
        arr[index].next=avail;
        avail = index;
        if (index==start) start = -1;
    }
    void insertFromBeginning(int data)
    {
        int i = getNode(data);
        arr[i].next = start;
        start = i;
    }
    void insertFromEnd(int data)
    {
        if(start == -1)
        {
            insertFromBeginning(data);
        }
        else
        {
            int temp =start;
            while(arr[temp].next!= -1)
            {
                temp = arr[temp].next;
            }
            arr[temp].next = getNode(data);
        }
    }
    void insertAfter(int data, int y)
    {
        int temp = start;
        while(arr[temp].data!=y)
        {
            temp = arr[temp].next;
        }
        int i = getNode(data);
        arr[i].next = arr[temp].next;
        arr[temp].next = i;
    }
    void deleteFromBeginnning()
    {
        if(start==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            int i = start;
            start = arr[start].next;
            freeNode(i);
        }
    }
    void deleteFromEnd()
    {
        if(start == -1)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            int temp_one=start;
            int temp_two = arr[start].next;
            if(temp_two==-1)
            {
                deleteFromBeginnning();
            }
            else
            {
                while(arr[temp_two].next!=-1)
                {

                    temp_one = temp_two;
                    temp_two = arr[temp_two].next;
                }
                freeNode(temp_two);
                arr[temp_one].next = -1;
            }
        }
    }
    void deleteAfter(int y)
    {
        if(start ==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            int temp = start;
            while(arr[temp].data!=y)
            {
                temp = arr[temp].next;
            }
            if(arr[temp].next==-1)
            {
                cout<<"no node"<<endl;

            }
            else
            {
                int del = arr[temp].next;
                arr[temp].next= arr[del].next;
                freeNode(del);
            }
        }
    }
    void show()
    {
        int temp = start;
        while(temp!=-1)
        {
            cout<<arr[temp].data<<" ";
            temp= arr[temp].next;
        }
        cout<<endl;
    }


};
int main()
{
    List l;
    cout<<"insertion : ";
    l.insertFromBeginning(3);
    l.insertFromBeginning(2);
    l.insertFromBeginning(1);
    l.insertFromEnd(4);
    l.show();
    cout<<"deletion : ";
    l.deleteFromBeginnning();
    l.deleteFromEnd();
    l.show();
    l.insertAfter(5,2);
    l.show();
    l.deleteAfter(2);
    l.show();

}

