#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// This problem is based on variable starting points and variable ending points

// Recurrsive solution
class Recurrsion{
public:
int solve(int i,int j,int n,vector<vector<int>>&arr){

    if((i>n-1) or (j<0) or (j>n-1)){
        return -1;
    }
    else if((i==n-1)){ // all elements in last row are base
        return arr[i][j];
    }
    else{

        int down = INT_MIN;
        int down_left = INT_MIN;
        int down_right = INT_MIN;

        int got_down = solve(i+1,j,n,arr);
        int got_down_left = solve(i+1,j-1,n,arr);
        int got_down_right = solve(i+1,j+1,n,arr);

        if(got_down!=-1)down = arr[i][j] + got_down;
        if(got_down_left!=-1)down_left = arr[i][j] + got_down_left;
        if(got_down_right!=-1)down_right = arr[i][j] + got_down_right;

        return max(down,max(down_left,down_right));

    }

}
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        int ans = 0;
    for(int col = 0;col<n;col++){
        ans = max(ans,solve(0,col,n,matrix));
    }

    return ans;
    }
};

//----------------------------------------------------------------------------------------------------

// Memoization
// randomly taken -268 to pass testcases
class Memoization{ 
int solve(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp){

    if((i>n-1) or (j<0) or (j>m-1)){
        return -268;
    }
    else if(i==n-1){ // all elements in last row are base
        return arr[i][j];
    }
    else if(dp[i][j]!=-268){return dp[i][j];}
    else{

        int down = INT_MIN;
        int down_left = INT_MIN;
        int down_right = INT_MIN;

        int got_down = solve(i+1,j,n,m,arr,dp);
        int got_down_left = solve(i+1,j-1,n,m,arr,dp);
        int got_down_right = solve(i+1,j+1,n,m,arr,dp);

        if(got_down!=-268)down = arr[i][j] + got_down;
        if(got_down_left!=-268)down_left = arr[i][j] + got_down_left;
        if(got_down_right!=-268)down_right = arr[i][j] + got_down_right;

        return dp[i][j] = max(down,max(down_left,down_right));

    }

}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>>dp(n,vector<int>(m,-268));

    int ans = INT_MIN;
    for(int col = 0;col<m;col++){
        ans = max(ans,solve(0,col,n,m,matrix,dp));
    }

    return ans;
}
};

//-------------------------------------------------------------------------------------------------------------
// Tabulation

class Tabulation
{
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>>dp(n,vector<int>(m,0));

    // all the elements in last row will act as base cases

    for(int col = 0;col<m;col++){
        dp[n-1][col] = matrix[n-1][col];
    }


    for(int i = n-2;i>=0;i--){
        for(int j = 0;j<m;j++){
            
            int up = matrix[i][j] + dp[i+1][j];

            int up_left = INT_MIN;
            if(j-1>=0)up_left = matrix[i][j] + dp[i+1][j-1];

            int up_right = INT_MIN;
            if(j+1<m)up_right = matrix[i][j] + dp[i+1][j+1];

            dp[i][j] = max(up,max(up_left,up_right));
        }
    }


    int ans = INT_MIN;

    for(int col = 0;col<m;col++){
        ans = max(ans,dp[0][col]);
    }

    return ans;
}};
int main()
{


    return 0;
}