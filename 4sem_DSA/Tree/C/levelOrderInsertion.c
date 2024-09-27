#include <stdio.h>
#include <stdlib.h>

struct Node;

// Queue for storing Node
#define max 10
int front = -1, rear = -1;
struct Node *q[max];
void enqueue(struct Node *data);
struct Node *dqueue();

void enqueue(struct Node *data)
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
        rear++;
        q[rear] = data;
    }
}

struct Node *dqueue()
{
    if (front == -1 || front > rear)
    {
        return NULL;
    }
    else
    {
        int f = front;
        front++;
        return q[f];
    }
}

int qempty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Binary tree starting
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));

    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}
struct Node *levelOrderInserton(struct Node *root)
{
    int data;
    printf("Enter data for root node: ");
    scanf("%d", &data);

    root = newNode(data);
    enqueue(root);

    while (!qempty())
    {
        struct Node *temp = dqueue();

        printf("Enter the data for left of %d: ", temp->data);
        scanf("%d", &data);
        if (data != -1)
        {
            temp->left = newNode(data);
            enqueue(temp->left);
        }
        printf("Enter the data for right of %d: ", temp->data);
        scanf("%d", &data);
        if (data != -1)
        {
            temp->right = newNode(data);
            enqueue(temp->right);
        }
    }

    return root;
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void preOrder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node *root = NULL;
    root = levelOrderInserton(root);

    printf("\nInorder: ");
    inOrder(root);
    printf("\nPreorder: ");
    preOrder(root);
    printf("\nPostorder: ");
    postOrder(root);

    return 0;
}