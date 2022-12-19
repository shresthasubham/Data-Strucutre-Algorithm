#include <iostream>
#define max 10

using namespace std;
template <class T>
class Stack
{
private:
    T stack[max];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(T item)
    {
        if (top >= max - 1)
            throw("\nStack Overflow");
        else
            stack[++top] = item;
    }
    T pop()
    {
        if (top < 0)
            throw("Stack UnderFlow");
        else
            return stack[top--];
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top >= (max - 1));
    }
    int giveTop()
    {
        return top;
    }
    T getTop()
    {
        return stack[top];
    }
};

int main()
{
    Stack<int> x;
    int a;
    try
    {
        for (int i = 0; i < max; i++)
        {
            cout << "Enter 0 to exit ::";
            cin >> a;
            if (a == 0)
                break;
            else
                x.push(a);
        }
        cout << "Popping out from top ::";
        while (x.giveTop() >= 0)
        {
            cout << ' ' << x.pop();
        }
        cout << '\n';
    }
    catch (const char *err)
    {
        cout << err;
    }
    return 0;
}
