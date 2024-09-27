#include <iostream>
#include <queue>
#include <map>
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
    int data;
    cout << "Enter root data: ";
    cin >> data;

    if (data == -1)
        return;

    queue<node *> q;

    root = new node(data);
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
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

vector<int> bottomView(node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> nodes;
    queue<pair<int, node *>> q;

    q.push(make_pair(0, root));

    while (!q.empty())
    {
        pair<int, node *> temp = q.front();
        q.pop();

        int HD = temp.first;
        node *frontNode = temp.second;

        nodes[HD] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(HD - 1, frontNode->left));
        }
        if (frontNode->right)
        {
            q.push(make_pair(HD + 1, frontNode->right));
        }
    }
    for (auto it : nodes)
    {
        cout << it.second << " ";
        ans.push_back(it.second);
    }
}
int main()
{
    node *root = NULL;
    levelOrderInsert(root);
    cout << endl;
    inorder(root);
    cout << endl;
    bottomView(root);

    return 0;
}