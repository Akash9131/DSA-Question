#include<iostream>
using namespace std;
int main()
{
    int a = 5;

    int *p = &a;

    cout<<"Size of (*p) is "<<sizeof(*p)<<endl;

    cout<<" *p is "<<*p<<endl;

    int *p1 = 0;

    cout<<"*p1 is"<<*p1<<endl;
}