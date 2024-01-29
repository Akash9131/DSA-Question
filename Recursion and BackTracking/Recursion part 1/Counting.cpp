#include<iostream>
using namespace std;

void print(int n){
    //base case
    if(n< 1){
        return;
    }

    // //processing
    // cout<<n <<" ";


    //RR
    print(n -1);

    //processing
    cout<<n <<" ";
    
}
int main()
{
     int n ;
    cout<<"Enter the number "<<endl;
    cin >> n;


    cout<<" counting of n is : "<<endl;
    print(n);
    return 0;
}