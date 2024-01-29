//Swap altarnate in array
//ip = 2 7 5 6 9 8
//op = 7 2 6 5 8 9

#include<iostream>
using namespace std;

void swapAltarnate(int arr[],int n) {
    int i = 0;
    
    while(i+1<n){
        swap(arr[i],arr[i+1]);
        i = i+2;
    }
}


void printArray(int arr[], int n){
    for(int i=0; i<n; i++) {
        cout<<arr[i] <<" ";
    }
    cout <<endl;
}
int main(){
    int arr[] ={2,7,5,6,9,8};
    int n = 6;


      swapAltarnate(arr,6);
     cout<<"printing array "<<endl;
      printArray(arr,6);
}