#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int arr[] = {4,9,5,13,131,2,1,};
    int n = 7;

//short pre defined function 
sort(arr,arr + n);

    for(int i=0; i<n; i++) {
        cout<<arr[i] <<" ";
    }
    cout <<endl;
    
}