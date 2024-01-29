#include<iostream>
using namespace std;
int main()
{
    int  n ;
    cout << "Enter the number "<<endl;

    cin>> n;

   /*
    bool isPrime = true;

    for(int i = 2; i<n; i++){
        //  dived ho gya kisi se
        if(n%i== 0){
            isPrime = 
            false;
            break;
        }
    }

    if(isPrime== true){
        cout<<" The number is prime no "<<endl;
    }
    else{
        cout<<"This is not a prime no "<<endl;
    }
    */

   int i = 2;

     while(i<n){

         if(n%i != 0){
             cout<<" This is prime number "<<endl;
             break;
         }
         else{
              cout<<" This is not a prime number "<<endl;
              break;
         }
         i++;
     }


}