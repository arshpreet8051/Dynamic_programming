#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
/*
    Follow up question to LCS
                                -> find length of longest common subsequence
                                -> ans1 = str1.length() - length of LCS
                                -> ans2 = str2.length() - length of LCS
                                -> return ans1 + ans2
*/


class Tabulation{
    int lcs(string & s, string & t) {
  // Write your code here.
  int n = s.length();
	int m = t.length();

	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

	for(int i = 0;i<=n;i++)dp[i][0] = 0;
	for(int j = 0;j<=m;j++)dp[0][j] = 0;

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(s[i-1]==t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

	return dp[n][m];
}
int canYouMake(string &s1, string &s2){
    // Write your code here.
    int length_of_longest_common_subsequence = lcs(s1,s2);

    int ans1 = s1.length()-length_of_longest_common_subsequence;
    int ans2 = s2.length()-length_of_longest_common_subsequence;

    return ans1+ans2;
    
}
};