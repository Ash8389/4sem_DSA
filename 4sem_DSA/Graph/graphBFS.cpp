#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class graph
{
    // unordered_map<int, list<int>> nodes;
    map<int, list<int>> nodes;

public:
    void adj(int s, int d, bool directed)
    {
        nodes[s].push_back(d);

        if (directed)
            nodes[d].push_back(s);
    }

    void print()
    {
        for (auto it : nodes)
        {
            cout << it.first << "-->";
            for (auto sec : it.second)
                cout << sec << " ";
            cout << endl;
        }
    }

    void BFS(bool visited[], int &node, vector<int> &ans)
    {
        queue<int> q;

        q.push(node);
        visited[node] = 1;

        while (!q.empty())
        {
            int firstNode = q.front();
            q.pop();

            ans.push_back(firstNode);

            for (auto it : nodes[firstNode])
            {
                if (!visited[it])
                {
                    q.push(it);
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
            g.BFS(visited, i, ans);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}