#include<iostream>
using namespace std;
void suresh(int k){
    cout<<"suresh call "<<k<<endl;
}

void rahul(int m ){
    cout<<"Rahul call "<<m<<endl;
    m++;
    suresh(m);
}

void ramesh(int n){
    cout<<" Ramesh call "<<n<<endl;
    n++;
    rahul(n);
}
int main()
{
    int n = 21;

    ramesh(n);
    cout<<"wapas in main function "<< n<<endl;
}