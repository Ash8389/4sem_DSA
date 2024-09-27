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
    }
}

int pop()
{
    if (top < 0)
    {
        cout << "Stack underflow" << endl
             << endl;
    }
    else
    {
        int data = stack[top];
        top--;
        return data;
    }
}

int ftop()
{
    return stack[top];
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
            cout << stack[i] << " ";
        }
    }
    cout << endl;
}

void sortinsert(int x)
{
    if (top == -1 || x > ftop())
    {
        push(x);
        return;
    }
    int temp = pop();
    sortinsert(x);
    push(temp);
}
void sortStack()
{
    if (top != -1)
    {
        int x = ftop();
        pop();
        sortStack();
        sortinsert(x);
    }
}

int main()
{
    push(30);
    push(-5);
    push(14);
    push(-14);
    push(6);

    cout << "Before Sorting" << endl;
    display();

    sortStack();

    cout << "After Sorting" << endl;
    display();

    return 0;
}