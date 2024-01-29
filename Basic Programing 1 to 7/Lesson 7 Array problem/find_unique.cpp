// Find unique  array

//ip ->2 3 1 6 3 6 2
// op -> 1

#include<iostream>
using namespace std;

int find_Duplicate(int arr[], int n) {
      int ans = 0;
      for(int i = 0; i<n; i++) {
        ans = ans^arr[i];
      }
      return ans;
}


int main() {
    int arr1[] = { 2,3,1,6,3,6,2};
    int n = 7;

    cout<<"unique number is : "<<find_Duplicate(arr1,7);
}