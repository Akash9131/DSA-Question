#include<iostream>
using namespace std;

void ReverseArray(int arr[],int n) {
       int i = 0;
       int j = n-1;

       while(i<=j)
        {
        swap(arr[i],arr[j]);
        i++;
        j--;
       }
}

int main () {
   
    int arr[6] = {3,5,2,7,6,9};


    
     ReverseArray(arr,6);

    // printing array
    cout<<"reversing array are: "<<endl;
    for(int i =0; i<6; i++) {
        cout<<arr[i]<<" ";
    }

    

}