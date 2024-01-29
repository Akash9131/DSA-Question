// intersaction int two sorted array 
// insertion  in two sorte array

#include<iostream>
using namespace std;

//TC- O(M+N) SC- O(1) but not handale repeated element
void  Intercation_array(int arr1[], int arr2[], int n , int m) {
     int  i= 0;
     int j = 0;

     while(i<n && j < m) {
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i]> arr2[j]){
         j++;
        }
         else{
            //arr1[i] == arr2[j];
            cout<<arr2[j]<<" ";
            i++;
            j++;
         }
     }
}

 //TC - O(M+N) SC-O(N)   BUT HANDLE DUPLECATIONELEMENT 
/* Function prints Intersection of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
void printIntersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (i > 0 && arr1[i] == arr1[i - 1]) {        //For Handling duplicates
            i++;
            continue;
        }
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}

int main() {

    int arr1[] = { 1, 2, 5, 12, 10 };
    int arr2[] = { 1, 3, 5, 6, 12, 8 };
    int n = 6;
    int m = 6;
    
    //op  1 5 12
    Intercation_array(arr1,arr2,6,6);

cout <<endl;
cout <<endl;
cout <<endl;
cout <<endl;

     int arr3[] = { 1, 2, 2, 3, 4 };
    int arr4[] = { 2, 2, 4, 6, 7, 8 };
 
    int m1 = 5;
    int n2 =  6;
 
    // Function calling
    printIntersection(arr3, arr4, m1, n2);
    // op  2 4
}