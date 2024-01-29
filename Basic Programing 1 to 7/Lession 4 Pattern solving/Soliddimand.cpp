#include<iostream>
using namespace std;
int main()
{
    int  n = 5;

/*

      for(int row = 1; row<=n; row++)
    {  // for each row 

        //space
        for(int col = 1; col<= n- row; col++)
        {
            cout<<" "<<" ";
        }
        // star
        for(int col= 1; col<=row; col++)
        {
            cout<<"*"<<" ";
        }
        for(int col = 1; col<= row;col++)
        {
            cout<<"*"<<" ";
        }

        // after each row new line
        cout<<endl;
    


    }
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
         for(int col = 1; col<= (n-row)+1; col++) 
        {
            cout<<"*"<<" ";
            
        }
        //after each row new line
        cout<<endl;
    }
    */

   for(int row = 1; row<=n; row++)
    {
        for(int col=1; col<=(n-row); col++)
        {
            cout<<" ";
        }
        for(int col= 1; col<= row; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
 for(int row = 1; row<=n; row++)
    {
        for(int col=1; col<=row-1; col++)
        {
            cout<<" ";
        }
        for(int col= 1; col<= (n-row)+1; col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }

}

/*
    *
   * *
  * * *
 * * * *
* * * * *
* * * * *
 * * * *
  * * *
   * *
    *



*/
