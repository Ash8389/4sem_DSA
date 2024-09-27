#include <iostream>
#include <queue>
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

void levelOrderInsertion(Node *&root)
{
    int data;

    cout << "Enter data for root: ";
    cin >> data;

    if (data == -1)
        return;

    root = new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << ": ";
        cin >> data;

        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << " :";
        cin >> data;

        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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

bool sameLevelLeaf(Node *root, int level, int &leafLvl)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
    {
        if (leafLvl == 0)
        {
            leafLvl = level;
            return true;
        }
        if (leafLvl != level)
            return false;

        return true;
    }

    return sameLevelLeaf(root->left, level + 1, leafLvl) && sameLevelLeaf(root->right, level + 1, leafLvl);
}

int main()
{
    Node *root = NULL;

    levelOrderInsertion(root);
    cout << "LEVEL ORDER TRAVERSAL" << endl;
    levelOrderTraversal(root);

    int leaflvl, lvl;
    leaflvl = lvl = 0;

    bool check = sameLevelLeaf(root, lvl, leaflvl);

    cout << "CHECK-->" << check << endl;

    return 0;
}