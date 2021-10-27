#include <bits/stdc++.h>
using namespace std;

void primsAlog(vector<vector<int>> graph)
{
    int n = graph.size();

    vector<int> parent(n, -1);
    vector<int> values(n, INT_MAX);
    set<int> vis;

    values[0] = 0;
    vis.insert(0);
    int minEl = INT_MAX;
    int minIdx = 0;

    for (int t = 0; t < (n - 1); ++t)
    {
        int e=0;
        for(auto el:graph[minIdx]){
            if(el!=0&&(values[e]>(el))){
                parent[e]=minIdx;
                values[e]=el;
            }
            e++;
        }

        minEl=INT_MAX;
        minIdx=-1;
        int i = 0;
        for (auto el : values)
        {
            if ((vis.find(i)==vis.end())&&(el < minEl))
            {
                minIdx = i;
                minEl = el;
            }
            i++;
        }

        vis.insert(minEl);
    }

    int totalWeight=0;
   for (int i = 1; i < n; i++){
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
        totalWeight+=graph[i][parent[i]];
   }

   cout<<"Total weight : "<<totalWeight<<endl;
}

int main()
{
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};
    primsAlog(graph);
}