#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
/*  
    -> we need to find the length of longest palindromic substring
    -> The problem can be solved by the logic of Longest common Subsequence 
    -> just a follow up question to lcs
    -> only one step is different from tabulation solution of lcs
*/

class tabulation{
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i = 0;i<=n;i++)dp[i][0] = 0;
        for(int j = 0;j<=m;j++)dp[0][j] = 0;
        
        int ans = 0;
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
            
                if(S1[i-1]==S2[j-1]){
                    
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                    
                }
                else{
                    dp[i][j] = 0;  // -> The only line that is different from lcs
                }
            }    
        }
        
        return ans;
    }
};