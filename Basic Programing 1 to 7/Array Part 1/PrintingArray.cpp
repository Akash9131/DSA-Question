#include<iostream>
using namespace std;

int main() {
    // aarray creation
    int arrayData[20];
    
    //insert The array size
    int arraySize ;
    cout<<"Enter the size of  array : " <<endl;
    cin >> arraySize;
     // insert the array element
    cout<<"Enter your Array element : "<<endl;
    for(int index = 0; index< arraySize; index++) {
        cin >> arrayData[index] ;
    }



    // print the array
    cout<<"Printed array is : " <<endl;
    for(int index =0; index< arraySize; index++) {
        cout<< arrayData[index]<<" ";
    }





}
