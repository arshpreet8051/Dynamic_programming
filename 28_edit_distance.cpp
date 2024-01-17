/*
    Question -> 
                - Make string s1 to s2
                - Allowed operations
                                    - Insert
                                    - Delete
                                    - Replace
*/

/*
    Logic -> String matching
        
    2 cases -> Match and No-match
                                
        1) if match -> do nothing move to next char

        2) If donot match

            - choice 1 -> insert(hypothetical) str1 ind remains same and str2 ind reducese by 1
            - choice 2 -> delete - ind of str1 moves by 1 str2 ind remains same
            - choice 3 -> replace - both indexes reduces by one
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 


// Recursion

class Recursion{
    int solve(string& str1,int i,string&str2,int j){
        
        // base case
        
        // s exhausted -> we need j+1 insertions
        if(i<0){
            return j+1;
        }
        
        // t exhausted -> we need i+1 deletions
        if(j<0){
            return i+1;
        }
    
        
        // casses of match and not match
        
        // match
        if(str1[i]==str2[j]){
            
            // move to nex char -> do nothing
            return 0 + solve(str1,i-1,str2,j-1);
        }
        
        // no match -> choices
        
        // choice 1
        int insert = 1 + solve(str1,i,str2,j-1);
        
        // choice 2
        int del = 1 + solve(str1,i-1,str2,j);
        
        // choice 3
        int replace = 1 + solve(str1,i-1,str2,j-1);
        
        return min(insert,min(del,replace));
        
    }
    int editDistance(string s, string t) {
        
        int m = s.length();
        int n = t.length();
        
        return solve(s,m-1,t,n-1);
    }
};

//------------------------------------------------------------------------------

// Memoization

class Memoization{
    int solve(string& str1,int i,string&str2,int j,vector<vector<int>>&dp){
        
        // base case
        
        // s exhausted -> we need j+1 insertions
        if(i<0){
            return j+1;
        }
        
        // t exhausted -> we need i+1 deletions
        if(j<0){
            return i+1;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        // casses of match and not match
        
        // match
        if(str1[i]==str2[j]){
            
            // move to nex char -> do nothing
            return 0 + solve(str1,i-1,str2,j-1,dp);
        }
        
        // no match -> choices
        
        // choice 1
        int insert = 1 + solve(str1,i,str2,j-1,dp);
        
        // choice 2
        int del = 1 + solve(str1,i-1,str2,j,dp);
        
        // choice 3
        int replace = 1 + solve(str1,i-1,str2,j-1,dp);
        
        return dp[i][j] = min(insert,min(del,replace));
        
    }
    int editDistance(string s, string t) {
        
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(s,m-1,t,n-1,dp);
    }
};


// -----------------------------------------------------------------------------------------------

// Tabulation

class Tabulation{
        int editDistance(string s, string t) {
        
        int m = s.length();
        int n = t.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        // base case
        for(int i = 0;i<=m;i++)dp[i][0] = i;
        for(int j = 0;j<=n;j++)dp[0][j] = j;
        
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                
                 if(s[i-1]==t[j-1]){
            
                // move to nex char -> do nothing
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            
                else{// no match -> choices
                
                // choice 1
                int insert = 1 + dp[i][j-1];
                
                // choice 2
                int del = 1 + dp[i-1][j];
                
                // choice 3
                int replace = 1 + dp[i-1][j-1];
                
                dp[i][j] = min(insert,min(del,replace));}
                    
                }
            }
        
        return dp[m][n];
    }
};