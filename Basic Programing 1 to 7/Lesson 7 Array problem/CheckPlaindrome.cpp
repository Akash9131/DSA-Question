// check plaindrome in array
// ip    1 2 3 4 5 6 6 5 4 3 2 1
// op    true

// ip    1 2 2 4 5 6 6 5 4 4 2 1
// op    false


#include<iostream>
using namespace std;

bool checkPalindrome(int arr[], int n) {
    int i =0;
    int j = n-1; 

    while(i<j){
        if(arr[i] != arr[j])
        return false;
        i++; j--;
    }
    return true;
}

int main() {
    int arr1[] = {1,2,3,4,5,5,4,3,2,1};
    int n = 10;
    int arr2[] ={1,2,3,4,4,4,2,1};
    int m = 8;

    cout <<"ans is  "<<checkPalindrome(arr1,10)<<endl;;
    cout << "ans is "<<checkPalindrome(arr2,8);

}