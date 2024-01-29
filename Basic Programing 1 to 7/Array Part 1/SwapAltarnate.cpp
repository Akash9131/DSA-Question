#include<iostream>
using namespace std;

void swapAltarnatearray(int arr[],int n) {
    int i = 0;
    while(i+1 < n) {
        
            swap(arr[i],arr[i+1]);
            i = i+2;
    }
}
int main() {
    /*/
    int even[6] = {2,7,5,6,9,8};

    cout<<"Swap altarnet even array is : " << endl;
    swapAltarnatearray(even,6);
    for(int i =0; i<6; i++) {
        cout<<even[i]<<" ";
    }

      cout<<endl;

*/


    int odd[7] = {3,7,2,2,7,3,4};
    int n = 7;
    
    swapAltarnatearray(odd,7);
    cout<<" Print arry is "<<endl;
    for(int i =0; i<n; i++){
        cout<<odd[i]<<" ";
    }
}