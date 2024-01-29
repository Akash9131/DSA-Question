#include<iostream>
using namespace std;
int optimalStatargy(int arr[], int i, int j){

    //base case
    if( i > j)
    return 0;

    int choice1 = arr[i]+ min(optimalStatargy(arr, i+2,j), optimalStatargy(arr,i+1,j-1));
     int choice2 = arr[j]+ min(optimalStatargy(arr, i+1,j-1), optimalStatargy(arr,i,j-2));

     int ans= max(choice1,choice2);

     return ans;
}

int main()
{
    int arr[]= {20,30,2,2,2,10};
    int i = 0;
    int j = 5;

    cout<<"winner is in optimal stratergy "<<optimalStatargy(arr, i, j)<<endl;

}