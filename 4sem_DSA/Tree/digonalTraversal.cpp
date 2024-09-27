#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildTree(Node *&root)
{
    int data;

    cout << " Enter data: ";
    cin >> data;

    if (data == -1)
        return;

    root = new Node(data);

    cout << "for left of " << data;
    buildTree(root->left);

    cout << "for right of " << data;
    buildTree(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

vector<int> diagonalTraversal(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, vector<int>> node;
    queue<pair<int, Node *>> q;

    q.push(make_pair(0, root));

    while (!q.empty())
    {
        pair<int, Node *> temp = q.front();
        q.pop();

        int lvl = temp.first;
        Node *frontNode = temp.second;

        node[lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(lvl + 1, frontNode->left));
        if (frontNode->right)
            q.push(make_pair(lvl, frontNode->right));
    }

    for (auto it : node)
    {
        for (auto in : it.second)
            ans.push_back(in);
    }

    return ans;
}

void solve(Node *root, int lvl, map<int, vector<int>> &nodes)
{
    if (root == NULL)
        return;

    nodes[lvl].push_back(root->data);

    solve(root->left, lvl + 1, nodes);
    solve(root->right, lvl, nodes);
}

vector<int> diagonal(Node *root)
{
    // your code here
    map<int, vector<int>> nodes;
    vector<int> ans;

    solve(root, 0, nodes);

    for (auto it : nodes)
        for (auto in : it.second)
            ans.push_back(in);

    return ans;
}
int main()
{
    Node *root = NULL;

    buildTree(root);
    cout << "\nINORDER TRAVERSAL: ";
    inOrder(root);
    cout << "\n*************DIGONAL TRAVERSAL****************";

    vector<int> res2 = diagonalTraversal(root);
    vector<int> res1 = diagonal(root);

    cout << endl
         << "USING RECURSION: ";
    for (auto it : res1)
        cout << it << " ";

    cout << endl
         << "USING Queue: ";
    for (auto it : res2)
        cout << it << " ";

    return 0;
}