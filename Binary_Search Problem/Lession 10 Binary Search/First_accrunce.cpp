#include<iostream>
using namespace std;
int  findFirst_occurence(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int ans = -1;


    while(start<=end)
    {
        if(arr[mid] == target)
        {
            ans= mid;
            end = mid -1;
        }
        else if(target < arr[mid])
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }

        mid = start+(end-start)/2;
    }
    return ans;
}

int  findLast_occurence(int arr[], int n, int target)

    {
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;
    int ans = -1;


    while(start<=end)
    {
        if(arr[mid] == target)
        {
            ans = mid;
            start = end+1;
        }
        else if(target < arr[mid])
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }

        mid = start+(end-start)/2;
    }
    return ans;
}


int main()
{
    int arr[] = {3,4,5,5,5,5,8,12};
    int n = 8;
    int target = 5;

     int ans1 =findFirst_occurence(arr,8,5);
     int ans2 = findLast_occurence(arr,8,5);

     cout<<"first occrence is "<<ans1<<endl;
     cout<<"Last occrence is "<<ans2<<endl;

}