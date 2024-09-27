#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class graph
{
    unordered_map<int, list<int>> nodes;

public:
    void adj(int src, int des, bool directed)
    {
        nodes[src].push_back(des);

        if (directed)
            nodes[des].push_back(src);
    }

    void print()
    {
        for (auto it : nodes)
        {
            cout << it.first << "-->";
            for (auto in : it.second)
                cout << in << " ";
            cout << endl;
        }
    }

    void DFS(bool visited[], int node, vector<int> &ans)
    {
        stack<int> s;

        s.push(node);
        visited[node] = 1;

        while (!s.empty())
        {
            int upperNode = s.top();
            s.pop();

            ans.push_back(upperNode);

            for (auto it : nodes[upperNode])
            {
                if (!visited[it])
                {
                    s.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
};
int main()
{
    graph g;
    int node, edge;
    cout << "Enter the no. nodes: ";
    cin >> node;
    cout << "Enter the no. of edges: ";
    cin >> edge;

    int src, dest;
    cout << "Enter node and edges by giving space between them\n";
    for (int i = 0; i < edge; i++)
    {
        cin >> src >> dest;
        g.adj(src, dest, 0);
    }

    g.print();

    bool visited[node];
    vector<int> ans;
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
            g.DFS(visited, i, ans);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}