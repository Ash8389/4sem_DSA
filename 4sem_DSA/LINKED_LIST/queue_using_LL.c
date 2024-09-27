#include <stdio.h>
#include <stdlib.h>
#define max 10

struct Node
{
    int data;
    struct Node *next;
};

// Initializing an empty list
struct Node *head = NULL;
//  Push
void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Print all elements of stack
void display(struct Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    printf("%d ", curr->data);
    display(curr->next);
}

// pop
void pop()
{
    struct Node *current = head;
    if (head == NULL)
    {
        printf("\nQueue is underflow.");
        return;
    }
    else if (current->next == NULL)
    {
        printf("Poped element is: %d", head->data);
        head = NULL;
        free(current);
        return;
    }

    head = current->next;

    printf("Poped element is: %d", current->data);
    free(current);
}

int main()
{
    int choice, value, size = 0;
    struct Node *curr;

    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");

    while (choice != 5)
    {
        curr = head;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (size < max)
            {
                printf("\nEnter the value for push: ");
                scanf("%d", &value);
                push(value);
                size++;
            }
            else
            {
                printf("\Queue overflow");
            }
            break;
        case 2:
            if (size > 0)
            {
                size--;
            }
            pop();
            break;
        case 3:
            if (head == NULL)
            {
                printf("\nStack is empty");
            }
            else
            {
                display(head);
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please Enter correct option: ");
        }
    }

    return 0;
}