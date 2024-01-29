#include<iostream>
#include<algorithm>
using namespace std;

void Sort0s1s2sArray(int arr[], int n) {
    int zerocount =0;
    int onecount = 0;
    int twocount = 0;

    for(int i = 0; i<n; i++) {
        if(arr[i] == 0)
         zerocount++;

         else if(arr[i] == 1)
         onecount++;

         else
         twocount++;
    }
    
    int i = 0;
         while(zerocount != 0){
            arr[i] = 0;
            i++;
            zerocount--;
         }

         while(onecount !=0){
            arr[i] = 1;
            i++;
            onecount--;
         }
         while(twocount !=0) {
            arr[i] = 2;
            i++;
            twocount--;
         }
    

}

int main() {
    int arr[7] ={1,0,2,2,0,1,1};

     cout<<" sorted Os1s2s sorted array is : "<<endl;

     Sort0s1s2sArray(arr,7);
     //printing array
  for(int i= 0; i<7; i++) {
      cout<<arr[i]<<" ";
  }
}