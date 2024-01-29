#include<iostream>
#include<vector>
using namespace std;
//top -Down
int solve(vector<int>&arr,int index, vector<int>&dp) {
    // base case
    if(index >= arr.size()) {
        return 0;
    }
    if(dp[index] != -1) {
        return dp[index];
    }
    int include = arr[index] + solve(arr,index+2,dp);
    int exclude =    0       + solve(arr,index+1,dp);

    return  dp[index] = max(include,exclude);
}

//Bottom up
int solveTab(vector<int>&arr, int n) {
    // base case
    vector<int>dp(arr.size()+2, 0);

    for(int index = arr.size() - 1; index >= 0; index--) {
   int include = arr[index] + dp[index+2];
    int exclude =    0       + dp[index+1];

      dp[index] = max(include,exclude);
    }
    return dp[0];
}

// space optimization
int solveTabSo(vector<int>&arr, int n) {
    // base case
   // vector<int>dp(arr.size()+2, 0);
    int next1 = 0;
    int next2 = 0;
    int curr;

    for(int index = arr.size() - 1; index >= 0; index--) {
   int include = arr[index] + next2;
    int exclude =    0       + next1;

      curr = max(include,exclude);
      next2 = next1;
      next1 = curr;
    }
    return curr;
}

int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);

   int ans = 0;
   vector<int>dp(arr.size(), -1);
  cout<<"the ans is ->  " <<solve(arr,0,dp)<<endl;

  cout<<"the ans is ->  " <<solveTab(arr,arr.size())<<endl;
  cout<<" SO ans is -> "<< solveTabSo(arr,arr.size())<<endl;

}