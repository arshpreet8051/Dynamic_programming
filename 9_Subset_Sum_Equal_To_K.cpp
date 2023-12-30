#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &


// Recursion
class Recursion{
    public:
    bool solve(int n,int sum,vector<int>&arr){
        
        // base case
        if(sum==0){return true;}
        
        if(n==0){return arr[n]==sum;}
        
        if(sum<0 or n<0){return false;}
        
        bool take = solve(n-1,sum-arr[n],arr);
        bool not_take = solve(n-1,sum,arr);
        
        return (take or not_take);
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        int n = arr.size();
        return solve(n-1,sum,arr);
    }
};

// Memoization
class Memoization{
    public:
    bool solve(int n,int sum,vector<int>&arr,vector<vector<int>>&dp){
        
        // base case
        if(sum<0 or n<0){return false;}
        if(sum==0){return true;}
        if(n==0){return arr[n]==sum;}
        
        
        if(dp[n][sum]!=-1){return dp[n][sum];}
        
        bool take = solve(n-1,sum-arr[n],arr,dp);
        bool not_take = solve(n-1,sum,arr,dp);
        
        return dp[n][sum] = (take or not_take);
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};

// Tabulation
class Tabulation{
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));

    for(int index = 0;index<n;index++){
        dp[index][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int index = 1;index<n;index++){
        for(int target = 1;target<=k;target++){
            bool not_take = dp[index-1][target];
            bool take = false;
            if(arr[index]<=target)take = dp[index-1][target-arr[index]];
            dp[index][target] = (take | not_take);
        }
    }

    return dp[n-1][k];
}
};
int main()
{


    return 0;
}