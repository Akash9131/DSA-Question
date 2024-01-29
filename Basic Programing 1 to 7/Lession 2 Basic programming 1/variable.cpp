#include<iostream>
using namespace std;
int main()
{
    int a = 5;
    cout << "value of a is "<< a<<endl;
    cout<< "size of int "<<sizeof(a)<<endl;

    char ch = 'a';
    cout<< "value of ch is "<< ch<<endl;
    cout << "size of charecter "<<sizeof(ch) <<endl;

    float b = 5.33;
    cout<< "value of b is "<< b<< endl;
    cout <<" size of float is "<<sizeof(b)<<endl;

    double c = 5.55;
    cout<< " value of c is "<< c<<endl;
    cout <<" size of double is "<<sizeof(c)<<endl;

    bool d = 0;
    cout<< " value of d is " <<d << endl;
    cout <<" size of bool is "<<sizeof(d)<<endl;


    float val = 5.0;
    int val2 = 3;

    int ans1 = val/val2;
    cout << "ans1 is " << ans1 <<endl;
    cout<<" ans is "<<(5.0/3)<<endl;

    char ch1 = 'a';
    int num =(int)ch1;
    cout <<" explicit type casting "<< num<< endl; 

    cout<<"size of short int " << sizeof(short int) <<endl;
    cout<<" size of long int "<< sizeof(long int )<<endl; // long int is a synonym for long .
    cout<<" size of long long int "<< sizeof(long long int)<<endl;// long long  was introdue to mean"long(64 bits) on window for real time."
    cout<<" size of wchar_t "<< sizeof(wchar_t)<<endl;  // wide charecter is similar to the *char* data  type, expect its size is 2 bytes instead of 1.
    // it is used to represent charecters that requires more memory to represent them than a single char.

    unsigned int m = -5;// only return positive number if it is not contain +ve so its return garbage value;
    cout<<"the m is "<<m<<endl;

    signed int l  = -5;// its contains both +ve and  -ve values..
    cout<<"The l is "<< l<<endl;
}                                   