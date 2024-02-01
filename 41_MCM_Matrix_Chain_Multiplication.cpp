/*

        New Pattern for dp -> Partition Set


        -Code dekn ch bahut soka pr Logic bnana aukha
        -Matrix multiplication rules should be known
        -Complete Logic in notebook
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Recursion

class Recursion{
int solve(vector<int>&arr,int i, int j){

    if(i==j)return 0;

    int mini = 1e9;
    for(int k = i;k<j;k++){

        int steps = arr[i-1]*arr[k]*arr[j] + solve(arr,i,k) + solve(arr,k+1,j);

        mini = min(steps,mini);

    }

    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    
    int i = 1;
    int j = N-1;

    return solve(arr,i,j);
}
};

//---------------------------------------------------------------------------

// Memoization

class Memoization{

int solve(vector<int>&arr,int i, int j,vector<vector<int>>&dp){

    if(i==j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int mini = 1e9;
    for(int k = i;k<j;k++){

        int steps = arr[i-1]*arr[k]*arr[j] + solve(arr,i,k,dp) + solve(arr,k+1,j,dp);

        mini = min(steps,mini);

    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{

    vector<vector<int>>dp(N,vector<int>(N,-1));
    int i = 1;
    int j = N-1;

    return solve(arr,i,j,dp);
}
};

//--------------------------------------------------------------------------

// Tabulation

class Tabulation{
    
int solve(vector<int>&arr,int i, int j,vector<vector<int>>&dp){

    if(i==j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int mini = 1e9;
    for(int k = i;k<j;k++){

        int steps = arr[i-1]*arr[k]*arr[j] + solve(arr,i,k,dp) + solve(arr,k+1,j,dp);

        mini = min(steps,mini);

    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.

    vector<vector<int>>dp(N,vector<int>(N,0));

    for(int i = N-1;i>0;i--){

        for(int j = i+1;j<N;j++){

            int mini = 1e9;
            for(int k = i;k<j;k++){

                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];

                mini = min(steps,mini);

            }

            dp[i][j] = mini;

        }
    }
    
    return dp[1][N-1];
}
};