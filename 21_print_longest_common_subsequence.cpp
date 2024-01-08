/*
    Follow up question to ;ength of longest common subsequence

    -> Find the longest common subsquence but first find lenght of it
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class solution{
     int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        // base case
        
        for(int i = 0;i<=n;i++)dp[i][0] = 0;
        for(int j = 0;j<=m;j++)dp[0][j] = 0;
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][m];
        
        int length = dp[n][m];
        
        string ans = "";
        
        for(int i = 0;i<length;i++){
            ans+='$';
        }
        
        int i = n;
        int j = m;
        int index = length-1;
        
        while(i>0 and j>0){
            
            if(s1[i-1]==s2[j-1]){
                ans[index] = s1[i-1];
                i--;
                j--;
                index--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        
        //return ans;
    }
};