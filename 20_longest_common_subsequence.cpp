#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Recursion
class Recursion{
    int solve(string &s,string &t,int i,int j){
	
	if(i<0 or j<0)return 0;

	if(s[i]==t[j]){
		return 1 + solve(s,t,i-1,j-1);
	}
	else{
		return max(solve(s,t,i-1,j),solve(s,t,i,j-1));
	}
}

int lcs(string s, string t)
{
	int i = s.size()-1;
	int j = t.size()-1;

	return solve(s,t,i,j);
}
};

//-----------------------------------------------------------------------------------------------------------

// Memoization

class Memoization{
int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
	
	if(i<0 or j<0)return 0;

	if(dp[i][j]!=-1)return dp[i][j];
	
	if(s[i]==t[j]){
		return dp[i][j] = 1 + solve(s,t,i-1,j-1,dp);
	}
	else{
		return dp[i][j] = max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));
	}
}

int lcs(string s, string t)
{
	int i = s.size()-1;
	int j = t.size()-1;

	vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
	return solve(s,t,i,j,dp);
}
};

//---------------------------------------------------------------------------------------------------------
// Tabulation

class Tabulation{
int lcs(string s, string t)
{
	//Write your code here
	int n = s.size();
	int m = t.size();

	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));


	// base cases

	// Note : Shifting of indexes for implementing base cases

	for(int i = 0;i<=n;i++)dp[i][0] = 0;
	
	for(int j = 0;j<=m;j++)dp[0][j] = 0;

	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
		return dp[n][m];
	}
};