#include <iostream>
using namespace std;

int push(int stack[], int size, int top)
{
    int data;
    if (top >= size - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        cout << "Enter the data: ";
        cin >> data;
        top++;
        stack[top] = data;
        cout << data << " is pushed" << endl;
    }
    return top;
}

int pop(int stack[], int size, int top)
{
    if (top < 0)
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        cout << "Poped element: " << stack[top] << endl;
        top--;
    }
    return top;
}

void display(int stack[], int size, int top)
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
    int stack[10], top = -1, size = 3;
    int n;

    cout << "Enter the size of a Stack: ";
    cin >> size;
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
            top = push(stack, size, top);
            break;
        case 2:
            top = pop(stack, size, top);
            break;
        case 3:
            display(stack, size, top);
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}