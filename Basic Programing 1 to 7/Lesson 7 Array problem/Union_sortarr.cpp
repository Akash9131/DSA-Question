// insertion in sorted array
// i/p   arr1[]= {1,3,4,5,7}
        //arr2[] = {2,3,5,6}

//o/p    union = {1,2,3,4,5,6,7};



#include<bits/stdc++.h>
using namespace std;

//TC- O(n+m)  Sc - O(1) but fail in duplicate element in array
void UnionSortedArr(int arr1[],int arr2[], int n, int m){
    int i =0;
    int j = 0;

    while(i<n && j<m) {
        if(arr1[i] == arr2[j]){
            cout<< arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
        }
        else{
            cout<<arr2[j]<<" ";
            j++;
        }
    }

    while(i<n)
    cout<<arr1[i++]<<" ";
    while(j<m)
    cout<<arr2[j++]<<" ";
}


 
 // OPTIMIZE SOLUTION   WITH OUT USING EXTRA SPACE
 // TC - O(M+N)  SC-O(1)
/* Helper function for printUnion().
   This same function can also be implemented as a lambda function inside printUnion().
*/
void next_distinct(const vector<int> &arr, int &x) // Moving to next distinct element
{
  // vector CAN be passed by reference to avoid unnecessary copies.
  // x(index) MUST be passed by reference so to reflect the change in the original index parameter
   
  /* Checks whether the previous element is equal to the current element,
       if true move to the element at the next index else return with the current index
  */
    do
    {
        ++x;
    } while (x < arr.size() && arr[x - 1] == arr[x]);
}
 
void printUnion(vector<int> arr1, vector<int> arr2)
{
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            next_distinct(arr1, i); // Incrementing i to next distinct element
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j] << " ";
            next_distinct(arr2, j); // Incrementing j to next distinct element
        }
        else
        {
            cout << arr1[i] << " ";
            // OR cout << arr2[j] << " ";
            next_distinct(arr1, i); // Incrementing i to next distinct element
            next_distinct(arr2, j); // Incrementing j to next distinct element
        }
    }
    // Remaining elements of the larger array
    while (i < arr1.size())
    {
        cout << arr1[i] << " ";
        next_distinct(arr1, i); // Incrementing i to next distinct element
    }
    while (j < arr2.size())
    {
        cout << arr2[j] << " ";
        next_distinct(arr2, j); // Incrementing j to next distinct element
    }
}



int main() {
    int arr1[]= {1,2,3,4,5,7};
    int arr2[] = {2,3,5,6};
    int n= 6;
    int m = 4;

     UnionSortedArr(arr1,arr2,n,m);




   cout<<endl;
   cout<<endl;
   cout<<endl;

     vector<int> arr8 = {1, 2, 2, 2, 3};    // Duplicates Present
    vector<int> arr9 = {2, 3, 3, 4, 5, 5}; // Duplicates Present
 
    printUnion(arr8, arr9);

  
    
}