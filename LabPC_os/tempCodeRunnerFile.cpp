#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

const int MAXN = 1e5 + 5;         // maximum number of nodes
vector<pair<int, int>> adj[MAXN]; // adjacency list
bool visited[MAXN];               // to track visited nodes

int prim(int start)
{
    int cost = 0;
    visited[start] = true;

    for (int i = 1; i < MAXN; i++)
    {
        int u = -1;
        int min_weight = INT_MAX;

        for (int j = 1; j < MAXN; j++)
        {
            if (visited[j])
            {
                for (auto v : adj[j])
                {
                    if (!visited[v.first] && v.second < min_weight)
                    {
                        u = v.first;
                        min_weight = v.second;
                    }
                }
            }
        }

        if (u == -1)
            break;

        visited[u] = true;
        cost += min_weight;
    }

    return cost;
}

int main()
{
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int start;
    cin >> start;

    int ans = prim(start);

    cout << ans << endl;

    return 0;
}