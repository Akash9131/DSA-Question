#include<iostream>
using namespace std;
int main()
{
    int a  = 5;
    int *p  = &a;

    cout<<"a is " <<a<<endl;
    cout<<"&a is " <<&a<<endl;
    // cout<<"*a is " <<*a<<endl;
    cout<<"p is " <<p<<endl;
    cout<<"*p is " <<*p<<endl;
    cout<<"&p is " <<&p<<endl;
}
