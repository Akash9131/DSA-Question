#include<iostream>
using namespace std;
int main()
{
    char  ch = 'G';
     char  *p = &ch;

     cout<<"Char ptr "<<*p <<endl;
      cout<<"Char ptr "<< p <<" "<<endl;

     char  ch1[] = "abcd";
     char  *p1 = ch1;

     cout<<"setof char ptr "<<p1;

}