// reverse integer 
 //ip -> 3 5 2 7 6 9
// op -> 9 6 7 2 5 3

#include<iostream>
#include<algorithm>
using namespace std;

// void reverseArray(int arr[], int n){
//     int i= 0;
//     int j= n-1;
//     while(i<j) {
//         swap(arr[i],arr[j]);
//         i++;
//         j--;
//     }
// }


// user made swap  function
 void reverse( int arr[],int n){
    int i=0, j= n-1;
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void reverseArray(int arr[],int n){
    int i =0;
    int j=n-1;

    while(i<j){
        reverse(arr,n);
        i++;
        j--;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++) {
        cout<<arr[i] <<" ";
    }
    cout <<endl;
}


int main(){

    int arr[6] = {3,5,2,7,6,9};
    int n = 6;


      reverseArray(arr,6);
    cout<<"printing array "<<endl;
      printArray(arr,6);


}