#include<iostream>
using namespace std;

void printsqure(int n){
    for(int i =1; i<=n; i++){
        cout<<"print squre "<<i*i<<endl;
    }
}

int main(){
    int n = 6;

    printsqure(6);
}