#include<iostream>
using namespace std;

void fun1(int ** q){
    q= q+1;
}

void fun2(int ** q){
   *q= *q+1;
}
void fun3(int ** q){
    **q= **q+1;
}
int main()
{
    int a = 5;

    int *p = &a;

    int **q = &p;



//   cout<< a<<endl;
//   cout<<&a<<endl;
// //   cout<<*a<<endl;


//   cout<< p<<endl;
//   cout<<&p<<endl;
//   cout<<*p<<endl;


//    cout<< q<<endl;
//   cout<<&q<<endl;
//   cout<<*q<<endl;
//   cout<<**q<<endl;


//1
 cout<<"Before "<<q<<endl;
 cout<<"Before "<<*q<<endl;
 cout<<"Before "<<**q<<endl;


 fun1(q);
 
 cout<<"After "<<q<<endl;
 cout<<"After "<<*q<<endl;
 cout<<"After "<<**q<<endl;

cout<<"next function call "<<endl;
cout<<endl;
cout<<endl;

//fun 2
  cout<<"Before "<<q<<endl;
 cout<<"Before "<<*q<<endl;
 cout<<"Before "<<**q<<endl;


 fun2(q);
 
 cout<<"After "<<q<<endl;
 cout<<"After "<<*q<<endl;
 cout<<"After "<<**q<<endl;



//fun3

cout<<"next function call "<<endl;
cout<<endl;
cout<<endl;

  cout<<"Before "<<q<<endl;
 cout<<"Before "<<*q<<endl;
 cout<<"Before "<<**q<<endl;

 fun3(q);
 
 cout<<"After "<<q<<endl;
 cout<<"After "<<*q<<endl;
 cout<<"After "<<**q<<endl;
}