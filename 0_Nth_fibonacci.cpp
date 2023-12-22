#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define and &&
#define or ||



// TOP DOWN APPROACH DP
int top_down_dp_fib(int n, vector<int>&dp){

    // recursion + memoization
    if(n==0 or n==1){return n;}

    if(dp[n]!=-1){return dp[n];}

    return dp[n] = top_down_dp_fib(n-1,dp) + top_down_dp_fib(n-2,dp);

}

// BOTTOM UP APPROACH DP
int bottom_up_dp(int n){

    // Tabulationp
    vector<int> dp(n+1,-1);

    dp[0] = 0;
    if(n==0){return dp[0];}

    dp[1] = 1;
    if(n==1){return dp[1];}

    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// base function
int Nth_fib(int n){

    vector<int> dp(n+1,-1);
    
    // TOP DOWN APPROACH
    return top_down_dp_fib(n,dp);

    // BOTTOM UP APPROACH
    return bottom_up_dp(n);
}

int main()
{
    
    int n = 10;
    cout<<Nth_fib(n);
    return 0;
}