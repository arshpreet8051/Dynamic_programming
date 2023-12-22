#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
/*Question:
Given nth stair to reach
Allowed moves -> 1 and 2
return all posiible ways to reach the nth stair
*/ 

// Recurrenece Relation
// f(n) = f(n-1) + f(n-2)

//----------------------------------------------------------------------------------------------------------------

//  1 -> Simple recursion

int solve_1(int n){
    
    // exception
    if(n==0){return 1;}
    
    // base case
    if(n<=2){return n;}

    int ans = solve_1(n-1) + solve_1(n-2);
    return ans;
}

//----------------------------------------------------------------------------------------------------------------

// 2 -> top down approach
// Recursion + Memoization

int solve_2(int n,vector<int>&dp){

    // exception
    if(n==0){return 1;}
    
    // step: 1 -> intialization
    dp[1] = 1;
    dp[2] = 2;

    // base case
    if(n<=2){return dp[n];}

    // step: 2 -> avoid already done calaulations
    if(dp[n]!=-1){return dp[n];}

    // store answer in dp
    return dp[n] = solve_2(n-1,dp) + solve_2(n-2,dp);
}

//----------------------------------------------------------------------------------------------------------------

// 3 -> Bottom up approach

int solve_3(int n){

    // step 1: intialization of dp array
    vector<int>dp(n+1,-1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    if(n<=2){return dp[n];}

    // step 2: iteration 

    for(int i = 3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//----------------------------------------------------------------------------------------------------------------


// 4 -> space optimized bottom up appraoch
int solve_4(int n){

    if(n<=2){return n;}

    int first = 1;
    int second = 2;

    int ans = 0;
    for(int i=3;i<=n;i++){
        ans = first+second;
        first = second;
        second = ans;
    }

    return ans;
}

int main()
{

    int n = 12;
    vector<int>dp(n+1,-1);
    int ans = solve_2(n,dp);
    return 0;
}