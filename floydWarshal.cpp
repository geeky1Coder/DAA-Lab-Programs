#include <bits/stdc++.h>
using namespace std;
int V = 4;

void floydWarshal(vector<vector<int>> graph)
{
    vector<vector<int>> dist(V, vector<int>(V, 0));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && (dist[i][j] > (dist[i][k] + dist[k][j])))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (auto el : dist)
    {
        for (auto c : el)
        {   
            if(c==INT_MAX){
                cout << -1 << "    ";
            }   
            else{
                cout << c << "    ";
            }
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 5, INT_MAX, 10},
                                 {INT_MAX, 0, 3, INT_MAX},
                                 {INT_MAX, INT_MAX, 0, 1},
                                 {INT_MAX, INT_MAX, INT_MAX, 0}};
    floydWarshal(graph);
    return 0;
}