#include<iostream>
using namespace std;

void printEven(int n){
    for(int i = 2; i<=n; i+2){
        cout<<"print even "<<i<<endl;
    }

}
int main()
{
    int n = 21;

    printEven(21);

}