#include<iostream>
using namespace std;


// max heapify
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2* i ;
    int right = 2* i + 1;

    if(left <= n && arr[left]  > arr[largest]) {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]) {
        largest = right;

    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);

    }
}

// build max heap
void buildMaxHeap(int arr[], int n) {
    for( int  i = n/2 - 1; i>= 0; i--) {
        heapify(arr,n,i);
    }
}

// merge heap
void mergeHeap(int merged[],int arr1[], int arr2[],int n, int m) {
    
    // copy arr1 
    for(int i = 0; i<=n ; i++) {
        merged[i] = arr1[i];
    }
    // copy arr2
    for(int i = 0; i<=m; i++) {
        merged[n + i] = arr2[i];
    }

    // build heap for modified arr
    buildMaxHeap(merged,m+n);
}

int main()
{
     int  arr1[] = {10,5,6,2};
     int arr2[]  = {12,7,9};

     int n = 4;
     int m = 3;
    
    int merged[m+n];
    mergeHeap(merged,arr1,arr2,n,m);

cout<<"printing merged array "<<endl;
    for(int i = 0; i< n+m; i++) {
        cout<<merged[i]<<" ";
    }
 
 }
