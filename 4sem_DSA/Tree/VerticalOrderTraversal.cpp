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
void buildTree(node *&root)
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
        return;
    root = new node(data);

    cout << "Left of " << data;
    buildTree(root->left);
    cout << "Right of " << data;
    buildTree(root->right);
}
void Traverse(node *root)
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
                q.push(NULL);
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

vector<int> verticalOrderTraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int HD = temp.second.first;
        int lvl = temp.second.second;

        // cout << HD << " , " << lvl << "=" << frontNode->data << " | ";
        nodes[HD][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(HD - 1, lvl + 1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(HD + 1, lvl + 1)));
    }
    for (auto x : nodes)
    {
        for (auto y : x.second)
        {
            for (auto z : y.second)
            {
                // cout << "X: " << x.first << " Y: " << y.first << " Z: " << z << " |";
                ans.push_back(z);
            }
        }
    }
    return ans;
}

int main()
{
    node *root = NULL;

    buildTree(root);
    cout << endl;
    Traverse(root);
    cout << endl;
    vector<int> res = verticalOrderTraversal(root);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}