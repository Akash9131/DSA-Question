#include<iostream>
using namespace std;
int fun(int x, int*y, int** z){
    int p,q;
    **z += 1;
    q = **z;
    *y +=2;
    p = *y;
    x  += 3;
    return x+p+q;
}
int main()
{
    int c,*b, **a;

    c =4;
    b = &c;
    a= &b;

    cout<<fun(c,b,a);
}