/*
    Note: 
         - Similar Question to Buy and Sell Stocks IV
         - but limited transactions to K
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Recursion{

int solve(vector<int>&prices,int n,int k,int ind,int buy){

    if(ind == n)return 0;
    if(k == 0)return 0;

    // we donot hold a stock, we can buy it
    if(buy){
        int buy_it = -prices[ind] + solve(prices,n,k,ind+1,0);
        int not_buy = 0 + solve(prices,n,k,ind+1,1);

        return max(buy_it,not_buy);
        }

    // we are holding a stock
    else{
        int sell = prices[ind] + solve(prices,n,k-1,ind+1,1);
        int not_sell = 0 + solve(prices,n,k,ind+1,0);

        return max(sell,not_sell);
    }
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    return solve(prices,n,k,0,1);
}

};

//-----------------------------------------------------

// Memoization

class Memoization{ 

int solve(vector<int>&prices,int n,int k,int ind,int buy,vector<vector<vector<int>>>&dp){

    if(ind == n)return 0;
    if(k == 0)return 0;

    if(dp[ind][buy][k]!=-1)return dp[ind][buy][k];

    // we donot hold a stock, we can buy it
    if(buy){
        int buy_it = -prices[ind] + solve(prices,n,k,ind+1,0,dp);
        int not_buy = 0 + solve(prices,n,k,ind+1,1,dp);

        return dp[ind][buy][k] = max(buy_it,not_buy);
        }

    // we are holding a stock
    else{
        int sell = prices[ind] + solve(prices,n,k-1,ind+1,1,dp);
        int not_sell = 0 + solve(prices,n,k,ind+1,0,dp);

        return dp[ind][buy][k] = max(sell,not_sell);
    }
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return solve(prices,n,k,0,1,dp);
}

};


//------------------------------------------------------------------------------------

// Tabulation

class Tabulation{
    int maxProfit(vector<int>& arr,int K)
{   
    int n = arr.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(K+1,0)));

    // for bases cases the value is zero so no need to do it separately

    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){
            for(int k = 1;k<=K;k++){

                if(buy){

                    int buy_it = -arr[i] + dp[i+1][0][k];
                    int donot_buy = 0 + dp[i+1][1][k];

                    dp[i][buy][k] = max(buy_it,donot_buy);
                }

                // i cannot buy
                else{

                    int sell = INT_MIN;
                    if(k-1>=0)sell = arr[i] + dp[i+1][1][k-1];
                    int donot_sell = 0 + dp[i+1][0][k];

                    dp[i][buy][k] = max(sell,donot_sell);
                }

            }
        }
    }
    return dp[0][1][2];
}
};

//------------------------------------------------------------------------------

// Space Optimization

class SapceOptimization{
    int maxProfit(vector<int>& arr,int K)
{   
    int n = arr.size();
    vector<vector<int>>after(2,vector<int>(K+1,0));
    vector<vector<int>>curr(2,vector<int>(K+1,0));

    // for bases cases the value is zero so no need to do it separately

    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){
            for(int k = 1;k<=K;k++){

                if(buy){

                    int buy_it = -arr[i] + after[0][k];
                    int donot_buy = 0 + after[1][k];

                    curr[buy][k] = max(buy_it,donot_buy);
                }

                // i cannot buy
                else{

                    int sell = INT_MIN;
                    if(k-1>=0)sell = arr[i] + after[1][k-1];
                    int donot_sell = 0 + after[0][k];

                    curr[buy][k] = max(sell,donot_sell);
                }

            }
        }

        after = curr;
    }
    return after[1][2];
}
};