#include<iostream>
using namespace std;
int main()
{
    /*
    int num;
    cout<<"enter the value of num "<<endl;
    cin>> num;

    cout<< " The number is "<<num<<endl;

    // if statement

    if(num>0){
        cout<<" num is positive "<<endl;
    }// else statement
    else{
        cout<<"num is negative "<<endl;
    }


    //if- else statement

    if(num == 1){
       cout<<" number 1 hai "<<endl;
    }
    else if(num == 3 ){
        cout<<"number 2 hai "<<endl;
    }
    else{
        cout<<"number nhi pata "<<endl;
    }

    */

   
   
   int n ;
   cout << " Enter the value "<<endl;
   cin>> n;

   if(n < 1000){
       cout<< " you go to Delhi "<<endl;
   }
   else if( n < 2000){
       cout << "you go to  Kolkata "<<endl;
   }
   else if( n <= 3000){
       cout << "you go to jaipur "<<endl;
   }
   else{
       cout << " you go to any where "<<endl;
   }



}

