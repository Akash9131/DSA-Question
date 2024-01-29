#include<iostream>
using namespace std;

/*
// Aproach 2
bool isPowerofTwo(int num) {
   if (num <= 0)
   return false;
   int ans = (num&(num-1));

   if(ans == 0) {
    return true;
   }
   else return false;
}

*/
bool isPowerofTwo(int num) {
    if(num <= 0)
    return false;
    int count = 0;
    while(num != 0) {
       if (num&1) {
        count++;
       }
       num = num >>1;
    }

    if(count == 1)
    return true;
    else
     return false;
}



int main()
 { cout << " enter your number "<<endl;
   int num;
  cin >> num;

  cout <<" The ans is : "<<isPowerofTwo(num)<<endl;

}