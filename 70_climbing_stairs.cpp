#include<bits/stdc++.h>

using namespace std;

int climbingStairs(int ind,vector<int>&dp){
    if(ind==0 || ind==1){
        return 1;
    }
    if(dp[ind]!=0){
        return dp[ind];
    }
    dp[ind] = climbingStairs(ind-1,dp)+climbingStairs(ind-2,dp);

    return dp[ind];
}   

int main()
{
    int n=3;
    vector<int>dp(n+1,0);
    cout<<climbingStairs(n,dp);
}