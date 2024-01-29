#include<iostream>
#include<vector>
using namespace std;

//simple rec
int solve(int n ) {
    // base case
    if(n <= 1)
    return n;

    int ans = solve(n-1) + solve(n-2);
    
    return ans;
}

// top - Down approch
// solve in rec + memo
// step 1: create dp array + passs in function
// step2 :  store the ans in dp  array
// step3:  check if dp array already has answer,if yes then return just after the base case
int solveMem(int n,vector<int>&dp) {
    // base case
    if(n <= 1)
    return n;
    
    //step 3
    if(dp[n] != -1) {
        return dp[n];

    }

    int ans = solveMem(n-1,dp) + solveMem(n-2,dp);
    //step2:
    dp[n] = ans;
    return ans;
}

// Bottom-up approch
// step1: dp array creation
// step2 : base case analysis of rec code and update dp array accordingly
// step 3: find the range for the changing varible and copy pest the  llogic in rec code accordingly

int solveTab(int nthTerm) {
    //step1: create dp array
    vector<int>dp(nthTerm+1,0);
    // step2 : update dp array ,basis of recursion Basis case
    dp[0] = 0;
    dp[1] = 1;

    //step3: find range and copy peste
    for(int n = 2; n<=nthTerm; n++) {

       int ans = dp[n-1] + dp[n-2];
    dp[n] = ans; 
    }

    return dp[nthTerm];
}

//space optimizition
int solveTabSpaceOptimizion(int nthTerm) {
    //step1: replace dp array with your otimized storage structures && remove dp array
    vector<int>dp(nthTerm+1,0);
    int prev1 = 1;
    int prev2 = 0;
    int curr;
    //step2: dp values ko replace karna hai ->prev1 and prev2
    for(int n = 2; n<=nthTerm; n++) {

       int ans = prev1 + prev2;
       curr = ans;
       //step3: top care of the movement and updation of prev1 and prev2
        prev2 = prev1; 
       prev1 = curr;

    }
    
    return curr;
}

int main() 
{
    int n;
    cout<< "inter the value of n "<<endl;
    cin  >> n;

// step 1 :
vector<int>dp(n+1,-1);
    int ans = solve(n);
    int ans1 = solveMem(n,dp);
    int ans2 = solveTab(n);
    int ans3 = solveTabSpaceOptimizion(n);
    
    cout<<" the answer is -> "<<ans <<endl;
    cout<<" the answer is -> "<<ans1 <<endl;
    cout<<" the answer is -> "<<ans2 <<endl;
    cout<<" the answer is -> "<<ans3 <<endl;
}