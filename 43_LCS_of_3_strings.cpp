#include<string>
using namespace std;

#define and &&
#define or ||

class Solution
{    int dp[105][105][105];

    int solve(string&a,string&b,string&c,int n,int m,int k){

        if(n==0 or m==0 or k==0)return 0;

        if(dp[n][m][k]!=-1)return dp[n][m][k];

        if(a[n-1]==b[m-1] and b[m-1] == c[k-1]){
            return dp[n][m][k] = 1 + solve(a,b,c,n-1,m-1,k-1);
        }

        else{

            int l = 0 + solve(a,b,c,n-1,m,k);
            int r = 0 + solve(a,b,c,n,m-1,k);
            int z = 0 + solve(a,b,c,n,m,k-1);

            return dp[n][m][k] = max({l,r,z});
        }
    }
    int LCS(string A, string B, string C, int n, int m, int k)
    {
        // Write your code here.
        memset(dp,-1,sizeof(dp));
        return solve(A,B,C,n,m,k);
    }};