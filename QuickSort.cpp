#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) 
{ 
    int t = a; 
    a = b; 
    b = t; 
} 
int partition(vector<int> &arr,int l,int r){
    int pivot=arr[r];
    int idx=l-1;

    for(int i=l;i<r;++i){
        if(arr[i]<pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    swap(arr[idx + 1], arr[r]);
    return (idx+1);
}   
void quicksort(vector<int> &arr,int l,int r){
    if(l>=r){
        return;
    }
    int x=partition(arr,l,r);
    quicksort(arr,l,x-1);
    quicksort(arr,x+1,r);
}
int main(){
    srand(time(0));
    vector<int> arr;
    for(int i=0;i<10000;++i){
        arr.push_back(rand());
    }
     
    cout<<endl;
    
    clock_t time_req;
    time_req=clock();
    quicksort(arr,0,arr.size()-1);
    time_req = clock()- time_req;

    cout << "Processor time taken: "
        << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
   
   
    return 0;
}