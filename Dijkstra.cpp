#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> dist, int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
void addEdge(vector<vector<pair<int, int>>> &adj, int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void dijkstra(vector<vector<pair<int, int>>> adj, int src, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> q;
    q.push(make_pair(0, src));
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = it->first;
            int w = it->second;
            if (dist[u] != INT_MAX && dist[v] > (dist[u] + w)) {
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v], v));
            }
        }
    }
    printArr(dist, n);
}
void solve() {
    int n = 9;
    vector<vector<pair<int, int>>> adj(n);
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    dijkstra(adj, 0, n);
}
int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}