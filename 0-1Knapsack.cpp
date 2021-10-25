#include <iostream>
using namespace std;

int main()
{   int n;
    cout <<"enter number of items:";
    cin>>n;
    int wt[n];
    int pf[n];
    int w,i,j;
    cout<<"enter capacity of knapsack:";
    cin>>w;
     for(i=0;i<n;i++){
        cout<<"enter weight of item "<<i+1<<": ";
        cin>>wt[i];
        cout<<"enter value of item "<<i+1<<": ";
        cin>>pf[i];
     }

     int t[n+1][w+1];
     for(i=0;i<n+1;i++){
        for(j=0;j<w+1;j++){

            if(i==0||j==0)
                t[i][j]=0;
            else if(wt[i-1]<=j)
                t[i][j]=max(pf[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
     }
     cout<<"maximum profit:"<<t[n][w];
    return 0;
}
