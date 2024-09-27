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
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
    {
        return;
    }

    root = new node(data);

    cout << "Enter data to store in left of " << data;
    buildTree(root->left);
    cout << "Enter data to store in right of " << data;
    buildTree(root->right);
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isEqual(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL)
        return false;
    if (root1 != NULL && root2 == NULL)
        return false;

    bool left = isEqual(root1->left, root2->left);
    bool right = isEqual(root1->right, root2->right);
    bool data = root1->data == root2->data;

    if (left && right && data)
        return true;

    return false;
}
int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    buildTree(root1);
    cout << endl;
    buildTree(root2);
    cout << endl;
    inorder(root1);
    cout << endl;
    inorder(root2);
    cout << endl;
    cout << isEqual(root1, root2);

    return 0;
}