#include <iostream>
#include <queue>
#include <utility>
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
        this->right = NULL;
        this->left = NULL;
    }
};

void buildTree(node *&root)
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
        return;
    root = new node(data);
    cout << "Enter data to store in left of " << data << endl;
    buildTree(root->left);
    cout << "Enter data to store in right of " << data << endl;
    buildTree(root->right);
}

void levelOrderTraverse(node *root)
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
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

//! T.C. = O(n^2)
int height(node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}
bool isBalanced(node *root)
{
    if (root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool cond = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && cond)
        return true;

    return false;
}
//! T.C. = O(n)
pair<bool, int> solve(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    bool checkLeft = left.first;
    bool checkRight = right.first;
    bool checkDiff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    ans.second = max(left.second, right.second) + 1;

    if (checkDiff && checkLeft && checkRight)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}
bool isBalanced2(node *root)
{
    return solve(root).first;
}
//. 5 4 3 -1 -1 -1 6 -1 -1 TRUE
//. 5 4 3 -1 2 -1 -1  -1 6 -1 -1 FALSE
int main()
{
    node *root = NULL;
    buildTree(root);
    levelOrderTraverse(root);
    cout << isBalanced(root) << endl;
    cout << isBalanced2(root) << endl;

    return 0;
}