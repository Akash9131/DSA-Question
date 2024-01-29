#include<iostream>
using namespace std;

int solve(int coins[], int  size, int amount,int currentCoin){
    //base case
    if(amount == 0)
    return 1;

    if(amount < 0)
    return 0;

      int ways = 0;

      //use every coins
      for(int i= currentCoin; i<=size; i++){
        ways += solve(coins,size, amount - coins[i], i);
      }
      return ways;
}
int main()
{
    int coins[]= {1,2};
    int amount = 4;
    int size = 2;
    int ans = solve(coins, size,amount,0);
    cout<<"total way make amount is "<<ans<<endl;
}