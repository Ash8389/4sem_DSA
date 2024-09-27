#include <stdio.h>
#include <stdlib.h>
#define max 10
int front = -1, rear = -1;
int a[max];
void enqueue();
void dqueue();
void display();
int main()
{
    char ch;
    while (1)
    {
        printf("\n1 for enqueue\n");
        printf("  2 for dqueue\n");
        printf("  3 for display\n");
        printf("  4 for exit\n");
        printf("  enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
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
    return (1);
}
void enqueue()
{
    int num;
    if (rear == max - 1)
    {
        printf("**queue is full**\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
        }
        printf("Enter number to Push\n");
        scanf("%d", &num);
        rear++;
        if (rear == 0)
        {
            a[rear] = num;
        }
        else
        {
            int i = 0;
            while (a[i] > num)
            {
                i++;
                if (i == rear)
                {
                    a[i] = num;
                    return;
                }
            }
            int j = rear;
            while (i < j)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[i] = num;
        }
    }
}
void dqueue()
{
    if (front == -1 || front > rear)
    {
        printf("**queue Is empty**\n");
    }
    else
    {
        printf("%d is deleted  ", a[front]);
        front++;
    }
}
void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("**queue Is empty**\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {

            printf("%d | ", a[i]);
        }
    }
}
