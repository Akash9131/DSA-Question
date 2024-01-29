#include<iostream>
using namespace std;

int factorial(int n){
    //Base case
   // assuming n > 1
    if(n == 1){
        return 1;
    }

        //logic
        int smallProblem = factorial(n-1);
        int biggerProblem = n * smallProblem;
        return biggerProblem;
}
int main(){

    int n ;
    cout<<"Enter the number "<<endl;
    cin >> n;


    cout<<" Factorial of n is : "<<factorial(n)<<endl;
    
}