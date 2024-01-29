//find pivot element is sorted rotated array
#include<iostream>
using namespace std;
int find_pivot(int arr[], int n){
    int start = 0;
    int end = n-1;

    while ((start<= end))
    {
        /* code */
        int mid = start + (end - start)/2;

        if( mid< end && arr[mid] > arr[mid + 1])//  also check mid
        return arr[mid] ;
        

        if( mid > 0 && arr[mid] < arr[mid-1]) //  also check mid in range
        return arr[mid - 1];
         


        if(arr[start] >= arr[mid])
         end = mid-1;

         else{
            start = mid+1;
         }
    }
    return -1;
    
}
int main(){

    int arr[]= {3,4,5,6,1,2};
    int n = 6;

    int arr1[]= {1,2,3,4,5,6};
    int n1 = 6;

    int ans = find_pivot(arr,6);

    cout<<"find pivot element is sorted rotated array "<<ans<<endl;


     int ans1 = find_pivot(arr1,n1);

    cout<<"find pivot element is sorted rotated array "<<ans1<<endl;
}
