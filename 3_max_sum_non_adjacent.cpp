#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
/*
    Problem:
            -Find max sum of elements in an array
            -No two elements can be adjacent

    Solution:
            -Use Pick No-Pick apprach
            -Use Dp for optimization
*/

// 1. Recurssion
int solve(int n,vector<int>&nums,int i){

    if(i>n){
        return 0;
    }
    else if(i==n){
        return nums[n];
    }

    int pick = nums[i] + solve(n,nums,i+2);
    int no_pick = solve(n,nums,i+1);

    return max(pick,no_pick);
}

// 2. Bottom-up
int solve_2(int ind,int n,vector<int>&nums,vector<int>&dp){

    if(ind>n){return 0;}

    else if(ind==n){
        return dp[n];
    }

    if(dp[ind]!=-1)return dp[ind];

    int pick = nums[ind] + solve_2(ind+2,n,nums,dp);
    int no_pick = solve_2(ind+1,n,nums,dp);

    return dp[ind] = max(pick,no_pick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size()-1;
    return solve(n,nums,0);
    vector<int>dp(n,-1);
    dp[n] = nums[n]; 
    int ans = solve_2(0,n,nums,dp);


    // Bottom Up

    vector<int> dp(n+1,-1);
    dp[0] = nums[0];

    for(int i =1;i<=n;i++){

        int take = nums[i];
        if(i>1)take+=dp[i-2];

        int not_take = dp[i-1];

        dp[i] = max(take,not_take);
    }
    
    return dp[n];
}
