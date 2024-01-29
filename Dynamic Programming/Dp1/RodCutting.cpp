#include<iostream>
#include<vector>
using namespace std;
int solve(int n,int a , int b, int c) {
    //base case
    if(n == 0)
    return 0;

    if(n < 0 )
    return INT_MIN;

    int first = solve(n-a,a,b,c);
    int second = solve(n-b,a,b,c);
    int third = solve(n-c,a,b,c);

    return  1+ max(first,max(second,third));

}

// top Down approch
int solveMem(int n,int a , int b, int c,vector<int>& dp) {
    //base case
    if(n == 0)
    return 0;

    if(n < 0 )
    return INT_MIN;
    if(dp[n] !=  -1) {
        return dp[n];
    }

    int first = solveMem(n-a,a,b,c,dp);
    int second = solveMem(n-b,a,b,c,dp);
    int third = solveMem(n-c,a,b,c,dp);

    return dp[n] = 1+ max(first,max(second,third));

}
int main() {
    int n = 17;
    int a = 10;
    int b = 11;
    int c = 3;

    vector<int>dp(n+1,-1);

    int ans =  solve(n,a,b,c);
    int anss = solveMem(n,a,b,c,dp);

    cout<<" maximum cut in rod is -> "<<ans<<endl;
    cout<< " maximum cut in rod is -> "<<anss<<endl;

    int n1 = 10;
    int a1 = 9;
    int b1 = 7;
    int c1 = 11;
    
    
    int ans1 =  solve(n1,a1,b1,c1);
    if(ans1 <= 0) {
        ans1 = -1 ;
    }
    cout<<" maximum cut in rod is -> "<<ans1<<endl;
}