// maximum number of array 
// ip-> 3 12 7 18 17 16
// op-> 18


#include<iostream>
//Inatilisize of pair stl
#include<utility>
using namespace std;



// maximum number in arr
int maximumNum(int arr[], int n){

     int ans = INT_MIN;
    for(int i=0; i<n; i++){
          ans= max(arr[i],ans);
    }
    return ans;
}

// minimum number in array
int minimumNum(int arr[],int n) {
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        ans = min(arr[i],ans);
    }
    return ans;
}


//fint amxmin in array
pair<int,int>get_maxMinArray(int arr[],int n) {
       int maxi = INT_MIN;
       int mini = INT_MAX;

       for(int i =0; i<n; i++) {
         maxi = max(arr[i],maxi);
         mini = min(arr[i],mini);
       }
       pair<int,int>p = make_pair(maxi,mini);
       return p;
       
}


int main() {
    int arr[] ={3,12,7,18,17,16};
    int n = 6;



    cout <<"MAximum number is : " <<maximumNum(arr,6)<<endl;;

    cout <<"Minimum number  is : "<<minimumNum(arr,6)<<endl;

 

    pair<int,int>j = get_maxMinArray(arr,6);

    cout<<"maximum number in Array  : "<<j.first<<endl;
    cout<<"minimum number is Array  : "<<j.second<<endl;
       
    
}