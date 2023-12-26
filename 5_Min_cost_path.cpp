#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &


// Recurrsion
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&grid){

        if(row == 0 and col ==0){
            return grid[row][col];
        }
        else if(row ==0 or col == 0){
            return -1;
        }
        else{

                int up = INT_MAX;
                int left = INT_MAX;

                int got_up = solve(row-1,col,grid);
                int got_left = solve(row,col-1,grid);

                if(got_up!=-1)up = grid[row][col] + got_up;
                if(got_left!=-1)left = grid[row][col] + got_left;

                return min(up,left);
                
            }


    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size()-1;
        int col = grid[0].size()-1;

        return solve(row,col,grid);

    }
};

//--------------------------------------------------------------------------------------------------------------

// Memoization
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){

        if(row == 0 and col ==0){
            return grid[row][col];
        }
        else if(row ==0 or col == 0){
            return -1;
        }

        else if(dp[row][col]!=-1){return dp[row][col];}
        else{

                int up = INT_MAX;
                int left = INT_MAX;

                int got_up = solve(row-1,col,grid,dp);
                int got_left = solve(row,col-1,grid,dp);

                if(got_up!=-1)up = grid[row][col] + got_up;
                if(got_left!=-1)left = grid[row][col] + got_left;

                return dp[row][col] = min(up,left);

            }


    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size()-1;
        int col = grid[0].size()-1;

        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        return solve(row,col,grid,dp);

    }
};

//--------------------------------------------------------------------------------------------------------------

// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size()-1;
        int col = grid[0].size()-1;

        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));

        dp[0][0] = grid[0][0];

        for(int i = 0;i<=row;i++){
            for(int j = 0;j<=col;j++){

                int up = INT_MAX;
                int left = INT_MAX;

                if(i==0 and j==0){continue;}
                if(i>0){up = grid[i][j] + dp[i-1][j];}
                if(j>0){left = grid[i][j] + dp[i][j-1];}

                dp[i][j] = min(up,left);
            }
        }

        return dp[row][col];
    }
};

int main()
{


    return 0;
}