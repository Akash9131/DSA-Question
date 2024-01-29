#include<iostream>
using namespace std;

void dumy(int *arr,int n){
    cout<<"size of arr  "<<sizeof(arr)<<endl;
}
int main(){

    int arr[]= {1,2,3,4,5};

    // cout<< *arr<<endl;
    // cout<< *(arr + 1)<<endl;
    //  cout<< *(arr + 2)<<endl;
    //   cout<< *(arr + 3)<<endl;
    //    cout<< *(arr + 4)<<endl;

    //    int i = 0;
    //    cout<< i[arr]<<endl;


    dumy(arr,5);

}
