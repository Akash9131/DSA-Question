#include<iostream>
#include<algorithm>
using namespace std;


int  binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = start+(end-start)/2;


    while(start <= end)
    {
        int midElement = arr[mid];

        //element found
        if(midElement == target)
        {
            return mid;
        }
        //check the left part and neglate right part
        else if(target < midElement)
        {
            end = mid-1;
        }
        //check the right part and neglated the left part 
        else{
            start = mid+1;
        }

        mid = start+(end-start)/2;
    }
    return -1;
}
int main()
{
    int arr[] = {3,7,12,13,17,21};
    int n = 6;
    int target = 12;
     

    // if(binarySearch(arr,6,21) == true)
    // {
    //     cout<<"Target is preasent in array "<<endl;
    // }
    // else{
    //     cout<<"Target is not found in array "<<endl;
    // }

  cout<<"INDEX OF TARGET IS :->   "<<binarySearch(arr,6,13)<<endl;;

//   element is not found
  cout<<"INDEX OF TARGET IS  :->  "<<binarySearch(arr,6,121)<<endl;


//predefined function

  cout<<"predefined function  ->"<< binary_search(arr,arr + n,target)<<endl;

 
   
}