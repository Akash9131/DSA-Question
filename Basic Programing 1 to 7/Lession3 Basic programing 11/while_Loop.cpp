#include<iostream>
using namespace std;
int main()
{

int num = 10;
/*
while(num != 0)
{
    cout<<"The number is "<< num <<endl;
    num = num -1;
    
}
*/

/*
 for(int i= 1; i<= num ; i++){
     cout<<  2* i <<endl;

 }
 */

 /* while( num!= 0){
     cout <<"Akash Haldar "<<endl;
     num = num -1;
  }
  
  */


 int sum = 0;
 int i = 1;

 while(i<=num){
     sum = sum+i;
     i= i+1;

 }

 cout << sum<<endl;

}