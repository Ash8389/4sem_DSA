#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Initializing an empty list
struct Node *head = NULL;

//  Creating linked list
void insert(int value)
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
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    newNode->next = head;
}

// Print all elements of linked list

void traverse()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    struct Node *current = head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
}

// delete the key element

void delete()
{
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct Node *current = head->next;
    struct Node *previous = head;
    if (current == previous)
    {
        head = NULL;
        return;
    }

    while (current->next != head)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return;
}

int main()
{
    int choice, value, index;

    printf("1. Insert\n2. Traverse\n.3. Delete\n4. Exit");

    while (choice != 5)
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
            delete ();
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}