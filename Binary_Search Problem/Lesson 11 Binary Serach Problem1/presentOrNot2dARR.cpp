#include<iostream>
using namespace std;


// for col
bool binarySearch(int arr[][3],int n, int m, int row, int target){
    int start = 0;
    int end = m-1;
    int mid = start + (end-start)/2;

    while(start <= end){
        if(arr[row][mid]  == target){
             cout<<row <<" "<<mid<<" "<<endl;
            return true;
        }
        if(arr[row][mid] < target){
                 start = mid+1;
        }
        else{
            end = mid-1;
        }
        int mid = start + (end-start)/2;
    }
    return false;
}


//for row search
bool SearchTarget(int arr[][3], int n, int m, int target){
    //find row
    int start = 0;
    int end = n-1;
    int mid =  start+(end- start)/2;

    while(start<= end){
        //first check starting element of row
        if(arr[mid][0]== target){
               cout<<mid <<" "<<0<<" "<<endl;
            return true;
        }
        //second check ending element of row
        if(arr[mid][m-1]== target){
            cout<<mid <<" "<<m-1<<" "<<endl;
            return true;
        }

        //check if  target is present bitween starting and ending element
        if(target >arr[mid][0] && target < arr[mid][m-1]){
            //apply binary search in col
            bool ans = binarySearch(arr,n,m,mid,target);
            return ans;
        }

        //check upper part
        if(target <arr[mid][0]){
            end = mid-1;
        }
         //check lower  part
        if(target > arr[mid][m-1]){
            start = mid+1;
        }

        mid = start+ (end-start)/2;
    }
    return false;

}


int main(){
    int arr[3][3]={1,5,9,14,20,21,30,34,43};
    int n =  3;
    int m = 3;
    int target = 34;

    cout<<SearchTarget(arr,n,m,target)<<endl;
    cout<<endl;

}