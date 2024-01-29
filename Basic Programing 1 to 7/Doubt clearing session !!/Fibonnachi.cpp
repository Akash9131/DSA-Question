#include<iostream>
using namespace std;
void printFibonacchi(int n){
    int first = 0;
    int second = 1;
    int sum ;
    cout << first <<" "<<second<<" ";
    for(int i = 3; i<n; i++){
        int sum = first+ second;
        cout<<sum<<" ";
        first = second;
        second = sum;
    }

}

int main(){
    int n = 8;

    printFibonacchi(9);
}