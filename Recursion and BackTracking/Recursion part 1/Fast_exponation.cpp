#include<iostream>
using namespace std;


int  expo(int n){
  // base case
  if(n == 0){
    return 1;
  }


  //processing
  int smallProblem = expo(n/2);

  if(n&1){
    return smallProblem * smallProblem * 2;
  }
  else{
    return smallProblem * smallProblem;
  }
     
}
int main()
{
    cout<<"Fast expontion is "<<expo(10)<<endl;
   cout<<"Fast expontion is "<<expo(11)<<endl;
}