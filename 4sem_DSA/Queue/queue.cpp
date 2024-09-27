#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX];
int size = 3;
int front = -1, rear = -1;

void enqueue()
{
    if (front == -1)
    {
        front++;
    }
    if (rear >= size - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        int data;
        cout << endl
             << "Enter the element: ";
        cin >> data;
        rear++;
        queue[rear] = data;

        cout << "'" << data << "' Pushed" << endl;
    }
}

void dqueue()
{
    if (front > rear || front == -1)
    {
        cout << "Queue is empty1" << endl;
    }
    else
    {
        if (rear == 0)
        {
            front--;
        }

        cout << "'" << queue[0] << "' is deleted" << endl;
        for (int i = 0; i < rear; i++)
        {
            swap(queue[i], queue[i + 1]);
        }
        rear--;
    }
}

void display()
{
    if (front > rear || front == -1)
    {
        cout << "Queue is empty2" << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
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
            enqueue();
            break;
        case 2:
            dqueue();
            break;
        case 3:
            display();
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