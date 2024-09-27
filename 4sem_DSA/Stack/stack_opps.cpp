#include <iostream>
using namespace std;

class Stack
{
public:
    int stack[10], top = -1, size;

    Stack(int size)
    {
        this->size = size;
    }

    int push(int);
    int pop();
    void display();
};

int Stack ::push(int data)
{
    if (top >= size - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = data;
        cout << data << " is pushed" << endl;
    }
    return top;
}

int Stack ::pop()
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

void Stack::display()
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
    int n, size, data;

    cout << "Enter the size of a Stack: ";
    cin >> size;

    Stack s1(size);

    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. exit" << endl;

    while (1)
    {
        cout << endl
             << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            s1.push(data);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.display();
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}