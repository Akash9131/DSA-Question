#include<iostream>
using namespace std;

int  getfactorial(int n){
    int ans = 1;
    for(int i =1; i<=n; i++){
        ans = ans * i;
    }
    return ans;
}
int main()
{
    int n = 5;

     int fact =getfactorial(5);

     cout<<"factorial is "<<fact<<endl;
}