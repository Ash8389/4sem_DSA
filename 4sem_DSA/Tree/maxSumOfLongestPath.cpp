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
void buildTree(node *&root)
{
    int data;
    cout << "Enter root data: ";
    cin >> data;

    if (data == -1)
    {
        return;
    }

    root = new node(data);

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << " :";
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << " :";
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
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

//->MAX SUM OF LONGEST PATH
void solve(node *root, int lvl, int &maxLvl, int sum, int &maxSum)
{

    if (root == NULL)
    {
        if (lvl > maxLvl)
        {
            maxLvl = lvl;
            maxSum = sum;
        }
        else if (lvl == maxLvl)
        {
            maxSum = max(maxSum, sum);
        }

        return;
    }

    solve(root->left, lvl + 1, maxLvl, sum + (root->data), maxSum);
    solve(root->right, lvl + 1, maxLvl, sum + (root->data), maxSum);
}
int maxSum(node *root)
{
    int lvl = 0;
    int maxLvl = 0;
    int sum = 0;
    int maxSum = 0;

    solve(root, lvl, maxLvl, sum, maxSum);

    return maxSum;
}

int main()
{
    node *root = NULL;

    buildTree(root);
    print(root);

    cout << "MAX SUM: " << maxSum(root);

    return 0;
}