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

// search for key value in Linked list

int search(int value)
{
    if (head == NULL)
    {
        printf("List is empty");
    }

    struct Node *current = head;
    int cnt = 0;
    do
    {
        cnt++;
        if (current->data == value)
        {
            return cnt;
        }
        current = current->next;
    } while (current != head);
    return -1;
}

// delete the key element

void delete(int value)
{
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct Node *current = head->next;
    struct Node *previous = head;

    do
    {
        if (current->data == value)
        {
            if (current == previous)
                head = NULL;
            return;
            if (current == head)
            {
                head = current->next;
                previous->next = head;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    } while (previous != head);

    printf("Element not found in the list.");
}

int main()
{
    int choice, value, index;

    printf("1. Insert\n2. Traverse\n3. Search\n4. Delete\n5. Exit");

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
            printf("\nEnter the key: ");
            scanf("%d", &value);
            index = search(value);
            if (index != -1)
            {
                printf("\nKey found at index: %d", index);
            }
            else
            {
                printf("\nKey don't exist");
            }
            break;
        case 4:
            printf("\nEnter the value for deletion: ");
            scanf("%d", &value);
            delete (value);
            break;

        default:
            exit(0);
            break;
        }
    }

    return 0;
}