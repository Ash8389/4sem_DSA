#include <iostream>
#include <queue>
#include <vector>
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

void levelOrderInsert(node *&root)
{
    queue<node *> q;

    int data;
    cout << "Enter root data: ";
    cin >> data;
    if (data == -1)
        return;

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data for store in left of " << temp->data << ": ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter data for store in right of " << temp->data << ": ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//! Boundry Traverse
class boundryTraverse
{
    void forleft(node *, vector<int> &);
    void leftToRight(node *, vector<int> &);
    void forright(node *, vector<int> &);

public:
    vector<int> traverse(node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        forleft(root->left, ans);
        leftToRight(root->left, ans);
        leftToRight(root->right, ans);
        forright(root->right, ans);

        return ans;
    }
};

void boundryTraverse::forleft(node *root, vector<int> &res)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    cout << "L" << root->data << " ";
    res.push_back(root->data);

    if (root->left)
        forleft(root->left, res);
    else
        forleft(root->right, res);
}
void boundryTraverse::leftToRight(node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << "LTR" << root->data << " ";
        res.push_back(root->data);
        return;
    }
    leftToRight(root->left, res);
    leftToRight(root->right, res);
}
void boundryTraverse::forright(node *root, vector<int> &res)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        forright(root->right, res);
    else
        forright(root->left, res);

    // cout << "R = " << root->data << " ";
    res.push_back(root->data);
}

int main()
{
    node *root = NULL;
    levelOrderInsert(root);
    cout << endl;
    inorder(root);
    cout << endl;

    boundryTraverse a;
    vector<int> res = a.traverse(root);

    for (auto it : res)
        cout << it << " ";

    return 0;
}