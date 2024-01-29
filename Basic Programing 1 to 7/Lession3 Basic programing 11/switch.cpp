#include<iostream>
using namespace std;
int main()
{
   /* int n;
    cin>>n;

    cout<<n<<endl;

    // switch statement
    switch(n){
        case 0: cout<< "I am case in 0 "<<endl;
        break;
        case 7 : cout<<" I am case in 7 "<<endl;
        break;
        default: cout<<"I am in default case "<<endl;
    }
    */

   int a ,b;

   cout<< "Enter the value value of a and b" <<endl;
   cin>> a >> b;
  
   char op;
   cin>>op;

   switch (op)
   {
   case '+': cout<<  a+b <<endl;
   break;
       
       case '-' : cout<< a-b <<endl;
       break;
       case '*': cout<< a*b <<endl;
       break;
       case  '/' : cout << a/b <<endl;
       break;
   default: cout<<"this is default case "<<endl;
       break;
   }


   switch (a+2*b){
       case 0 : cout<< "this is zero"<<endl;
       break;
       case 15 : cout<<" this is 15 "<<endl;
       default : cout<< "This is default "<<endl;
   }
  
}