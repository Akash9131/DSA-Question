#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int n, int target) {
    for(int i =0; i<n; i++) {
        if(arr[i] == target) {
            return true;
        }
    }
    return false;
}
int main() {
    int arry[20];

    int arr[7]  = {3,6,7,12,2,4,6};
    //int target = 14;
    int target = 6;
    cout <<"Array element are present or not  :"<<LinearSearch(arr,7,target);
}