
#include <iostream>

using namespace std;

struct Node
{
    int coeff, exp;
    Node *next = nullptr;
};

int main()
{
    Node *poly1 = nullptr;
    Node *poly2 = nullptr;
    Node *poly3 = nullptr;

    int n1, n2;
    cout << "Enter number of terms in the first polynomial: ";
    cin >> n1;

    cout << "Enter number of terms in the second polynomial: ";
    cin >> n2;

    cout << "\nEnter coefficient and exponent of each term of first polynomial:\n";
    for (int i = 0; i < n1; ++i)
    {
        int coeff, exp;
        cin >> coeff >> exp;

        Node *new_node = new Node{coeff, exp};
        new_node->next = poly1;
        poly1 = new_node;
    }

    cout << "\nEnter coefficient and exponent of each term of second polynomial:\n";
    for (int i = 0; i < n2; ++i)
    {
        int coeff, exp;
        cin >> coeff >> exp;

        Node *new_node = new Node{coeff, exp};
        new_node->next = poly2;
        poly2 = new_node;
    }

    Node *p1 = poly1;
    Node *p2 = poly2;
    Node *p3 = poly3;

    while (p1 && p2)
    {
        if (p1->exp > p2->exp)
        {
            Node *new_node = new Node{p1->coeff, p1->exp};
            new_node->next = p3;
            p3 = new_node;

            p1 = p1->next;
        }
        else if (p2->exp > p1->exp)
        {
            Node *new_node = new Node{p2->coeff, p2->exp};
            new_node->next = p3;
            p3 = new_node;

            p2 = p2->next;
        }
        else
        {
            Node *new_node = new Node{(p1->coeff + p2->coeff), p1->exp};
            new_node->next = p3;
            p3 = new_node;

            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1)
    {
        Node *new_node = new Node{p1->coeff, p1->exp};
        new_node->next = p3;
        p3 = new_node;

        p1 = p1->next;
    }

    while (p2)
    {
        Node *new_node = new Node{p2->coeff, p2->exp};
        new_node->next = p3;
        p3 = new_node;

        p2 = p2->next;
    }

    cout << "\nsum of the two polynomials is:\n";
    while (p3)
    {
        if (p3->coeff != 0)
        {
            if (p3->coeff != 1)
            {
                cout << p3->coeff;
            }

            if (p3->exp == 1)
            {
                cout << "x";
            }
            else if (p3->exp > 1)
            {
                cout << "x^" << p3->exp;
            }

            if (p3->next && p3->next->coeff > 0)
            {
                cout << " + ";
            }
        }

        p3 = p3->next;
    }

    return 0;
}