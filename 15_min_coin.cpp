/// NOTE : Infinite supply of coins

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Recursion{
    int solve(vector<int>&arr,int x, int n){
	    
	    
	    // base cases
	    if(x==0){return 0;}
	    
	    if(n==0){
	        
	        if(x%arr[n]==0)return x/arr[n];
	        return 1e9;
	    }
	    
	    int not_take = 0 + solve(arr,x,n-1);
	    
	    int take = INT_MAX;
	    
	    if(x>=arr[n])take = 1 + solve(arr,x-arr[n],n); // Note this step
	    
	    
	    return min(take,not_take);
	    
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    
	    int n = nums.size();
	    
	    int ans = solve(nums,amount,n-1);
	    
	    if(ans>=1e9)return -1;
	    
	    return ans;
	}
};

//-----------------------------------------------------------------------------------------------------------

class Memoization{
    int solve(vector<int>&arr,int x, int n,vector<vector<int>>&dp){
	    
	    
	    // base cases
	    if(x==0){return 0;}
	    
	    if(n==0){
	        
	        if(x%arr[n]==0)return x/arr[n];
	        return 1e9;
	    }
	    
	    if(dp[n][x]!=-1){return dp[n][x];}
	    
	    int not_take = 0 + solve(arr,x,n-1,dp);
	    
	    int take = INT_MAX;
	    
	    if(x>=arr[n])take = 1 + solve(arr,x-arr[n],n,dp);
	    
	    
	    return dp[n][x] = min(take,not_take);
	    
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    
	    int n = nums.size();
	    
	    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
	    int ans = solve(nums,amount,n-1,dp);
	    
	    if(ans>=1e9)return -1;
	    
	    return ans;
	}
};

//----------------------------------------------------------------------------------------------------------

class Tabulation{
    int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    
	    int n = nums.size();
	    
	    vector<vector<int>>dp(n,vector<int>(amount+1,0));
	    
	    
	    for(int t = 0;t<=amount;t++){
	        if(t%nums[0]==0)dp[0][t] = t/nums[0];
	        else dp[0][t] = 1e9;
	        
	    }
	    
	    
	    for(int i = 1;i<n;i++){
	        for(int j = 0;j<=amount;j++){
	            
	            int not_take = 0 + dp[i-1][j];
	    
        	    int take = INT_MAX;
        	    
        	    if(j>=nums[i])take = 1 + dp[i][j-nums[i]];
        	    
        	    
        	    dp[i][j] = min(take,not_take);
	        }
	    }
	    
	    
	    return dp[n-1][amount]>=1e9 ? -1 : dp[n-1][amount];
	}
};