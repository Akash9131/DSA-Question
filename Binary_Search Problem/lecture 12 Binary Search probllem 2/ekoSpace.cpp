#include<iostream>
#include<algorithm>
using namespace std;

bool isPossibleSolution(int mid, int arr[], int n, int target){

    int sum = 0;
       for(int i= 0; i<n; i++){
        int diff = 0;

        if(arr[i] > mid)
            diff = arr[i] - mid;

            sum = sum + diff;
        
       }

       if(sum >= target)
       return true;
       else
       return false;
}

int getMaxHeightofSaw(int arr[], int n , int target) {
    //asani se ending  nikalne ke liye 
    sort(arr,arr + n);

    int start = 0;
    int end = arr[n-1];
     int ans = -1;


    while(start <= end){
        int mid = start + (end - start)/2;

        if(isPossibleSolution(mid,arr,n,target)){
            // store ans
            ans = mid;
            // move to right
            start = mid +1;
        }
        else{
            // move to right
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[]={15,8,18,6};
    int target = 30;

   int ans = getMaxHeightofSaw(arr,4,target);

   cout<<" EKO SPACE MAXIMUM HEGIHT IS ->>> "<<ans<<endl;
   //return zero mendetoray
   return 0;
}