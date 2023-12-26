#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 


// Recurrsion
int solve(int row,int col,vector<vector<int>>&arr){

	if(row == 0 and col == 0){
		return arr[row][col];
	}

	else if(row<0 or col<0){
		return -1;
	}

	else{

		int up = INT_MAX;
		int left_up = INT_MAX;

		int got_up = solve(row-1,col,arr);
		int got_left_up = solve(row-1,col-1,arr);

		if(got_up!=-1)up = arr[row][col] + got_up;
		if(got_left_up!=-1) left_up = arr[row][col] + got_left_up;

		return min(up,left_up);

	}

}

//---------------------------------------------------------------------------------------------------

// Memoization
int solve(int i,int j,int n,vector<vector<int>>&arr,vector<vector<int>>&dp){

	if(i == n-1){
		return arr[i][j];
	}
	
	else if(i>=n or (j>i)){return -1;}

    else if(dp[i][j]!=-1){return dp[i][j];}
    
	else{
        
        int one = INT_MAX;
        int two = INT_MAX;
        
        int down = solve(i+1,j,n,arr,dp);
        int down_right = solve(i+1,j+1,n,arr,dp);
        
        if(down!=-1)one = arr[i][j] + down;
        if(down_right!=-1)two = arr[i][j] + down_right;
        
		return dp[i][j] = min(one,two);

	}
  }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        if(n==1){return triangle[0][0];}
        int row = triangle.size()-1;
	    int col = triangle[n-1].size()-1;
            
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        
    	return solve(0,0,n,triangle,dp);
    }

//---------------------------------------------------------------------------------------------------------

// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

	// variable base cases

	for(int col = 0;col<n;col++){
		dp[n-1][col] = triangle[n-1][col];
	}

	for(int i = n-2;i>=0;i--){
		for(int j = i;j>=0;j--){

			int d = triangle[i][j] + dp[i+1][j];
			int dg = triangle[i][j] + dp[i+1][j+1];

			dp[i][j] = min(d,dg);
		}
	}

	return dp[0][0];   
    }
};


int main()
{


    return 0;
}