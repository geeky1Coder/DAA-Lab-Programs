#include <bits/stdc++.h>
using namespace std;
int V = 7;

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
        cout<<"BREAK HERE"<<endl;
    }

    // for (auto el : dist)
    // {
    //     for (auto c : el)
    //     {   
    //         if(c==INT_MAX){
    //             cout << -1 << "    ";
    //         }   
    //         else{
    //             cout << c << "    ";
    //         }
    //     }
    //     cout << endl;
    // }
}

int main()
{
    vector<vector<int>> graph = {
        {
            0,5,2,INT_MAX,INT_MAX,INT_MAX,INT_MAX
        },
        {
            5,0,2,4,18,INT_MAX,INT_MAX
        },
        {
            2,2,0,8,INT_MAX,19,INT_MAX

        },
        {
            INT_MAX,4,8,0,INT_MAX,INT_MAX,9
        },
        {
            INT_MAX,18,INT_MAX,INT_MAX,0,11,14
        },
        {
            INT_MAX,INT_MAX,19,INT_MAX,11,0,15,
        },
        {
            INT_MAX,INT_MAX,INT_MAX,9,14,15,0
        }
    };

    floydWarshal(graph);
    return 0;
}