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
    bool isThreaded; // Indicates whether the right pointer is a thread
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->isThreaded = false; // Initially, no threads
    }
};

void buildTree(node *&root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

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

// Function to find the leftmost node in the tree
node *leftMost(node *current)
{
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current;
}

// Function to do an inorder traversal of the threaded binary tree
void inOrderThreaded(node *root)
{
    node *current = leftMost(root);

    while (current != NULL)
    {
        cout << current->data << " ";

        if (current->isThreaded)
            current = current->right;
        else
            current = leftMost(current->right);
    }
}

// Function to convert a binary tree into a threaded binary tree
void insertInorder(node *&root, queue<node *> &q)
{
    if (root == NULL)
        return;

    insertInorder(root->left, q);
    q.push(root);
    insertInorder(root->right, q);
}
void convertToThreaded(node *&root)
{
    queue<node *> q;
    insertInorder(root, q);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        // cout << temp->data << " :1" << endl;
        if (!q.empty())
        {
            // cout << temp->data << " :2" << endl;
            if (temp->right == NULL)
            {
                temp->isThreaded = true;
                // cout << temp->data << " :3" << endl;
                // cout << temp->data << "->" << q.front()->data << endl;
                temp->right = q.front();
            }
        }
    }
}

void displayThread(node *root)
{
    if (root == NULL)
    {
        return;
    }
    displayThread(root->left);

    if (root->isThreaded == true)
    {
        cout << root->data << "->" << root->right->data << endl;
    }
    else
    {
        displayThread(root->right);
    }
    // while (root != NULL)
    // {
    //     cout << root->data << " ";
    //     if (root->isThreaded)
    //         root = root->left;
    //     else
    //         root = root->right;
    // }
}
// void convertToThreaded(node *root, node *&prev)
// {
//     if (root == NULL)
//     {
//         // root->left = NULL;
//         cout << "IN\n";
//         return;
//         // root->isThreaded = true;
//     }
//     convertToThreaded(root->left, prev);
//     if (root->right != NULL)
//     {
//         cout << "check" << root->data << endl;
//         root->isThreaded = true;
//         root->right = prev;
//     }
//     convertToThreaded(root->right, root);
// }
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
int main()
{
    queue<node *> q;
    node *root = NULL;
    buildTree(root);

    LevelOrderTraverse(root);
    // insertInorder(root, q);
    convertToThreaded(root);
    displayThread(root);
    // while (!q.empty())
    // {
    //     cout << q.front()->data << " ";
    //     q.pop();
    // }
    // Convert the binary tree into a threaded binary tree
    node *prev = NULL; // Pointer to keep track of the previously visited node

    // Inorder traversal of the threaded binary tree
    // cout << "Inorder traversal of the threaded binary tree: ";
    // inOrderThreaded(root);

    return 0;
}
