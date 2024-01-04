#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Recursion
class Recursion{

int solve(vector<int>&weight, vector<int>&value, int n, int mw,int w,int ind){

	// base case

	// bag full
	if(w==mw){return 0;}

	// bag overflow
	if(w>mw){return -1;}

	// index 0
	if(ind==0){

		if(w + weight[ind] <= mw){return value[ind];}
		return 0;
	}
 
	if(ind<0){return -1;}

	int not_take = INT_MIN;
	int nt = solve(weight,value,n,mw,w,ind-1);

	if(nt!=-1)not_take = nt;

	int take = INT_MIN;
	int t = solve(weight,value,n,mw,w+weight[ind],ind-1);
	if(t!=-1)take = value[ind] + t;

	return max(take,not_take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	int w = 0;

	int ans = solve(weight,value,n,maxWeight,w,n-1);
	if(ans==-1){return 0;}
	return ans;
}
};

//---------------------------------------------------------------------------------------------------

// Memoization

class Memoization{

int solve(vector<int>&weight, vector<int>&value, int n, int mw,int w,int ind,vector<vector<int>>&dp){

	// base case

	// bag full
	if(w==mw){return 0;}

	// bag overflow
	if(w>mw){return -1;}

	// index 0
	if(ind==0){

		if(w + weight[ind] <= mw){return value[ind];}
		return 0;
	}
 
	if(ind<0){return -1;}

	if(dp[ind][w]!=-1){return dp[ind][w];}

	int not_take = INT_MIN;
	int nt = solve(weight,value,n,mw,w,ind-1,dp);

	if(nt!=-1)not_take = nt;

	int take = INT_MIN;
	int t = solve(weight,value,n,mw,w+weight[ind],ind-1,dp);
	if(t!=-1)take = value[ind] + t;

	return dp[ind][w] = max(take,not_take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	int w = 0;
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	int ans = solve(weight,value,n,maxWeight,w,n-1,dp);
	if(ans==-1){return 0;}
	return ans;
}
};

//---------------------------------------------------------------------------------------------------

// Tabulation
class Tabulation{
     int knapSack(int W, int wt[], int val[], int n) 
    { 
       // in tabulation method take care of base case
       // for every index zero and for every weight less than equal to max weight, we can steal the value
       
    
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        
        for(int w = wt[0];w<=W;w++){
            dp[0][w] = val[0];
        }
        
        for(int ind = 1;ind<n;ind++){
            for(int w = 0;w<=W;w++){
                
            	int not_take = dp[ind-1][w];
            
            	int take = INT_MIN;
            	if(wt[ind]<=w)take = val[ind] + dp[ind-1][w-wt[ind]];
            
                dp[ind][w] = max(take,not_take);
            }
        }
        
        return dp[n-1][W];
       
    }
};