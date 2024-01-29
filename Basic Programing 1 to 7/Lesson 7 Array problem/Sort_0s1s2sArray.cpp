//sort an array of 0s 1s 2s
// ip =  1 0 2 2 0 1 1
// op =  0 0 1 1 1 2 2

#include<iostream>
#include<algorithm>
using namespace std;

void Sort_0s1s2s(int arr[], int n) {
   
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    for(int i = 0 ; i<n; i++) {
        if(arr[i] == 0){
            zeroCount++;
        }
        else if( arr[i] == 1){
            oneCount++;
        }
        else{
            twoCount++;
        }
    }

    int i = 0;
    
    while(zeroCount != 0){
        arr[i] = 0;
        i++;
        zeroCount--;
    }

    while(oneCount != 0){
        arr[i] = 1;
        i++;
        oneCount--;
    }
     while(twoCount != 0){
        arr[i] = 2;
        i++;
        twoCount--;
    }

   
}



void printArray(int arr[], int n){
    for(int i=0; i<n; i++) {
        cout<<arr[i] <<" ";
    }
    cout <<endl;
}

int main() {
    int arr[] = {1,0,2,2,0,1,1};
    int n = 7;


    Sort_0s1s2s(arr,n);
    cout<<"printing array "<<endl;
      printArray(arr,7);

  
}
   
