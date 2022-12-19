#include <iostream>
#include <cstring>
#define MAX 10
using namespace std;
template <class T>
class Stack
{
private:
    int top;
    T str[MAX];
public: 
Stack()
{
    top = -1;
}
bool isFull()
{
    if (top == (MAX - 1))
        return true;
    else
        return false;
}
bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
void push (T data)
{
    if (isFull())
        throw "stack overflow ";
    else
        str[++top] = data;
}
T pop()
{
    if (isEmpty())
        throw "stack underflow"; 
    else
        return str[top--];
}
void display()
{
    for (size_t i = 0; i <= top; i++)
        cout << "a" << i << "=" << str[i] << endl;
    cout << endl;
}
T getTop()
{
    return str[top];
}
};

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c)
{
    if (c == '^' || c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}

string Postfix(string infix)
{
    string postfix;
    Stack<int> s;
       for (size_t i = 0; i < infix.length(); i++)
    {
        // FOR operand
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        // FOR  operator
        else if (isOperator(infix[i]))
        {
            if (s.isEmpty())
                s.push(infix[i]);
            else if (precedence(infix[i]) > precedence(s.getTop()))
                s.push(infix[i]);
            else if (precedence(infix[i]) <= precedence(s.getTop()))
            {
                while (precedence(infix[i]) <= precedence(s.getTop()))
                {
                    postfix += s.pop();
                }
                s.push(infix[i]);
            }
        }
        // FOR parenthesis
        else if (infix[i] == '(')
            s.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (s.getTop() != '(')
            {
                postfix += s.pop();
            }
            s.pop();
        }
    }
    while (!s.isEmpty())
        postfix += s.pop();
     return postfix;
}
int main()
{
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    try{
        
         cout << "The required postfix expression is : " << Postfix(infix);
    }
    catch(const char *err){
        cout << err << endl;
    }
        return 0;
}