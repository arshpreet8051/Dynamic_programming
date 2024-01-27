/*
    LOGIC -> Pick - Not Pick
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

// Recursion
class Recursion{
    int solve(int arr[],int n,int ind,int prev_ind){

    // base case
    if(ind == n)return 0;


    int pick = INT_MIN;
    if(prev_ind == -1 or arr[prev_ind] < arr[ind]){
        pick = 1 + solve(arr,n,ind+1,ind);
    }

    int not_pick = 0 + solve(arr,n,ind+1,prev_ind);

    return max(pick,not_pick);
    
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return solve(arr,n,0,-1);
}
};

//---------------------------------------------------------------------------------

// Memoization
class Memoization{
   int solve(int arr[],int n,int ind,int prev_ind,vector<vector<int>>&dp){

    // base case
    if(ind == n)return 0;

    // Cordinate shifting
    if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];

    int pick = INT_MIN;
    if(prev_ind == -1 or arr[prev_ind] < arr[ind]){
        pick = 1 + solve(arr,n,ind+1,ind,dp);
    }

    int not_pick = 0 + solve(arr,n,ind+1,prev_ind,dp);

    return dp[ind][prev_ind+1] = max(pick,not_pick);
    
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return solve(arr,n,0,-1,dp);
}
};

// Tabulation

class Tabulation{
    int longestIncreasingSubsequence(int arr[], int n)
{
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int ind = n-1;ind>=0;ind--){
        for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
            int pick = INT_MIN;

            if(prev_ind == -1 or arr[prev_ind] < arr[ind]){

                // GAME : Due to coordinate shifting - second variable will be +1
                pick = 1 + dp[ind+1][ind+1];
            }

            int not_pick = 0 + dp[ind+1][prev_ind+1];

            dp[ind][prev_ind+1] = max(pick,not_pick);
        }
    }
    return dp[0][-1+1];
}
};

//--------------------------------------------------------------------------------------

// Space Optimization

class Sapce_optimization{
    int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int>curr(n+1,0), next(n+1,0);


    for(int ind = n-1;ind>=0;ind--){
        for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){
            int pick = INT_MIN;
            if(prev_ind == -1 or arr[prev_ind] < arr[ind]){
                pick = 1 + next[ind+1];
            }

            int not_pick = 0 + next[prev_ind+1];

            curr[prev_ind+1] = max(pick,not_pick);
        }

        next = curr;
    }
    return next[-1+1];
}
};