#include<iostream>
using namespace std;
int main()
{
    /*
    int n = 5;

    for(int i = 0; i<n; i++){
        cout<<"Akash Haldar "<<endl;
    }
    */

   int n = 10;
   for(int i = 1; i<=n; i++){
       cout<< 2*i<<endl;
     //  break;
   }

   int v = 5;
   cout<<v++<<endl;
   cout<<v<<endl;

   int q = 5;
   cout<<++q<<endl;
   cout<<q <<endl;


   int e = 5;
   cout<<--e<<endl;
   cout<<e<<endl;

   int y = 5;
   cout<<y--<<endl;
   cout<<y <<endl;


   int o = 10;

   for(int i = 1 ;i<n; i++){
       if(i%2 == 0){
           continue;
          // break;
       }
       cout<<i<<endl;
   }

   int g = 10;

   for(;;){
       if(g>0){
       cout<<"Akki "<<endl;
       g--;
       }
       else{
           break;
       }
   }
   cout<<"Khatam"<<endl;
   
}