#include <iostream>
#include <vector>
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
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
        return;
    root = new node(data);

    cout << "Enter data to insert left of " << data << endl;
    buildTree(root->left);
    cout << "Enter data to insert right of " << data << endl;
    buildTree(root->right);
}

void traverseInorder(node *root)
{
    if (root == NULL)
        return;
    traverseInorder(root->left);
    cout << root->data << " ";
    traverseInorder(root->right);
}
vector<int> zig_zag(node *root)
{
    queue<node *> q;
    q.push(root);

    vector<int> ans;
    bool LtoR = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> res(size);

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();

            if (LtoR)
                res[i] = temp->data;
            else
                res[size - i - 1] = temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        LtoR = !LtoR;
        for (auto val : res)
        {
            ans.push_back(val);
        }
    }
    return ans;
}
int main()
{
    node *root = NULL;
    buildTree(root);
    cout << endl
         << " Inorder Traverse: ";
    traverseInorder(root);

    cout << endl
         << " Zig Zag Traverse: ";
    vector<int> ans = zig_zag(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}