#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 

class Recursion{
     
int solve(vector<int>&arr,int k,int ind){

	if(k==0){return 1;}

	if(ind == arr.size()-1){return arr[ind]==k;}
	if(ind>arr.size()-1 or k<0){return 0;}


	int not_take = solve(arr,k,ind+1);

	int take = 0;
	if(arr[ind]<=k)take = solve(arr,k-arr[ind],ind+1);

	int mod = 1e9+7;

	return (take + not_take)%mod;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.

	return solve(arr,k,0);
}

};

//---------------------------------------------------------------------------------------------------

class Memoization{

    
int solve(vector<int>&arr,int k,int ind,vector<vector<int>>&dp){

	if(k==0){return 1;}

	if(ind == arr.size()-1){return arr[ind]==k;}
	if(ind>arr.size()-1 or k<0){return 0;}

	if(dp[ind][k]!=-1){return dp[ind][k];}

	int not_take = solve(arr,k,ind+1,dp);

	int take = 0;
	if(arr[ind]<=k)take = solve(arr,k-arr[ind],ind+1,dp);

	int mod = 1e9+7;

	return dp[ind][k] = (take + not_take)%mod;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	vector<vector<int>>dp(arr.size(),vector<int>(k+1,-1));
	return solve(arr,k,0,dp);
}

};

//-------------------------------------------------------------------------------------------------

class Tabulation{

    int findWays(vector<int>& arr, int k)
{
	// Write your code here.

	int n = arr.size();
	int mod = 1e9+7;

	vector<vector<int>>dp(n,vector<int>(k+1,0));

	for(int i = 0;i<n;i++){
		dp[i][0] = 1;
	}

	if(arr[0]<=k)dp[0][arr[0]] = 1;

	for(int i = 1;i<n;i++){
		for(int j = 0;j<=k;j++){

			int not_take = dp[i-1][j];

			int take = 0;
			if(arr[i]<=j)take = dp[i-1][j-arr[i]];
			
			dp[i][j] = (take+not_take)%mod;

		}
	}

	return dp[n-1][k];
}

};
int main()
{


    return 0;
}