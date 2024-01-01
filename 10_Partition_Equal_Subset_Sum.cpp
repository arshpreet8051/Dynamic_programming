#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

// Similar to problem - 9 subset sum


class memoization{
bool solve(vector<int>&arr,int ind,int sum,vector<vector<int>>&dp){

	// base case
	if(ind<0 or sum<0){return false;}

	if(ind == 0){return arr[ind] == sum;}
	
	if(sum==0){
		return true;
	}
	if(dp[ind][sum]!=-1){return dp[ind][sum];}

	bool take = solve(arr,ind-1,sum-arr[ind],dp);
	bool not_take = solve(arr,ind-1,sum,dp);

	return dp[ind][sum] = (take or not_take);

}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.

	if(n==1){return false;}
	int sum = 0;

	for(auto x : arr){
		sum+=x;
	}

	if(sum%2){return false;}
	sum/=2;

	vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	return solve(arr,n-1,sum,dp);
}


};
int main()
{


    return 0;
}