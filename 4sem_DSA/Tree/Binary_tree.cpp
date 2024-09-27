#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void buildTree(node *&root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    // root = new node(data); //.If we consider -1 as NULL
    if (data == -1)
    {
        return;
    }
    root = new node(data);
    cout << "Enter the data to insert left of " << data << endl;
    buildTree(root->left);
    cout << "Enter the data to insert right of " << data << endl;
    buildTree(root->right);
}

void LevelOrderTraverse(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    cout << endl;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            // if (temp->left->data != -1)//. If we consider -1 as NULL
            if (temp->left)
                q.push(temp->left);
            // if (temp->right->data != -1)//. If we consider -1 as NULL
            if (temp->right)
                q.push(temp->right);
        }
    }
}
//@REVERSE  LEVEL ORDER TRAVERSE
void RLOT(node *root)
{
    queue<node *> q;
    stack<node *> s;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->right)
                q.push(temp->right);

            if (temp->left)
                q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        node *top = s.top();
        s.pop();
        if (top == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << top->data << " ";
        }
    }
}
//@ LEVEL ORDER INSERTION
void LOI(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter data for root node: ";
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the data for left of " << temp->data << ": ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter the data for right of " << temp->data << ": ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}
void inOrder(node *&root) //->LNR
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(node *&root) //->NLR
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *&root) //->LRN
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root = NULL;
    buildTree(root);
    // LOI(root);
    cout << endl
         << "LEVEL ORDER TRAVERSAL";
    LevelOrderTraverse(root);
    cout << endl
         << "REVERSE LEVEL ORDER TRAVERSAL";
    RLOT(root);
    cout << endl
         << "INORDER: ";
    inOrder(root);
    cout << endl
         << "PREORDER: ";
    preOrder(root);
    cout << endl
         << "POSTORDER: ";
    postOrder(root);
    return 0;
}