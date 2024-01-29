#include<iostream>
#include<vector>
using namespace std;

// simple recurrsion
int knapsackProblem(vector<int>& val, vector<int>& wt, int index, int capacity) {
    // base case
    if(index == val.size() ||  capacity == 0) 
        return 0;

        int include = 0;

        if(capacity >= wt[index])
         include = val[index] + knapsackProblem(val,wt,index+1, capacity - wt[index]);
         
         int exclude = 0 + knapsackProblem(val,wt,index+1,capacity);

         return  max(include,exclude);


    
}
// top Down approch
int knapsackProblem1(vector<int>& val, vector<int>& wt, int index, int capacity, vector<vector<int> >& dp) {
    // base case
    if(index == val.size() ||  capacity == 0) 
        return 0;

        if(dp[index][capacity] != -1) 
        return dp[index][capacity];

        int include = 0;

        if(capacity >= wt[index])
         include = val[index] + knapsackProblem1(val,wt,index+1, capacity - wt[index],dp);
         
         int exclude = 0 + knapsackProblem1(val,wt,index+1,capacity,dp);

         return  dp[index][capacity] = max(include,exclude);


    
}

// bottom up approch
int knapsackProblemTab(vector<int>& val, vector<int>& wt, int index,int C, int n) {
  vector<vector<int> > dp(n+1,vector<int>( C+1,0));

  for(int index = n-1 ; index>= 0; index--) {
    for(int capacity = 0; capacity <= C; capacity++) {
         int include = 0;

        if(capacity >= wt[index])
         include = val[index] + dp[val,wt,index+1][capacity - wt[index]];
         
         int exclude = 0 + dp[val,wt,index+1][capacity];

          dp[index][capacity] = max(include,exclude);
    }
  }
  /*
  for(int index = n-1 ; index>= 0; index--) {
    for(int capacity = 0; capacity <= C; capacity++) {
      cout<<dp[index][capacity]<<" ";
    }
    cout<<endl;
  }
  */
  return dp[0][C];
}


int main()
{
    int n = 3;

    vector<int>val,wt;
    val.push_back(60);
    val.push_back(100);
    val.push_back(120);

    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);

    int capacity = 50;
    int ans = knapsackProblem(val,wt,0,capacity);
    cout<<"Knapsack  problem ans is -> "<< ans <<endl;

    vector<vector<int> > dp(n,vector<int>(capacity+1,-1));
    int ans1 = knapsackProblem1(val,wt,0,capacity,dp);
    cout<<"Knapsack  problem ans is -> "<< ans1 <<endl;

    int ans2 = knapsackProblemTab(val,wt,0,capacity,n);
    cout<<"Knapsack problem ans2 is -> "<<ans2<<endl;


}