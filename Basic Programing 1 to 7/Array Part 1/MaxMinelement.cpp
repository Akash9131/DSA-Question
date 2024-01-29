#include <iostream>
using namespace std;
//get maximum number in array
int getMaximumNumber(int arr[], int n) {
    int ans = INT_MIN;

    for(int i= 0; i<n; i++) {
        ans = max(ans, arr[i]);
    }
    return ans;
}

// get minimum number
int getMinimumNumber(int arr[], int n) {
    int ans = INT_MAX;

    for(int i= 0; i<n; i++) {
        ans = min(ans, arr[i]);
    }
    return ans;
}
int main(){
    int arr[6] = {2,12,7,18,17,16} ;
    cout<<"Maximum number is : " <<getMaximumNumber(arr,6)<<endl;
    cout<<"Minum number is  : "<<getMinimumNumber(arr,6);

}
