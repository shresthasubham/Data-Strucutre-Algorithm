#include <iostream>
#include <cstring>
#define MAX 100
// Q.N.     (A+(B*C-(D/E^F)*G)*H)
// ANSWER   +A*-*BC*/D^EFGH
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
void push(T data)
{
    if (isFull())
        throw "stack overflow";
    else
        str[++top] = data;
}
T pop()
{
    if (isEmpty())
        throw "stack underflow "; 
    else
        return str[top--];
}

T getTop()
{
    return str[top];

}
};
string reverse(string infix){
    string rev;
    for (size_t i = 0; i < infix.length(); i++)
        rev += infix[infix.length()-1-i] ;
    return rev;
}

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

string Prefix(string infix)
{
    string prefix;
    Stack<char> s;

    infix = reverse(infix) ;

    for (size_t i = 0; i < infix.length(); i++)
    {
        // FOR operand
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            prefix += infix[i];
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
                    prefix += s.pop();
                }
                s.push(infix[i]);
            }
        }
        // FOR parenthesis
        else if (infix[i] == ')')
            s.push(infix[i]);
        else if (infix[i] == '(')
        {
            while (s.getTop() != ')')
            {
                prefix += s.pop();
            }
            s.pop();
        }
    }

    while (!s.isEmpty())
        prefix += s.pop();
    return reverse(prefix) ;
} 
int main()
{
    string infix;
    cout << "Enter infix : ";
    cin >> infix;

    try{
        cout << "The prefix expression is : " << Prefix(infix);
    }
    catch(const char *err){
        cout << err << endl;
    }
    return 0;
}
