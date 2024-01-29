#include<iostream>
using namespace std;

void printArray(int arr[], int size){

     for(int i = 0; i<size; i++){
         cout<<arr[i]<<" ";
     }
}
int main()
{
    //int arr[10];

    int arr1[5]= {1,4,5,6,7};

    //int arr2[] = {1,2,3,4};

    //int arr3[15] = {1,4,5,7,8};

    printArray(arr1,5);
    cout<<endl;

    cout<<"Array size "<< sizeof(arr1)<<endl;;

    
}