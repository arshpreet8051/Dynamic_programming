
/*
    Same as Ques 31 just add -fee after selling
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Memoization{
    int solve(vector<int>&arr,int n,int i,int buy,vector<vector<int>>&dp,int fee){

    // base case
    if(i==n)return 0;

    if(dp[i][buy]!=-1)return dp[i][buy];

    // if i can buy
    if(buy){

        int buy_it = -arr[i] + solve(arr,n,i+1,0,dp,fee);
        int donot_buy = 0 + solve(arr,n,i+1,1,dp,fee);

        return dp[i][buy] = max(buy_it,donot_buy);
    }

    // i cannot buy
    else{

        int sell = arr[i] + solve(arr,n,i+1,1,dp,fee) - fee;
        int donot_sell = 0 + solve(arr,n,i+1,0,dp,fee);

        return dp[i][buy] = max(sell,donot_sell);
    }


}
int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(2,-1));
	int ans = solve(prices,n,0,1,dp,fee);
	return  ans>=0 ? ans : 0;
}

};