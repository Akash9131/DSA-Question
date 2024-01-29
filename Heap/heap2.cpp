#include<iostream>
#include<queue>
using namespace std;
int getKthLargestElement(int arr[], int n,int k) {
    priority_queue<int,vector<int>,greater<int>> minHeap;

    // process first Kth element;
    for(int i = 0; i<k ; i++){
        minHeap.push(arr[i]);
    }
    //processes reamining element 
    for(int i = k; i<n; i++) {
        if(arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}
int getKthMinimumElement(int arr[], int n,int k) {
    priority_queue<int> maxHeap;

    // process first Kth element;
    for(int i = 0; i<k ; i++){
        maxHeap.push(arr[i]);
    }
    //processes reamining element 
    for(int i = k; i<n; i++) {
        if(arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    return maxHeap.top();
}
int getMinCostRopes(int arr[], int n) {
    // inisalize cost with zero
    int cost = 0;

     // create minHeap
    priority_queue<int,vector<int>,greater<int>>minHeap;

     // inser all element in minHeap
    for(int i = 0; i< n; i++) {
        minHeap.push(arr[i]);
    }

    while(minHeap.size() > 1) {
        //feact 2 min element and put their sum in cost
        // and put element back in min heap
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();


        int sum = first + second;
        cost += sum;
        minHeap.push(sum);

    }
    return cost;
}
int main()

{
    /*

    // max heap
     priority_queue<int>maxHeap;

     //insert
     maxHeap.push(1);
     maxHeap.push(2);
     maxHeap.push(5);
     maxHeap.push(5);
     maxHeap.push(3);


     //top element for the root element
     cout<< maxHeap.top()<<endl;
     maxHeap.pop();
     cout<< maxHeap.size() <<endl;

     if(maxHeap.empty()){
        cout <<"heap is  empty "<<endl;
     }
     else{
        cout<<" heap is not empty "<<endl;
     }



     // min heap
     priority_queue<int,vector<int>,greater<int> >minHeap;
     
//insert
     minHeap.push(1);
     minHeap.push(2);
     minHeap.push(5);
     minHeap.push(5);
     minHeap.push(3);


     //top element for the root element
     cout<< minHeap.top()<<endl;
     minHeap.pop();
     cout<< minHeap.size() <<endl;

     if(minHeap.empty()){
        cout <<"heap is  empty "<<endl;
     }
     else{
        cout<<" heap is not empty "<<endl;
     }

     */

    int arr[] = {3,2,5,1,6,8,7,9};
    int n = 8;
    int k = 3;

    int arr1[] = {4,3,2,6};
    

    cout<<"Kth largest element is  : "<<getKthLargestElement(arr,8,3)<<endl;
    cout<<"Kth Minimum element is : " <<getKthMinimumElement(arr,8,3)<<endl;
    cout<<"Minimum cost of ropes is : " <<getMinCostRopes(arr1,4)<<endl;

}