#include<iostream>
#include<vector>
using namespace std;

int minCoin(int target , vector<int>& arr) {
    // base case
    if(target == 0) 
        return 0;

        if(target < 0)
        return INT_MAX;

        int mini = INT_MAX;
        for(int i = 0; i< arr.size(); i++) {
           int  ans = minCoin(target - arr[i], arr);
           //u are able to build target
           if(ans != INT_MAX) {
            mini = min(mini,1 +ans);
           }

        }
        return  mini;
    
}

int minCoinTD(int target , vector<int>& arr, vector<int>& dp) {
    // base case
    if(target == 0) 
        return 0;

        if(target < 0)
        return INT_MAX;
        
        if(dp[target] != -1) {
            return dp[target];
        }

        int mini = INT_MAX;
        for(int i = 0; i< arr.size(); i++) {
           int  ans = minCoinTD(target - arr[i], arr, dp);
           //u are able to build target
           if(ans != INT_MAX) {
            mini = min(mini,1 +ans);
           }

        }
        return  dp[target] = mini;
    
}
int minCoinTab(int t, vector<int>arr) {
    vector<int>dp(t, INT_MAX);
    dp[0] = 0;

    for(int target = 1; target <= t ; target++) {
         int mini = INT_MAX;
        for(int i = 0; i< arr.size(); i++) {
           if(target - arr[i] >= 0) {
            int  ans = dp[target - arr[i]];
           //u are able to build target
           if(ans != INT_MAX) {
            mini = min(mini,1 +ans);
           }
           }
        }
         dp[target] = mini;
    }
    return dp[t];

}
int main()
{
    vector<int>arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    int target = 7;

    vector<int>dp(target+1,-1);


     cout<<" maximum no of element "<<minCoin(target,arr)<<endl;
     cout<<" maximum no of element "<<minCoinTD(target,arr,dp)<<endl;
     cout<<"maximum no of  element "<<minCoinTab(target,arr)<<endl;
}