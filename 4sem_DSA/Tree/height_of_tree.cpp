#include <iostream>
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
    if (data == -1)
    {
        return;
    }
    root = new node(data);
    cout << "Enter the data for left of " << data << endl;
    buildTree(root->left);
    cout << "Enter the data for right of " << data << endl;
    buildTree(root->right);
}
void inorderTraverse(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraverse(root->left);
    cout << root->data << " ";
    inorderTraverse(root->right);
}
int height(node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    // cout << endl
    //      << "leftHeight: " << leftHeight;
    int rightHeight = height(root->right);
    // cout << endl
    //      << "rightHeight: " << rightHeight;
    // cout << endl
    //  << "max(leftHeight, rightHeight) + 1: " << max(leftHeight, rightHeight) + 1;
    return (max(leftHeight, rightHeight) + 1);
}
int main()
{
    node *root = NULL;
    buildTree(root);
    inorderTraverse(root);
    cout << endl
         << height(root);
    return 0;
}