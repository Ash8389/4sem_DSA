#include <iostream>
using namespace std;

#define MAX 10
int stack1[MAX], top1 = -1, size = 3;
int stack2[MAX], top2 = -1;
int push2(int);
int pop2();

int push1(int data)
{
    if (top1 >= size - 1)
    {
        cout << "Queue overflow" << endl
             << endl;
    }
    else
    {

        top1++;
        stack1[top1] = data;
        cout << data << " is pushed" << endl
             << endl;
    }
    return top1;
}

int pop1()
{
    if (top1 < 0)
    {
        cout << "Queue underflow" << endl
             << endl;
    }
    else
    {
        while (top1 != -1)
        {
            push2(stack1[top1]);
            top1--;
        }
        pop2();
    }
    return top1;
}

void display1()
{
    if (top1 < 0)
    {
        cout << "Stack Empty" << endl;
    }
    else
    {
        for (int i = 0; i <= top1; i++)
        {
            cout << stack1[i] << " ";
        }
    }
}
int push2(int data)
{
    if (top2 >= size - 1)
    {
        // cout << "Stack overflow" << endl
        //  << endl;
    }
    else
    {
        top2++;
        stack2[top2] = data;
        // cout << data << " is pushed" << endl
        //      << endl;
    }
    return top2;
}

int pop2()
{
    if (top2 < 0)
    {
        cout << "Stack underflow" << endl
             << endl;
    }
    else
    {
        // cout << "Poped element: " << stack2[top2] << endl
        //      << endl;
        top2--;
        while (top2 != -1)
        {
            push1(stack2[top2]);
            top2--;
        }
    }
    return top2;
}

void display2()
{
    if (top2 < 0)
    {
        cout << "Stack Empty" << endl;
    }
    else
    {
        for (int i = 0; i <= top2; i++)
        {
            cout << stack2[i] << " ";
        }
    }
}

int main()
{
    int n;
    cout << ("\n1. for enqueue");
    cout << ("\n2. for dqueue");
    cout << ("\n3. for display");
    cout << ("\n4. for exit");
    while (1)
    {
        cout << ("\nEnter your choice: ");
        cin >> (n);
        switch (n)
        {
        case 1:
            int data;
            cout << endl
                 << "Enter the element: ";
            cin >> data;
            push1(data);
            break;
        case 2:
            pop1();
            break;
        case 3:
            display1();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
        }
    }

    return 0;
}