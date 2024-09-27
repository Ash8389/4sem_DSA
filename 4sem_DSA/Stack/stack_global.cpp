#include <iostream>
using namespace std;

#define MAX 10
int stack[MAX], top = -1;

void push(int data)
{
    if (top >= MAX - 1)
    {
        cout << "Stack overflow" << endl
             << endl;
    }
    else
    {
        top++;
        stack[top] = data;
        cout << data << " is pushed" << endl
             << endl;
    }
}

void pop()
{
    if (top < 0)
    {
        cout << "Stack underflow" << endl
             << endl;
    }
    else
    {
        cout << "Poped element: " << stack[top] << endl
             << endl;
        top--;
    }
}

void display()
{
    if (top < 0)
    {
        cout << "Stack Empty" << endl;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
}

int main()
{
    int n, data;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. exit" << endl;

    while (1)
    {
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}