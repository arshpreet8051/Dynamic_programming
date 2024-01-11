#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Recursion{
    
int solve(string &str1,string &str2,int i,int j){

    if(j<0)return 1;
    if(i<0)return 0;
    
    if(str1[i]==str2[j]){
        return solve(str1,str2,i-1,j) + solve(str1,str2,i-1,j-1);
    }
    else{
        return  solve(str1,str2,i-1,j);
    }

}
int numDistinct(string S, string T) {
    int i = S.length()-1;
    int j = T.length()-1;

    return solve(S,T,i,j);
}
};


//------------------------------------------------------------------------------------------------

class Tabulation{

    
int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){

    if(j<0)return 1;
    if(i<0)return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];

    if(str1[i]==str2[j]){
        return dp[i][j] =  solve(str1,str2,i-1,j,dp) + solve(str1,str2,i-1,j-1,dp);
    }
    else{
        return dp[i][j] = solve(str1,str2,i-1,j,dp);
    }

}
int numDistinct(string S, string T) {
    // Write your code here
    int i = S.length()-1;
    int j = T.length()-1;

    vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
    return solve(S,T,i,j,dp);
}
};