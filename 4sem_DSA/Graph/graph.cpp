#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void buildGraph(int src, int des, bool directed)
    {
        adj[src].push_back(des);

        if (directed)
            adj[des].push_back(src);
    }

    void print()
    {
        cout << "*** SOURCE_NODE -> DESTINATION_NODE ***" << endl;
        for (auto it : adj)
        {
            cout << it.first << " -> ";

            for (auto itt : it.second)
            {
                cout << itt << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int node, edge;
    cout << "Enter the no. of node: ";
    cin >> node;
    cout << "Enter the no. of edge: ";
    cin >> edge;

    graph g;

    for (int i = 0; i < edge; i++)
    {
        int src, des;

        cin >> src >> des;

        //! Directed -> 1
        //! Undirected -> 0

        g.buildGraph(src, des, true);
    }
    g.print();

    return 0;
}

int minDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0; // Empty tree has depth 0
    }

    int minLeft = minDepth(root->left);

    int minRight = minDepth(root->right);

    // Consider only the minimum depth from either subtree (or 1 if only one child)
    return 1 + std::min(minLeft, minRight);
}