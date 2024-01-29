#include<iostream>
using namespace std;
int main()
{
    int  i = 5;

    int & j = i;

    int &k = j;


    cout<<"i "<<i<<endl;
    i++;
    cout<<"j "<<j<<endl;
    j++;
    cout<<"k "<<k<<endl;
    


    //array
    int n ;
    cout<<"enter the value of n "<<endl;
    cin>> n;

    int *arr = new int[n];

   
   //input
    cout<<"enter the element of arr "<<endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


    // print arr
    cout<<"printing the array "<<endl;
    for(int i=0; i<n; i++){
        cout<< arr[i] <<" ";
    }

    delete []arr;
}