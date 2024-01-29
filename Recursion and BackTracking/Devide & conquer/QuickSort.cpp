#include<iostream>
using namespace std;

int partition(int arr[], int start , int end){

    //taking first element  as a pivot
    int pivot = arr[start];
    
    //count smaller elements
      int count = 0;
    for(int i = start + 1; i<= end; i++){
        if(arr[i] <= pivot)
        count++;
    }


    //find right place for pivot
    int pivotIndex = start + count;


    //swap
    swap(arr[pivotIndex],arr[start]);

    // handle left and right
    //we want all lesser element on left side  of pivotElement
    //we want all gretter element on right side of pivotElement

    int i = start;
    int j = end;

    while( i<pivotIndex  && j > pivotIndex){
        // already small element in left side
        while(arr[i] <= pivot){
             i++;
        }

        // already greter element   in right side
        while(arr[j] >= pivot){
             j--;
        }


        if(i<pivotIndex  && j > pivotIndex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
   return pivotIndex;
}

void quickSort(int arr[], int start, int end){

    //base caase
    if(start >= end)
    return;

    int pIndex = partition(arr,start,end);


    //left
    quickSort(arr, start, pIndex-1);

    //right
    quickSort(arr,pIndex + 1, end);
}
int main()
{
    int arr[] ={12,11,13,5,6,7};
    int size = 6;

    quickSort(arr,0, size-1);

    for(int i=0; i< size; i++){
        cout<<arr[i]<<" ";
    }
}