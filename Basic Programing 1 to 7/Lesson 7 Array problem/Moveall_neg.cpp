// move all negative in one side and  positive anathor side
//i/p = 3 -1  2 -4 -6 -4 5
//o/p = -1 -4 -6 -4 3 2 5

#include<iostream>
#include<algorithm>
using namespace std;

// tc- o(n)  sc-O(1)
void move_negative (int arr[], int n) {
    int j = 0;

    for(int i=0; i<n; i++){
        if(arr[i]<0){
             if(i != j)
            swap(arr[i],arr[j]);
            j++;
        }
    }

}

//Tc - O(n) Sc-O(1)
void ReArrange(int arr[],int n) {
    int low = 0;
    int high = n-1;

    while(low<high){
        if(arr[low]< 0){
            low++;
        }
        else if(arr[high]> 0){
            high--;
        }
        else{
            swap(arr[low],arr[high]);
        }
    }
}

//using vector short begin end  function tc is O(nlogn) and sc is O(n); 


void printArray(int arr[], int n){
    for(int i=0; i<n; i++) {
        cout<<arr[i] <<" ";
    }
    cout <<endl;
}

int main()
{
    int arr[] = {3,-1,2,-4,-6,-4,5};
    int n = 7;

   

    // move_negative(arr,7);
     ReArrange(arr,7);
    cout<<"printing array "<<endl;
      printArray(arr,7);

}