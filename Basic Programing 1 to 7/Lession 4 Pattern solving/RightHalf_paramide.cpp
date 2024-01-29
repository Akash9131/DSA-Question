#include<iostream>
using namespace std;
int main()
{
    int n = 5;

    for(int row = 1; row<=n; row++){
        // ffor each row =, print stars = row ka number

        for(int col= 1; col<=row; col++)
        {
            cout<<"*"<<" ";
        }
        // after every row new line
        cout<<endl;
    }
}

/*

*
* *
* * *
* * * *
* * * * * 

*/