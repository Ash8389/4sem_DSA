#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *buildTree(struct Node *root)
{
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    root = (struct Node *)malloc(sizeof(struct Node));

    root->data = data;
    printf("For left of %d ", root->data);
    root->left = buildTree(root->left);
    printf("For right of %d ", root->data);
    root->right = buildTree(root->right);

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

struct Node *search(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("THIS IS NULL");
        return NULL;
    }

    if (root->data == value)
    {
        printf("FIND");
        return root;
    }
}

int main()
{
    struct Node *root = NULL;
    root = buildTree(root);

    printf("\nInorder: ");
    inOrder(root);
    printf("\nPreorder: ");
    preOrder(root);
    printf("\nPostorder: ");
    postOrder(root);

    struct Node *ans = search(root, 3);
    printf("%d", ans->data);
    return 0;
}