#include <iostream>
#define SIZE 6
using namespace std;

template <class T>
class DQueue
{
private:
    T str[SIZE];
    int front, rear, count;

public:
    DQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        if (count == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (count == SIZE)
            return true;
        else
            return false;
    }
    // Enqueue
    void enqueueFromEnd(T elem)
    {
        if (isFull())
            throw "Queue is full";
        else
        {
            rear = (rear + 1) % SIZE;
            str[rear] = elem;
            count++;
        }
        cout << "enqueueFromEnd sucess" << endl;
    }

    void enqueueFromStart(T elem)
    {
        if (isFull())
            throw "Queue is full";
        else
        {
            if (front == 0)
            {
                front = SIZE - 1;
            }
            else
            {
                front--;
            }
            str[front] = elem;
            count++;
        }
        cout << "enqueueFromStart sucess" << endl;
    }
    // Dequeue
    T dequeueFromStart()
    {
        T temp;
        if (isEmpty())
            throw "Queue is empty";
        else
        {
            temp = str[front];
            front = (front + 1) % SIZE;
            count--;
        }
        return temp;
    }
    T dequeueFromEnd()
    {
        T temp;
        if (isEmpty())
            throw "Queue is empty";
        else
        {
            if (rear == 0){ temp = str[rear]; rear = SIZE - 1; }
            else{ temp = str[rear]; rear--; }
            count--;
        }
        return temp;
    }
};

int main()
{
    DQueue<int> q;
    try
    {
        q.enqueueFromEnd(10);
        q.enqueueFromEnd(20);
        q.enqueueFromEnd(30);
        q.enqueueFromStart(40);
        q.enqueueFromStart(50);
        q.enqueueFromStart(60);
        cout << q.dequeueFromEnd() << endl;
        cout << q.dequeueFromStart() << endl;
    }
    catch (const char *err)
    {
        cout << err;
    }
    return 0;
}