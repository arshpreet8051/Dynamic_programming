#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// recursion

class Recursion{
    
int solve(vector<int>&price,int length,int index){

	if(index == 1){
		if(length%index==0)return price[0]*(length/index);
		return -1e9;
	}
	
	if(length<0)return -1e9;

	int not_take = solve(price,length,index-1);
	int take = INT_MIN;
	if(length-index>=0)take = price[index-1]+solve(price,length-index,index);


	return max(take,not_take);

}

int cutRod(vector<int> &price, int n)
{
	int length = n;
	int index = n;

	return solve(price,length,index);
}

};

//---------------------------------------------------------------------------------------------------------
// Memoization

class Memoization{
    
int solve(vector<int>&price,int length,int index,vector<vector<int>>&dp){

	if(index == 1){
		if(length%index==0)return price[0]*(length/index);
		return -1e9;
	}
	
	if(length<0)return -1e9;

	if(dp[index][length]!=-1)return dp[index][length];

	int not_take = solve(price,length,index-1,dp);
	int take = INT_MIN;
	if(length-index>=0)take = price[index-1]+solve(price,length-index,index,dp);


	return dp[index][length] = max(take,not_take);

}

int cutRod(vector<int> &price, int n)
{
	int length = n;
	int index = n;

	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	return solve(price,length,index,dp);
}};

//-----------------------------------------------------------------------------------------------

// Tabulation

class Tabulation{
    
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));

	for(int len = 1;len<=n;len++){
		if(len%1==0)dp[1][len] = price[0]*(len/1);
	}

	for(int ind = 2;ind<=n;ind++){
		for(int len = 1;len<=n;len++){

			int not_take = dp[ind-1][len];
			int take = INT_MIN;
			if(len-ind>=0)take = price[ind-1]+dp[ind][len-ind];


			dp[ind][len] = max(take,not_take);
				}
			}
			return dp[n][n];
}
};