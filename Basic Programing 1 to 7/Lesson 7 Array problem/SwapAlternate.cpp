#include<iostream>
using namespace std;

void swapArray(int arr[], int n)
{
    int i = 0;
    while(i<=n)
    {
        if(i+1<n)
        {
            swap(arr[i],arr[i+1]);
        }
        i = i+2;
    }
}
int main()
{
    int arr[] ={2,7,5,6,9,8};

    swapArray(arr,6);

    for(int i = 0; i<6; i++)
    {
        cout<<arr[i]<<" ";
    }

}