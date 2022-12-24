#include <iostream>
#define SIZE 5
using namespace std;

template <class T>
class CQueue
{
private:
    T str[SIZE];
    int front, rear, count;

public:
    CQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        if ( count == 0 )
            return true;
        else 
            return false;
    }

    bool isFull()
    {
        if (count == SIZE )
            return true;
        else
            return false;
    }
    // Enqueue
    void enqueue(T elem)
    {
        if (isFull())
            throw "Queue is full";
        else{
            rear = (rear + 1) % SIZE;
            str[rear] = elem;
            count++;
        }
        cout << "enqueue sucess" << endl;
    }
    // Dequeue
    T dequeue()
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
};

int main()
{
    CQueue<int> q;
    try
    {
        for (size_t i = 0; i < SIZE; i++)
            q.enqueue(i);
        for (size_t i = 0; i < SIZE; i++)
            cout << q.dequeue()<< " ";
    }
    catch (const char *err)
    {
        cout << err;
    }

    return 0;
}
