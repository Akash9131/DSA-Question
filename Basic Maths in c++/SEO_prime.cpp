#include<iostream>
#include<vector>
using namespace std;

int SEOPrimeCount(int n){

    int count  = 0;
    // prime number ko inatially  prime man liya
    vector<bool>prime(n+1,true);
     
    //  o aur 1  ko noon prime mark kar do
    prime[0] = prime[1]  = false;
    
    // table wise non-prime mark kar do
    for(int i = 2; i<n; i++){

        if(prime[i])
        count ++;
       
        // table wise non prime mark kar do
        for(int j = 2*i; j<n;  j= j+i){
            prime[j] = 0;
        }
    }
    return count;    
}
int main()
{
    int n = 30;

    cout<<"Count of prime no is "<<SEOPrimeCount(n);
}