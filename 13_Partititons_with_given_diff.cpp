// partition an array in two subsets
// conditions -> S1 >= S2  and S1 - S2 = D
// let S1 = total - S2
// : total - S2 - S2 = D
// S2 = (total - d) / 2
// The problem boils down to subsets with target sum = (total-d)/2

// make sure 2 conditions
// (total-d)>0 and total-d is even


#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Memoization Solution

class solution{
int mod = 1e9+7;

int solve(vector<int>&arr,int n,int sum,int ind,vector<vector<int>>&dp){

    // basr case
    if(ind == n-1){
        if(sum==0 and arr[n-1]==0){return 2;}
        if(sum==0 or sum == arr[n-1]){return 1;}
        return 0;
    }

    if(ind>n-1 or sum<0)return 0;

    if(dp[ind][sum]!=-1){return dp[ind][sum];}

    int not_take = solve(arr,n,sum,ind+1,dp);
    int take = 0;
    if(sum>=arr[ind])take = solve(arr,n,sum-arr[ind],ind+1,dp);

    return dp[ind][sum] = (take+not_take)%mod;
}

int count_subsets_with_sum(vector<int>&arr,int sum){

    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    return solve(arr,n,sum,0,dp);

}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int total = 0;
    for(auto x : arr){
        total+=x;
    }

    // Logic
    if ((total-d>0) and ((total-d)%2==0)) {
        int new_sum = (total-d)/2;
        return count_subsets_with_sum(arr, new_sum);
    }

    return 0;
}



};

