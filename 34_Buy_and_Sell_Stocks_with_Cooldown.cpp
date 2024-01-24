#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Recursion{
int solve(vector<int>&arr,int n,int ind,int buy){

    if(ind >= n)return 0;

    if(buy==1){

        int buy_it = -arr[ind] + solve(arr,n,ind+1,0);
        int not_buy = 0 + solve(arr,n,ind+1,1);

        return max(buy_it,not_buy);

    }

    else{   

        int sell = arr[ind] + solve(arr,n,ind+2,1);
        int not_sell = 0 + solve(arr,n,ind+1,0);

        return max(sell,not_sell);
    }

}

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int ind = 0;

    return solve(prices,n,ind,1);
}
};

//---------------------------------------------------------

// Memoization
class Memoization{
    int f(vector<int> & prices,int n,int ind,int buy,vector<vector<int>> & dp){

    if(ind>=n) return 0;

    if(dp[ind][buy]!=-1) return dp[ind][buy];

    if(buy){

       return dp[ind][buy]= max(-prices[ind]+f(prices,n,ind+1,0,dp),f(prices,n,ind+1,1,dp));

       

    }

    else{

        return dp[ind][buy]= max(prices[ind]+f(prices,n,ind+2,1,dp),f(prices,n,ind+1,0,dp));

    }

}

int stockProfit(vector<int> &prices){

    // Write your code here.

    int n=prices.size();

    vector<vector<int>> dp(n,vector<int>(2,-1));

    return f(prices,n,0,1,dp);

}
};

//-------------------------------------------------------------------

class Tabulation{

    
int stockProfit(vector<int> &prices){

    // Write your code here.

    int n=prices.size();

    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int ind = n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            if(buy){

            dp[ind][buy]= max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            }

            else{

                 dp[ind][buy]= max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);

            }
        }
    }
    return dp[0][1];

}
};