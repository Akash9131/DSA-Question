#include<iostream>
using namespace std;

// Larget sum Contigues subArray 
//Kedene array
int getLargestSubarray(int arr[], int n) {
   int  maxi = INT_MIN;
   int  sum = 0;

   for(int i=0; i<n; i++) {
    // include current element
     sum =  sum+ arr[i];
     
     // update maxi
     maxi = max(sum, maxi);
     //if sum is less than zero so  do sum remain 0
     if(sum < 0)
     sum = 0;
   }
   return maxi;
}
int main() {
    int  arr[] = {-2,-3,4,-1,-2,1,5,-3};
    cout<<"maximum sum contineus subarray :  "<<getLargestSubarray(arr,8)<<endl;

}