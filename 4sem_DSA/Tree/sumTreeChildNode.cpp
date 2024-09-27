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

pair<int, bool> solve(node *root)
{
    if (root == NULL)
    {
        pair<int, bool> p = make_pair(0, true);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<int, bool> p = make_pair(root->data, true);
        return p;
    }

    pair<int, bool> left = solve(root->left);
    pair<int, bool> right = solve(root->right);

    int checkSum = left.first + right.first == root->data;

    pair<int, bool> ans;
    ans.first = root->data;

    ans.second = (checkSum && left.second && right.second);
    return ans;
}

bool sumTree(node *root)
{
    if (root == NULL)
        return true;

    return solve(root).second;
}

/*
 ->For it is true for this tree

 !                                         30
 !                                         /\
 !                                        /  \
 !                                      17    13
 !                                      /\    /\
 !                                     /  \  /  \
 !                                    7  10 9  4
 !                                       /
 !                                      /
 !                                     10

*/

int main()
{
    node *root = NULL;
    buildTree(root);
    print(root);

    cout << "ANSWER: " << sumTree(root);

    return 0;
}