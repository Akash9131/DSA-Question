#include<iostream>
using namespace std;

int score = 0;

void fun1(){
    
    cout<<score<<endl;
    score++;
    cout<<"Function 1"<<endl;
}
void fun2(){
    
    cout<<score<<endl;
    score+=2;
    cout<<"Function 2"<<endl;
}
void fun3(){

    cout<<score<<endl;
    score+=3;
    cout<<"Function 3"<<endl;
    
}

//inline function

inline  int function(int x, int y){
    //chal jayega but  body replace nhi hogi 
    // cout<<score<<endl;
    // score+=3;
    // if(x>y){
    //     cout<<" x is bigger "<<endl;
    // }
    // else{
    //     cout<<" y is bigger "<<endl;
    // }

      return  x*y;
}
int main()
{   fun1();
    fun2();
    fun3();

   int ans = function(2,5);

   cout<<"inline function ka ans -> "<< ans<<endl;
    
}