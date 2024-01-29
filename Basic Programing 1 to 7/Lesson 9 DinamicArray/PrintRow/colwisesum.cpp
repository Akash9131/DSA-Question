#include<iostream>
using namespace std;

void rowwiseSum(int arr[3][4], int row, int col)
{  
    // each col
    for(int i = 0; i<row; i++)
    {
       int  sum = 0;
        for(int j=0; j<col; j++)
        {
            sum = sum + arr[i][j]; 

        }
         cout<<sum<<" ";
    }
    cout<<endl;
}


void colwiseSum(int arr[3][4], int row, int col)
{  
    // each col
    for(int i = 0; i<col; i++)
    {
       int  sum = 0;
        for(int j=0; j<row; j++)
        {
            sum = sum + arr[j][i]; 

        }
         cout<<sum<<" ";
    }
    cout<<endl;
}


int main()
{
    int arr[3][4]={3,5,11,2,5,9,8,0,5,0,1,3};
    colwiseSum(arr,3,4);
    rowwiseSum(arr,3,4);
}