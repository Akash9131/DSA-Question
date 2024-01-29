#include<iostream>
using namespace std;
int main()
{
    int n =  4;
    // for each row
    for(int row = 1; row<=n; row++)
    {    // space
        for(int col = 1; col<=row-1;col++)
        {
            cout<<" "<<" ";
        }
        // star
        for(int col = 1; col<=(n-row)+1; col++)
        {
            cout<<"*"<<" ";
        }
        //after each row new line
        cout<<endl;
    }
}

/*

* * * *
  * * *
    * * 
      *  



*/