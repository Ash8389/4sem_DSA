#include <iostream>
using namespace std;

#define MAX 50
int stack1[MAX], top1 = -1;
int stack2[MAX], top2 = -1;
void push2(int);
void pop2();

void push1(int data)
{
    if (top1 >= MAX - 1)
    {
        cout << "Queue overflow" << endl
             << endl;
    }
    else
    {

        top1++;
        stack1[top1] = data;
    }
}

void pop1()
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
}

void display1()
{
    if (top1 < 0)
    {
        cout << "stack Empty" << endl;
    }
    else
    {
        for (int i = 0; i <= top1; i++)
        {
            cout << stack1[i] << " ";
        }
        cout << endl;
    }
}

void push2(int data)
{
    top2++;
    stack2[top2] = data;
}

void pop2()
{
    cout << stack2[top2] << " is Poped" << endl;
    top2--;
    while (top2 != -1)
    {
        push1(stack2[top2]);
        top2--;
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
            if (top1 >= MAX - 1)
            {
                cout << "Queue is overflow" << endl
                     << endl;
            }
            else
            {
                int data;
                cout << endl
                     << "Enter the element: ";
                cin >> data;
                cout << data << " is Pushed" << endl;
                push1(data);
            }
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