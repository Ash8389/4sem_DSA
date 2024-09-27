#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildTree(Node *&root)
{
    int data;

    cout << " Enter data: ";
    cin >> data;

    if (data == -1)
        return;

    root = new Node(data);

    cout << "for left of " << data;
    buildTree(root->left);

    cout << "for right of " << data;
    buildTree(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inorder(Node *root, queue<Node *> &q)
{
    if (root == NULL)
        return;

    inorder(root->left, q);
    q.push(root);
    inorder(root->right, q);
}
Node *bToDLL(Node *root)
{
    // your code here
    queue<Node *> q;

    inorder(root, q);

    Node *head = q.front();

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        Node *secNode;

        if (!q.empty())
            secNode = q.front();
        else
            secNode = NULL;

        if (frontNode == head)
        {
            frontNode->left = NULL;
        }
        if (!q.empty())
        {
            frontNode->right = secNode;
            secNode->left = frontNode;
        }
        else
        {
            frontNode->right = NULL;
        }
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
    return head;
}

int main()
{
    Node *root = NULL;

    buildTree(root);
    cout << endl;
    inOrder(root);
    cout << endl;

    // queue<Node *> q;
    // inorder(root, q);
    // while (!q.empty())
    // {
    //     cout << q.front()->data << " ";
    //     q.pop();
    // }
    Node *LL = bToDLL(root);

    return 0;
}