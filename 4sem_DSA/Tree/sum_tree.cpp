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
void levelOrderInsert(node *&root)
{
    int data;
    queue<node *> q;
    cout << "Enter data to stored in root: ";
    cin >> data;
    if (data == -1)
        return;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter data to store in left of " << temp->data << ": ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter data to store in right of " << temp->data << ": ";
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
pair<bool, int> solve(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    bool leftCheck = left.first;
    bool rightCheck = right.first;
    bool sumCheck = left.second + right.second == root->data;

    pair<bool, int> ans;
    ans.second = 2 * root->data;

    if (leftCheck && rightCheck && sumCheck)
    {
        ans.first = true;
        return ans;
    }
    else
    {
        ans.first = false;
        return ans;
    }
}
bool sumTree(node *root)
{
    return solve(root).first;
}
//. 26 10 3 4 6 -1 3 -1 -1 -1 -1 -1 -1 TRUE
int main()
{
    node *root = NULL;
    levelOrderInsert(root);
    cout << endl;
    inorder(root);
    cout << endl;
    cout << sumTree(root);

    return 0;
}