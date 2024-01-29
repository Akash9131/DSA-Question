#include<iostream>
using namespace std;
int main()
{
    int n = -137;

    while(n !=0){
        int digit = n%10;

        cout<<"Digit "<<digit<<endl;

        n = n/10;

        cout<<"Done"<< endl;
    }
}