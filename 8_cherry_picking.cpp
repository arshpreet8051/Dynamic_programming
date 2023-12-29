#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

// recursion

class recursion{
int solve(int j1,int j2,int i,int c,int r,vector<vector<int>>&grid){

    if((j1>c-1) or (j1<0) or (j2<0) or (j2>c-1)){
        return -1e8;
    }

    else if(i==r-1){

        if(j1==j2){return grid[i][j1];}
        return (grid[i][j1] + grid[i][j2]);
    }
    else{

        int maxi = INT_MIN;
        for(int x = -1;x<=1;x++){
            for(int y = -1;y<=1;y++){
                if(j1!=j2){maxi = max(maxi,grid[i][j1] + grid[i][j2] + solve(j1+x,j2+y,i+1,c,r,grid));}
                else{maxi = max(maxi,grid[i][j1] + solve(j1+x,j2+y,i+1,c,r,grid));}
            }
        }

        return maxi;

    }

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    return solve(0,c-1,0,c,r,grid);
}
};


//----------------------------------------------------------------------------------------------------------------

// Memoization

class Memoization{
public:
    int solve(int j1,int j2,int i,int r,int c,vector<vector<int>>&arr,vector<vector<vector<int>>>&dp){
            
        if((j1<0) or (j2<0) or (j1>c-1) or (j2>c-1)){
            return -1e8;
        }
        else if(i==r-1){
            
            if(j1==j2){return arr[i][j1];}
            return arr[i][j1] + arr[i][j2];
        }
        
        else if(dp[i][j1][j2]!=-1){return dp[i][j1][j2];}
        else{
            
            int maxi = INT_MIN;
            
            for(int x = -1;x<=1;x++){
                for(int y = -1;y<=1;y++){
                    
                    if(j1==j2){maxi = max(maxi,arr[i][j1]+solve(j1+x,j2+y,i+1,r,c,arr,dp));}
                    else{maxi = max(maxi,arr[i][j1] + arr[i][j2] + solve(j1+x,j2+y,i+1,r,c,arr,dp));}
                }
            }
            return dp[i][j1][j2] = maxi;
            
        }
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,m-1,0,n,m,grid,dp);
    }
};

//---------------------------------------------------------------------------------------------------------

// Tabulation

class Tabulation{
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

    for(int j1 = 0;j1<c;j1++){
        for(int j2 = 0;j2<c;j2++){
            dp[r-1][j1][j2] = (j1==j2) ? grid[r-1][j1] : grid[r-1][j1] + grid[r-1][j2]; 
        }
    }

    for(int i = r-2;i>=0;i--){
        for(int j1 = 0;j1<c;j1++){
            for(int j2 = 0;j2<c;j2++){
                int maxi = -1e8;
                for(int x = -1;x<=1;x++){
                for(int y = -1;y<=1;y++){
                if(j1!=j2){
                    
                    if(j1+x<c and j1+x>=0 and j2+y<c and j2+y>=0)maxi = max(maxi,grid[i][j1] + grid[i][j2] + dp[i+1][j1+x][j2+y]);}
                else{
                    if(j1+x<c and j1+x>=0 and j2+y<c and j2+y>=0)maxi = max(maxi, grid[i][j1] + dp[i+1][j1+x][j2+y]);}
                }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c-1];
}
};

int main()
{


    return 0;
}