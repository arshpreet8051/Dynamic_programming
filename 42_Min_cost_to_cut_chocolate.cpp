#include<iostream>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Recursion

class Recursion{
int solve(vector<int>&cuts,int i,int j){

    if(i>j)return 0;

    int mini = INT_MAX;

    for(int k = i;k<=j;k++){

        int ans = cuts[j+1] - cuts[i-1] + solve(cuts,i,k-1) + solve(cuts,k+1,j);

        mini = min(mini, ans);
    }

    return mini;

}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.

    cuts.push_back(n);
    cuts.push_back(0);
    
    // Sorting because we want to solve the cuts (subproblems independently);

    sort(cuts.begin(),cuts.end());

    return solve(cuts,1,c);

}
};

//----------------------------------------------------------------------------

// Memoization

class Memoization{
    int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){

    if(i>j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int mini = INT_MAX;

    for(int k = i;k<=j;k++){

        int ans = cuts[j+1] - cuts[i-1] + solve(cuts,i,k-1,dp) + solve(cuts,k+1,j,dp);

        mini = min(mini, ans);
    }

    return dp[i][j] = mini;

}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.

    cuts.push_back(n);
    cuts.push_back(0);
    
    // Sorting because we want to solve the cuts (subproblems independently);

    sort(cuts.begin(),cuts.end());

    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return solve(cuts,1,c,dp);

}
};

// Tabulation

class Tabulation{
    int cost(int n, int c, vector<int> &cuts){

    cuts.push_back(n);

    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

    for(int i=c; i>=1; i--){

        for(int j=1; j<=c; j++){

            if(i>j) continue;

            int mini=INT_MAX;

            for(int ind=i; ind<=j; ind++){

                int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];

                mini=min(mini, cost);

            }

            dp[i][j]=mini;

        }

    }

    return dp[1][c];

}
};