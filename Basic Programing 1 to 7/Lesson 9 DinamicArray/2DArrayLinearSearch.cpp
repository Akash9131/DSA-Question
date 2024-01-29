#include<iostream>
using namespace std;

bool Linearsearch(int arr[][3], int row , int col, int target)
{
    for(int i = 0; i<row; i++)
    {
      for(int j =0; j<col; j++)
      {
          if(arr[i][j] == target)
          {
             return true;
          }
      }
    }
    return false;
}

int main()
{
    int arr[3][3]={5,1,3,10,12,15,13,24,14};

    cout<<"searching 13 "<<Linearsearch(arr,3,3,13)<<endl;
    cout<<"searching 25 "<<Linearsearch(arr,3,3,25)<<endl;

    
}