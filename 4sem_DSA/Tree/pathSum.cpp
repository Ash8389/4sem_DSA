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

node *buildTree(node *root)
{
    int data;
    cout << " Enter data: ";
    cin >> data;

    if (data == -1)
        return NULL;

    root = new node(data);

    cout << "For left of " << data;
    root->left = buildTree(root->left);
    cout << "For right of " << data;
    root->right = buildTree(root->right);

    return root;
}
void print(node *root)
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

void solve(node *root, vector<int> pathNode, int &count, int givenSum)
{
    if (root == NULL)
        return;

    pathNode.push_back(root->data);

    int sum = 0;
    for (auto it : pathNode)
    {
        sum += it;
    }
    if (sum == givenSum)
        count++;
    solve(root->left, pathNode, count, givenSum);
    solve(root->right, pathNode, count, givenSum);
}
int pathSum(node *root, int sum)
{
    int count = 0;
    vector<int> pathNode;

    solve(root, pathNode, count, sum);

    return count;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    print(root);
    cout << "SUM: " << pathSum(root, 8);

    return 0;
}