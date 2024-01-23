/*
    Note:
        - Similar Question to Buy and sell stocks II - but transactions are limited
        - if not buyed yet - 2 options - buy or not
        - if buyed and holding a stock - 2 options - sell or not
        - keep a variable to check no of transactioins
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 

 // Recursion
 //-----------------------------------------------------------------------------------
class Recursion{
    int solve(vector<int>&arr,int n,int i,int buy,int k){

    // base case
    if(k==0)return 0;
    if(i==n)return 0;


    // if i can buy
    if(buy){

        int buy_it = -arr[i] + solve(arr,n,i+1,0,k);
        int donot_buy = 0 + solve(arr,n,i+1,1,k);

        return max(buy_it,donot_buy);
    }

    // i cannot buy
    else{

        int sell = INT_MIN;
        if(k-1>=0)sell = arr[i] + solve(arr,n,i+1,1,k-1);
        int donot_sell = 0 + solve(arr,n,i+1,0,k);

        return max(sell,donot_sell);
    }


}
int maxProfit(vector<int>& prices)
{
    return solve(prices,prices.size(),0,1,2);
}
};
//--------------------------------------------------------------------------------

// Memoization

// Note for memo - there will be a 3D vector

class Memoization{
    #include<vector>
int solve(vector<int>&arr,int n,int i,int buy,int k,vector<vector<vector<int>>>&dp){

    // base case
    if(k==0)return 0;
    if(i==n)return 0;

    if(dp[i][buy][k]!=-1)return dp[i][buy][k];

    // if i can buy
    if(buy){

        int buy_it = -arr[i] + solve(arr,n,i+1,0,k,dp);
        int donot_buy = 0 + solve(arr,n,i+1,1,k,dp);

        return dp[i][buy][k] = max(buy_it,donot_buy);
    }

    // i cannot buy
    else{

        int sell = INT_MIN;
        if(k-1>=0)sell = arr[i] + solve(arr,n,i+1,1,k-1,dp);
        int donot_sell = 0 + solve(arr,n,i+1,0,k,dp);

        return dp[i][buy][k] = max(sell,donot_sell);
    }


}
int maxProfit(vector<int>& prices)
{   
    int n = prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

    return solve(prices,prices.size(),0,1,2,dp);
}
};

//------------------------------------------------------------------------------------

// Tabulation

class Tabulation{
    int maxProfit(vector<int>& arr)
{   
    int n = arr.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    // for bases cases the value is zero so no need to do it separately

    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){
            for(int k = 1;k<=2;k++){

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
    int maxProfit(vector<int>& arr)
{   
    int n = arr.size();
    vector<vector<int>>after(2,vector<int>(3,0));
    vector<vector<int>>curr(2,vector<int>(3,0));

    // for bases cases the value is zero so no need to do it separately

    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){
            for(int k = 1;k<=2;k++){

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