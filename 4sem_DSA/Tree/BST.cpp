#include <iostream>
#include <queue>
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
void levelOrderTraverse(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

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
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
void buildBST(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return;
    }
    if (data <= root->data)
        buildBST(root->left, data);

    if (data > root->data)
        buildBST(root->right, data);
}
node *search(node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    if (data > root->data)
        return search(root->right, data);
}

void remove(node *&root, int data)
{
    if (root == NULL)
    {
        cout << "Node not found" << endl;
        return;
    }
    // ! if (root->data == data)
    // ! {
    // !     root->right;
    // !     root = root->right;
    // !     return;
    // ! }
    if (data < root->data)
        remove(root->left, data);

    if (data > root->data)
        remove(root->right, data);
}
int main()
{
    node *root = NULL;
    buildBST(root, 5);
    levelOrderTraverse(root);
    cout << endl;
    buildBST(root, 6);
    levelOrderTraverse(root);
    cout << endl;
    buildBST(root, 2);
    levelOrderTraverse(root);
    cout << endl;
    buildBST(root, 3);
    levelOrderTraverse(root);
    cout << endl;
    buildBST(root, 1);
    levelOrderTraverse(root);
    cout << endl;
    buildBST(root, 8);
    levelOrderTraverse(root);
    cout << endl;
    buildBST(root, 7);
    levelOrderTraverse(root);
    cout << endl;

    // cout << search(root, 3)->data;
    // cout << endl
    //      << endl;

    remove(root, 2);
    levelOrderTraverse(root);
    cout << endl;

    return 0;
}