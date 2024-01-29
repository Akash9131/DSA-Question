#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target){
    
    for(int i = 0; i<size; i++){
       if(arr[i]== target){
           return true;
       }
    }
     return  false;
}

void printArray(int arr[], int size){

     for(int i = 0; i<size; i++){
         cout<<arr[i]<<" ";
     }
}

int main()
{
    int arr[100];
    int n;
    cout<< " enter the  size of array "<<endl;
    cin>> n;
     // insert the element in array
     cout<<"Enter the element of array "<<endl;
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }

    cout << " Printing the array "<<endl;
    printArray(arr,5);
    cout<<endl;


    if(arr,5,7){
        cout<<" Elemint in exist in array "<<endl;
    }
    else{
        cout<<"Element is not exist in array"<<endl;
    }


}