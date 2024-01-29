#include<iostream>
using namespace std;
void merge(int arr[], int start, int end){

    int mid = start + (end - start)/2;

    int leftLength = mid - start + 1;
    int rightLength = end - mid;
    
    //create left and right part
    int *left = new int[leftLength];
    int *right = new int[rightLength];


  // copy into left array
    int orignalIndex = start;
    for(int i=0; i<leftLength; i++){
         left[i] = arr[orignalIndex++];
    }

    // copy int right array
      orignalIndex =  mid + 1;
    for(int i=0; i<rightLength; i++){
         right[i] = arr[orignalIndex++];
    }

    // now we have 2 sorted array
    // we have to merge them

    int leftIndex = 0;
    int rightIndex = 0;
    orignalIndex = start;


  // compare element from left and right array and copy into orignal array
    while(leftIndex < leftLength  &&  rightIndex < rightLength){
        if(left[leftIndex] <= right[rightIndex]) {
            arr[orignalIndex++] = left[leftIndex++];
        }
        else{
            arr[orignalIndex++] = right[rightIndex++];
        }
    }

   // check if any more element present in left array, then copy it
    while(leftIndex <leftLength){
         arr[orignalIndex++] = left[leftIndex++];
    }
     // check if any more element present in right array, then copy it
    while(rightIndex < rightLength){
            arr[orignalIndex++] = right[rightIndex++];
    }

    delete []left;
    delete [] right;
}
void mergeSort(int arr[],int start, int end){
    // base case
    if(start >= end){
           return;
    }

    int mid = start + (end - start)/2;

    //left part
    mergeSort(arr,start,mid);


    //right part
    mergeSort(arr,mid+1,end);


    // merge two sorted parts
    merge(arr,start,end);
}
int main()
{
    int arr[] ={12,11,13,5,6,7};
    int size = 6;

    mergeSort(arr,0, size-1);

    for(int i=0; i< size; i++){
        cout<<arr[i]<<" ";
    }
}