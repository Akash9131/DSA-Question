#include<iostream>
using namespace std;

int binarySearch(int arr[],int start,int end, int target) {
    int mid = start + (end - start)/2;

    while(start <= end){
        if(arr[mid] == target)
        return mid;

        if(arr[mid] < target)
         start = mid+1;

         else
         end = mid - 1;

         mid = start + (end - start)/2;

    }
    return -1;
}
// we dont Know the size of array,
//consedering it infinete position as per question
//assuption array size is infinite, so no index of bound is exist

int findPosition(int arr[],  int target){
    int start = 0;
    int end  = 1;
    int val = arr[start];

    while(val <target){
        start = end;
        end = 2 *end;
        val =  arr[end]; 
    }
     return binarySearch(arr,start,end,target);
}
int main()
{
    int arr[] = {3,13,17,21,25,62,93,100,122,133,149};

   

   int ans = findPosition(arr,25);
   int ans1 = findPosition(arr,35);

    cout<<"Search in Uknow size of array   "<< ans<<endl;
       cout<<"Search in Uknow size of array   "<< ans1<<endl;
}