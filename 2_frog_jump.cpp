#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
/*  Problem:
            -A frog can jump either 1 or 2
            -Cost between 2 steps abs(cost[i] - cost[i+1])
            -calculate min cost to reach end
*/

/*  Recurrence relation : 
                            f( 1_step ) = abs(cost(current)-cost(current+1) + f(n-1)
                            f( 2_step ) = abs(cost(current)-cost[current+2]) + f(n-2)
                            ans = min(f(1_step),f(2_step))
                            */

// Solution - 1 (Recurrsion)
int solve(int i,vector<int>&h){
    if(i==0){return 0;}
    else if(i==1){
        return abs(h[0]-h[1]);
    }

    int left = abs(h[i]-h[i-1]) + solve(i-1,h);
    int right = abs(h[i]-h[i-2]) + solve(i-2,h);

    return min(left,right);

}
int frogJump_1(int n, vector<int> &heights)
{
    // Write your code here.
    return solve(n-1,heights);
}


// Solution - 2 (Top Down)
int solve_2(int i,vector<int>&h,vector<int>&dp){
    
    if(i==0){return dp[0];}
    else if(i==1){
        return dp[1];
    }

    if(dp[i]!=-1){return dp[i];}

    int left = abs(h[i]-h[i-1]) + solve(i-1,h);
    int right = abs(h[i]-h[i-2]) + solve(i-2,h);

    return dp[i] = min(left,right);

}
int frogJump_2(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);
    dp[0] = 0;
    dp[1] = abs(heights[0]-heights[1]);
    return solve_2(n-1,heights,dp);
}


// Solution - 3 (Bottom up)
int frogJump_3(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1);

    dp[0] = 0;
    if(n==0){return dp[0];}
    
    dp[1] = abs(dp[0]-dp[1]);
    if(n==1){return dp[1];}

    for(int i=2;i<n;i++){
        int left = abs(heights[i]-heights[i-1]) + dp[i-1];
        int right = abs(heights[i]-heights[i-2]) + dp[i-2];
        dp[i] = min(left,right);
    }

    return dp[n-1];
}