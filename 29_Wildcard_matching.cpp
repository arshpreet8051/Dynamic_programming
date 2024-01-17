#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Recursion

class Recursion{
    bool solve(string&str1,int i,string&str2,int j){

   // base cases

   // case - 1
   if(i<0 and j<0)return true;

   // case - 2
   if(i<0 and j>=0)return false;

   // case - 3
   if(j<0 and i>=0){
      for(int x = 0;x<=i;x++){
         if(str1[x]!='*')return false;
      }
      return true;
   }


   // match
   if(str1[i]==str2[j] or str1[i]=='?'){
      return solve(str1,i-1,str2,j-1);
   }

   // no match but star
   if(str1[i]=='*'){

      // one time star will consume char (j-1) and one time we will star as of length of zero (i-1)
      return (solve(str1,i-1,str2,j) or solve(str1,i,str2,j-1));
   }

   // no match
   return false;

}

bool wildcardMatching(string pattern, string text)
{
   int i = pattern.length();
   int j = text.length();

   return solve(pattern,i-1,text,j-1);
}

};


//---------------------------------------------------------------------------------------------------------

class Memoization{
    #include<vector>
bool solve(string&str1,int i,string&str2,int j,vector<vector<int>>&dp){

   // base cases

   // case - 1
   if(i==0 and j==0)return true;

   // case - 2
   if(i==0 and j>0)return false;

   // case - 3
   if(j==0 and i>0){
      for(int x = 0;x<i;x++){
         if(str1[x]!='*')return false;
      }
      return true;
   }

   if(dp[i][j]!=-1)return dp[i][j];

   // match
   if(str1[i-1]==str2[j-1] or str1[i-1]=='?'){
      return dp[i][j] = solve(str1,i-1,str2,j-1,dp);
   }

   // no match but star
   if(str1[i-1]=='*'){

      // one time star will consume char (j-1) and one time we will star as of length of zero (i-1)
      return dp[i][j] = (solve(str1,i-1,str2,j,dp) or solve(str1,i,str2,j-1,dp));
   }

   // no match
   return dp[i][j] = false;

}

bool wildcardMatching(string pattern, string text)
{
   int i = pattern.length();
   int j = text.length();

   vector<vector<int>>dp(i+1,vector<int>(j+1,-1));

   return solve(pattern,i,text,j,dp);
}

};

//--------------------------------------------------------------------------------------------

class Tabulation{
    bool wildcardMatching(string str1, string str2)
{
   int m = str1.length();
   int n = str2.length();

   vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));

   dp[0][0] = true;

   for(int j = 0;j<=n;j++)dp[0][j] = false;

   for(int i = 0;i<=m;i++){

      bool flag = true;

      for(int x = 0;x<i;x++){
         if(str1[x]!='*'){
            flag = false;
            break;
            }
      }

      dp[i][0] = flag;
   }

   for(int i = 1;i<=m;i++){
      for(int j = 1;j<=n;j++){

         if(str1[i-1]==str2[j-1] or str1[i-1]=='?'){
             dp[i][j] = dp[i-1][j-1];
         }

         // no match but star
         else if(str1[i-1]=='*'){

            // one time star will consume char (j-1) and one time we will star as of length of zero (i-1)
            dp[i][j] = (dp[i-1][j] or dp[i][j-1]);
         }

         // no match
         else{dp[i][j] = false;}
      }
   }

   return dp[m][n];
}

};