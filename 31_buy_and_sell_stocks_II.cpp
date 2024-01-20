/*
    Note:
        You can make any number of transactions
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Recursion{
    long solve(long*arr,int n,int i,int buy){

    // base case
    if(i==n)return 0;


    // if i can buy
    if(buy){

        long buy_it = -arr[i] + solve(arr,n,i+1,0);
        long donot_buy = 0 + solve(arr,n,i+1,1);

        return max(buy_it,donot_buy);
    }

    // i cannot buy
    else{

        long sell = arr[i] + solve(arr,n,i+1,1);
        long donot_sell = 0 + solve(arr,n,i+1,0);

        return max(sell,donot_sell);
    }


}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    return solve(values,n,0,1);
}
};

//-------------------------------------------------------------------------------------------------

// Memoization
class Memoization{
    #include<vector>
long solve(long*arr,int n,int i,int buy,vector<vector<long>>&dp){

    // base case
    if(i==n)return 0;

    if(dp[i][buy]!=-1)return dp[i][buy];

    // if i can buy
    if(buy){

        long buy_it = -arr[i] + solve(arr,n,i+1,0,dp);
        long donot_buy = 0 + solve(arr,n,i+1,1,dp);

        return dp[i][buy] = max(buy_it,donot_buy);
    }

    // i cannot buy
    else{

        long sell = arr[i] + solve(arr,n,i+1,1,dp);
        long donot_sell = 0 + solve(arr,n,i+1,0,dp);

        return dp[i][buy] = max(sell,donot_sell);
    }


}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>>dp(n,vector<long>(2,-1));
    return solve(values,n,0,1,dp);
}
};
//---------------------------------------------------------------------------------------------

// Tabulization

class Tabulization{
    long getMaximumProfit(long *arr, int n)
{
    //Write your code here
    vector<vector<long>>dp(n+1,vector<long>(2,0));

    dp[n][0] = 0;
    dp[n][1] = 0;

   
    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){
            if(buy){

                        long buy_it = -arr[i] + dp[i+1][0];
                        long donot_buy = 0 + dp[i+1][1];

                        dp[i][buy] = max(buy_it,donot_buy);
                    }

                    // i cannot buy
                    else{

                        long sell = arr[i] + dp[i+1][1];
                        long donot_sell = 0 + dp[i+1][0];

                        dp[i][buy] = max(sell,donot_sell);
                    }
        }
    }
    
        return dp[0][1];
}
};

//----------------------------------------------------------------------------

// Space Optimization

class SpaceOptimization{
    long getMaximumProfit(long *arr, int n)
{
    //Write your code here
    vector<long>ahead(2,0);
    vector<long>curr(2,0);

   
    for(int i = n-1;i>=0;i--){
        for(int buy = 0;buy<=1;buy++){
            if(buy){

                        long buy_it = -arr[i] + ahead[0];
                        long donot_buy = 0 + ahead[1];

                        curr[buy] = max(buy_it,donot_buy);
                    }

                    // i cannot buy
                    else{

                        long sell = arr[i] +ahead[1];
                        long donot_sell = 0 + ahead[0];

                        curr[buy] = max(sell,donot_sell);
                    }
        }

        ahead = curr;
    }
    
        return ahead[1];
}
};