#include <iostream>

using namespace std;
struct node
{
    int info, next;
}node[5];
class Queue
{
    int front,rear,avail;
public:
   Queue(){
    front = -1;
    rear = -1;
    avail = 0;
        for (int i = 0; i < 4; i++)
        {
            node[i].next = i + 1;
        }
        node[4].next = -1;
   }
   
    int getnode(void)
    {
        int p;
        if (avail == -1)
        {
            std::cout << "Overflow" << std::endl;
            exit(1);
        }
        p = avail;
        avail = node[avail].next;
        return p;
    }
    void freenode(int p)
    {
        node[p].next = avail;
        avail = p;
        return;
    }
   
    bool empty()
    {
        return ((front == -1) ? true : false);
    }
    
    int insert(int x)
    {
        int p;
        p = getnode();
        node[p].info = x;
        node[p].next = -1;
        if (rear == -1)
            front = p;
        else
            node[rear].next = p;
        rear = p;

    return x;
    }
    int remove()
    {
        int p, x;
        if (empty())
        {
            std::cout << "Underflow" << std::endl;
            exit(1);
        }
        p = front;
        x = node[p].info;
        front = node[p].next;
        if (front == -1)
            rear = -1;
        freenode(p);
        return x;
    }
};
int main()
{
    Queue q;
    cout<<"Enqueue : ";
    for (int i = 0; i < 5; i++)
    {
         cout << q.insert(i);
    }
    cout<<endl;
    cout<<"Dequeue ; ";
    for (int i = 0; i < 4; i++)
    {
     cout << q.remove();
    }
    return 0;
}