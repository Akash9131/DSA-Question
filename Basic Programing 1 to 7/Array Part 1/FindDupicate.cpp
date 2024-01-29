// Find duplicate in array in arr of n+1 integer
#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n) {
    int sum1 = 0;

    for(int i=0; i<n; i++) {
       sum1 = sum1 + arr[i];
    }

    int sum2 = (n-1)* n/2;
    int ans =  sum1-sum2;
    return  ans;
  
}
int main()
{
    int arr[] = {1,2,3,3,4};
    int arr1[] = {1,2,3,4,4,5,6,7};
    int arr2[] = {1,2,3,4,5,6,7,8,9,9,10,11,12,13,14,15};
    cout<<"Find duplicate in array :  "<<findDuplicate(arr,5) <<endl;
     cout<<"Find duplicate in array :  "<<findDuplicate(arr2,16);
}