#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
 
void Union(vector<int> &parent, int x, int y)
{
    parent[x] = y;
}


int main(){
    int n=4;
    vector<vector<int>> adj; 
    adj.push_back({0,1,1});
    adj.push_back({1,3,3});
    adj.push_back({3,2,4});
    adj.push_back({2,0,2});
    adj.push_back({0,3,2});
    adj.push_back({1,2,2});

    sort(adj.begin(),adj.end(),[](vector<int> a,vector<int> b){
        return a[2]<b[2];
    });

    vector<int> parent(n,-1);
    
    int ans=0;
    vector<int> ansEdges;

    for(int i=0;i<adj.size();++i){
        int px=find(parent,adj[i][0]);
        int py=find(parent,adj[i][1]);

        if(px==py){
            //cycle found
        }
        else{
            ans+=adj[i][2];
            ansEdges.push_back(i);
            Union(parent,px,py);
        }
    }

    cout<<"Weight of MST : "<<ans<<endl;
    cout<<"Edges of MST : "<<endl;

    for(auto el:ansEdges){
        cout<<adj[el][0]<<" -- "<<adj[el][1]<<"   "<<adj[el][2]<<endl;
    }
}