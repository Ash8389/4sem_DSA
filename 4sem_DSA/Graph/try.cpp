#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adjlist;

    void buildGraph(int src, int des, bool directed)
    {
        adjlist[src].push_back(des);

        if (directed)
            adjlist[des].push_back(src);
    }

    void print()
    {
        cout << "*****Print*****" << endl;
        for (auto a : adjlist)
        {
            cout << a.first << " -> ";
            for (auto b : a.second)
                cout << b << " | ";
            cout << endl;
        }
    }

    void dfs(bool visited[], vector<int> &ans, int node)
    {
        stack<int> s;
        s.push(node);
        visited[node] = true;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            ans.push_back(top);

            for (auto it : adjlist[top])
            {
                if (visited[it] != true)
                {
                    s.push(it);
                    visited[it] = true;
                }
            }
        }
    }
};

int main()
{
    int n, e;

    cout << "Enter no. of nodes: ";
    cin >> n;
    cout << "Enter no. of edges: ";
    cin >> e;

    graph g;

    for (int i = 0; i < e; i++)
    {
        int src, des;
        cin >> src >> des;

        g.buildGraph(src, des, 0);
    }
    g.print();

    bool visited[n] = {0};
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] != true)
            g.dfs(visited, ans, i);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}