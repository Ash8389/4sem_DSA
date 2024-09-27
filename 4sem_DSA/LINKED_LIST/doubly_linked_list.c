#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
};

// Initializing an empty list
struct Node *head = NULL;

//  Creating linked list
void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;

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
        newNode->previous = current;
    }
}

// Print all elements of linked list
void traverse()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// delete the position node
void delete(int position)
{
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    struct Node *back = NULL;
    struct Node *current = head;
    struct Node *front = head->next;

    if (position == 1)
    {
        head = front;
        if (front != NULL)
            front->previous = NULL;
    }
    else
    {
        int count = 1;
        while (count < position)
        {
            back = current;
            current = current->next;
            // Checking if front is NULL, for last elementss
            if (front != NULL)
                front = front->next;
            if (current == NULL)
            {
                printf("Element not found in the list.");
                return;
            }
            count++;
        }
        back->next = front;
        // Checking if front is NULL, for last element
        if (front != NULL)
            front->previous = back;
    }
    free(current);
}

int main()
{
    int choice, value, index;

    printf("1. Insert\n2. Traverse\n3. Delete\n4. Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value for insertion: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            traverse();
            break;
        case 3:
            printf("\nEnter the position of node for deletion: ");
            scanf("%d", &value);
            delete (value);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input");
        }
    }

    return 0;
}