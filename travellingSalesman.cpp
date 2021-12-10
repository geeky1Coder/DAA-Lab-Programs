#include <bits/stdc++.h>
using namespace std;
int n=4;
int allVisited=(1<<n)-1;
vector<vector<int>> graph={
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
vector<vector<int>> dp((1<<n),(vector<int> (n,-1)));
int tsp(int mask,int pos){
    if(mask==allVisited){
        return graph[pos][0];
    }
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    int ans=INT_MAX;
    for(int city=0;city<n;++city){
        if((mask&(1<<city))==0){
            int newAns=graph[pos][city]+tsp((mask|(1<<city)),city);
            ans=min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
int main(){
    cout<<tsp(1,0)<<endl;
    return 0;
}