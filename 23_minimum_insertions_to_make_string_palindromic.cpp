#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
/*
    -> This problem can be solved using the logic of longest palindromic string

    steps:
            -> find length of longest palindromic substring using the logic of longest common subsequence (lcs)
            -> ans = total string length - length of longest palindromic substring
*/

class Tabulation{
    
    int lcs(string&s1,string&s2){

	int n = s1.length();
	int m = s2.length();

	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

	for(int i = 0;i<=n;i++)dp[i][0] = 0;
	for(int j = 0;j<=m;j++)dp[0][j] = 0;

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(s1[i-1]==s2[j-1])dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

	return dp[n][m];
}

int minimumInsertions(string &str)
{
	/*
		logic :
				1) find longest palindromic subsequence using longest common subsequence
				2) ans = string length - length of longest palindromic subsequence
	*/

	string s1 = str;
	reverse(str.begin(),str.end());
	string s2 = str;

	int length_of_longest_palindromic_subsequence = lcs(s1,s2);

	return (str.length() - length_of_longest_palindromic_subsequence);
}

};