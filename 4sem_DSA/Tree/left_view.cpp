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
void levelOrderInsertion(node *&root)
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
        cout << endl;
    }
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

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
void solve(node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() == lvl)
        ans.push_back(root->data);

    solve(root->left, ans, lvl + 1);
    solve(root->right, ans, lvl + 1);
}
vector<int> leftView(node *root)
{
    vector<int> ans;

    solve(root, ans, 0);
    return ans;
}
int main()
{
    node *root = NULL;
    levelOrderInsertion(root);
    levelOrderTraversal(root);

    cout << endl;
    vector<int> res = leftView(root);
    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}