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
        this->left = NULL;
        this->right = NULL;
    }
};
void buildTreeLevelOrder(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
        return;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter data to insert left of " << temp->data << " :";
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter data to insert right of " << temp->data << " :";
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
int height(node *root)
{
    if (root == NULL)
        return 0;

    int lp = height(root->left);
    int rp = height(root->right);

    return (max(lp, rp) + 1);
}
//! TC - O(n^2)
int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int lp = diameter(root->left);
    int rp = diameter(root->right);
    int in = height(root->left) + 1 + height(root->right);

    return max(in, max(lp, rp));
}

//! TC - O(n)
pair<int, int> solve(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    int left_height = left.second;
    int right_height = right.second;
    int height = left_height + right_height + 1;

    int left_dia = left.first;
    int right_dia = right.first;

    pair<int, int> ans;
    ans.first = max(height, max(left_dia, right_dia));

    ans.second = max(left_height, right_height) + 1;

    return ans;
}
int diameter2(node *root)
{
    pair<int, int> ans = solve(root);
    return ans.first;
}
int main()
{
    node *root = NULL;
    buildTreeLevelOrder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    cout << diameter(root);
    cout << endl;
    cout << diameter2(root);

    return 0;
}