#include<iostream>
using namespace std;

void function(int *p){
    *p = *p+1;
}
int main()
{
    int a = 5;
    int *p = &a;

    cout<<"before " <<p<<endl;
    cout<<"before "<<*p <<endl;


    function(p);
    cout<<"after " <<p<<endl;
    cout<<"after "<<*p <<endl;

}
