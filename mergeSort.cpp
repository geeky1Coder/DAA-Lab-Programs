#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int start,int mid, int end) {
    int left = mid - start + 1;
    int right = end - mid;
    int l[left],r[right];

    for(int i=0;i<left;i++) {
        l[i] = a[start+i];
    }

    for(int i=0;i<right;i++) {
        r[i] = a[mid+i+1];
    }

    int i=0,j=0,k=start;
    while(i<left && j<right) {
        if(l[i]<=r[j]) {
            a[k] = l[i];
            i++;
        }
        else {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while(i<left) {
        a[k++] = l[i++];
    }

    while(j<right) {
        a[k++] = r[j++];
    }
}

void mergeSort(int a[],int start, int end) {
    if (start<end) {
        int mid = start + (end-start)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}

int main() {
    int  n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    srand(time(0));
    // cout<<"r"<<RAND_MAX<<"\n";
    cout<<"\nEnter array : ";
    for(int i=0;i<n;i++)
        arr[i] = rand() % 10000;

    // measure time
    // time taken by the processor to sort the elements ?
    // (excluding display time)
    clock_t start_time = clock();
    cout<<"\nStart time = "<<start_time<<"\n";
    mergeSort(arr,0,n-1);
    clock_t end_time = clock();
    cout<<"\nEnd time = "<<end_time<<"\n";

    cout<<"\n\nSorted array : \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    // end - start / clocks per sec
    cout<<"\n\nTotal execution time = "<<float(end_time - start_time)/CLOCKS_PER_SEC<<"\n";

    return 0;
}