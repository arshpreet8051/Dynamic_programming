#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &


// similar problem to 0/1 knapsack just one extra condition that a single value can be taken any number of times
// 2 changes to make:
//                  -> in case of take donot change index i.e. n
//                  -> in case of 0 index if ( w % wt[n] ) then we can take ( w / wt[n] * value[n] ) coz unlimited supply

class Recursion{

int solve(int n,int w,vector<int>&val,vector<int>&wt){

    // base case
    if(w==0){return 0;}
    if(n==0){
        if(w%wt[n]==0)return w/wt[n]*val[n]; // game
        return -1e9;
    }

    if(w<0 or n<0){return -1e9;}

    int not_take = solve(n-1,w,val,wt);
    int take = INT_MIN;

    if(w>=wt[n])take = val[n] + solve(n,w-wt[n],val,wt);

    return max(take,not_take);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    int ans = solve(n-1,w,profit,weight);
    return ans<=-1e9?0:ans;
}
};


// ------------------------------------------------------------------------------------------
// Memoization

class Memoization{

int solve(int n,int w,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){

    // base case
    if(w==0){return 0;}
    if(n==0){
        if(w%wt[n]==0)return w/wt[n]*val[n];
        return -1e9;
    }

    if(w<0 or n<0){return -1e9;}

    if(dp[n][w]!=-1)return dp[n][w];

    int not_take = solve(n-1,w,val,wt,dp);
    int take = INT_MIN;

    if(w>=wt[n])take = val[n] + solve(n,w-wt[n],val,wt,dp);

    return dp[n][w] = max(take,not_take);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    int ans = solve(n-1,w,profit,weight,dp);
    return ans<=-1e9?0:ans;
}
};

//---------------------------------------------------------------------------------------------------
// Tabulation

class Tabulation{
    
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    vector<vector<int>>dp(n,vector<int>(w+1,0));

    for(int wt = 0;wt<=w;wt++){
        if(wt%weight[0]==0)dp[0][wt] = (wt/weight[0])*profit[0];
    }

    for(int index = 1;index<n;index++){
        for(int wt = 0;wt<=w;wt++){
           
            int not_take = dp[index-1][wt];
            int take = INT_MIN;

            if(wt>=weight[index])take = profit[index] + dp[index][wt-weight[index]];

            dp[index][wt] = max(take,not_take);

        }
    }
    return dp[n-1][w];
}
};