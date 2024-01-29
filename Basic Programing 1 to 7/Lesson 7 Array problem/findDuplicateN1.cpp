// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 

 //TC -O(N)
 69 SC- O(1)
// Function to find the duplicate
// number using counting sort method
int findDuplicate(int arr[], int n)
{
    int countArr[n + 1], i;
 
    // Initialize all the elements
    // of the countArr to 0
    for (i = 0; i <= n; i++)
        countArr[i] = 0;
 
    // Count the occurrences of each
    // element of the array
    for (i = 0; i <= n; i++)
        countArr[arr[i]]++;
 
    bool a = false;
 
    // Find the element with more
    // than one count
    for (i = 1; i <= n; i++) {
 
        if (countArr[i] > 1) {
            a = true;
            cout << i << ' ';
        }
    }
 
    // If unique elements are ther
    // print "-1"
    if (!a)
        cout << "-1";

        return 0;
}
 
// Driver Code
int main()
{
    // Given N
    int n = 4;
 
    // Given array arr[]
    int arr[] = { 1, 3, 4, 2, 2 };
 
    // Function Call
    findDuplicate(arr, n);
    return 0;
}