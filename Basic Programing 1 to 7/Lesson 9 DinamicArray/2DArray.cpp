#include<iostream>
using namespace std;
int main()
{
    //creation
    int arr1[3][2];
    // initialise with zero
    int arr[3][3] = {0};
    // initialise with one first element 
    int arr2[3][3] ={1};
    // initialize with 2d array like 1D array
    int arr3[3][3] ={1,2,3,4,5,6,7,8,9};
     //initalise with 2d array in row/col wise
    int arr4[3][2] ={{1,2},{3,4},{5,6}};

     int arr5[3][2] ={{2},{3,},{5,6}};
     // give garbage value in arr5
    int row = 3;
    int col = 2;
    



    //input
/*
for(int i = 0; i<row;i++)
  {
      for(int j=0; j<col;j++ )
      {
          cin>>arr1[i][j];
      }
      cout<< endl;
  }
  */
  


    // print entire array
  for(int i = 0; i<row;i++)
  {
      for(int j=0; j<col;j++ )
      {
          cout<<arr4[i][j]<<" ";
      }
      cout<< endl;
  }





    cout<<" Sab shai chal rha hai"<<endl;

}