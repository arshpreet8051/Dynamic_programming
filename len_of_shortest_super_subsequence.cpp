/*
    NOTE: Follow up question to LCS
                                    
                -> Supersubsequence is the shortest length string which all the words of parent strings in same order
                -> e.g -str1 = brute, str2 = groot, super-subsequence = bgruoote

                Logic:
                        -> find lengrth of lcs
                        -> find no of chars different from lcs in str1 - ans1
                        -> find no of chars different from lcs in str2 - ans2
                        -> return ans1 + ans2 + lcs_len
*/

#include<vector>
#include<string>
using namespace std;

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
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int lcs_len = lcs(X,Y);
        
        int ans1 = X.length()-lcs_len;
        int ans2 = Y.length()-lcs_len;
        
        return ans1 + ans2 + lcs_len;
    }
};
