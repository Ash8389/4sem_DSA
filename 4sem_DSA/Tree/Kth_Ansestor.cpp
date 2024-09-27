#include <iostream>
#include <queue>
#include <limits.h>
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
    cout << "Enter root data: ";
    cin >> data;

    if (data == -1)
        return;

    root = new node(data);

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << ": ";
        cin >> data;

        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << ": ";
        cin >> data;

        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}

void print(node *root)
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

node *solve(node *root, int data, int &k)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
    {
        k--;
        return root;
    }

    node *left = solve(root->left, data, k);
    node *right = solve(root->right, data, k);

    if (k == 0)
    {
        k = INT_MAX;
        return root;
    }
    if (left != NULL && right == NULL)
    {
        k--;
        return left;
    }
    else if (left == NULL && right != NULL)
    {
        k--;
        return right;
    }
    else
        return NULL;
}
int Kth_ansestor(node *root, int data, int k)
{

    if (root == NULL || root->data == data)
    {
        return -1;
    }
    node *ans = solve(root, data, k);

    return ans->data;
}

/*
 ->For 1 the 2nd ansestor is 3

 !                                         10
 !                                         /\
 !                                        /  \
 !                                       3    0
 !                                      /\    /\
 !                                     /  \  /  \
 !                                    21  11 4  23
 !                                        /   \
 !                                       /     \
 !                                      1       2

*/

int main()
{
    node *root = NULL;
    buildTree(root);
    print(root);
    cout << "Kth Ansestor is: " << Kth_ansestor(root, 1, 2);

    return 0;
}