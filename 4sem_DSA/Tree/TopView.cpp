#include <iostream>
#include <queue>
#include <map>
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
void buildTree(node *&root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1)
        return;

    root = new node(data);

    cout << "Left of " << data;
    buildTree(root->left);
    cout << "Right of " << data;
    buildTree(root->right);
}
void traverse(node *root)
{
    if (root == NULL)
        return;

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
vector<int> topView(node *root)
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

        node *frontNode = temp.second;
        int HD = temp.first;

        if (nodes.find(HD) == nodes.end())
            nodes[HD] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(HD - 1, frontNode->left));
        if (frontNode->right)
            q.push(make_pair(HD + 1, frontNode->right));
    }
    for (auto x : nodes)
    {
        ans.push_back(x.second);
    }

    return ans;
}
int main()
{

    node *root = NULL;
    buildTree(root);
    cout << endl;
    traverse(root);
    cout << endl;
    topView(root);

    return 0;
}