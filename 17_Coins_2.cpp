// Similar to previous problem just unlimited supply of coins

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Recursion{
long solve(int *arr,int n,int val){

    if(val == 0){return 1;}

    if(n==0){
        if(val%arr[n]==0)return 1;
        return 0;
    }

    if(val<0 or n<0)return -1;

    long not_take = solve(arr,n-1,val);
    long take = 0;
    if(arr[n]<=val)take=solve(arr,n,val-arr[n]);
    return (take+not_take);

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    long ans = solve(denominations,n-1,value);
    return ans;
}
};

//--------------------------------------------------------------------------------------------------------

// Memoization

class Memoization{
long solve(int *arr,int n,int val,vector<vector<long>>&dp){

    if(val == 0){return 1;}

    if(n==0){
        if(val%arr[n]==0)return 1;
        return 0;
    }

    if(val<0 or n<0)return -1;

    if(dp[n][val]!=-1)return dp[n][val];

    long not_take = solve(arr,n-1,val,dp);
    long take = 0;
    if(arr[n]<=val)take=solve(arr,n,val-arr[n],dp);
    return dp[n][val] = (take+not_take);

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    long ans = solve(denominations,n-1,value,dp);
    return ans;
}
};

//-----------------------------------------------------------------------------------------------------------

class Tabulation{
    long countWaysToMakeChange(int *arr, int n, int value)
{
    //Write your code here

    vector<vector<long>>dp(n,vector<long>(value+1,0));

    for(int target = 0;target<=value;target++){
        if(target%arr[0]==0)dp[0][target] = 1;
    }


    for(int ind = 1;ind<n;ind++){
        for(int t = 0;t<=value;t++){

            long not_take = dp[ind-1][t];
            long take = 0;
            if(arr[ind]<=t)take=dp[ind][t-arr[ind]];
            dp[ind][t] = (take+not_take);
        }
    }

   return dp[n-1][value];
}
};