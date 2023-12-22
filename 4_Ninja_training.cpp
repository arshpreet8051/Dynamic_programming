#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 

// 1 -> Recurrsion
int solve1(int last,int day,int n,vector<vector<int>>&arr){

    // base case ->we are on the last day
    if(day==n-1){
        int maxi = 0;
        for(int i = 0;i<=2;i++){
            if(i!=last){
                maxi = max(maxi,arr[day][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for(int i = 0;i<=2;i++){
        if(i!=last){
            maxi = max(maxi,arr[day][i] + solve1(i,day+1,n,arr));
        }
    }

    return maxi;
}   

int max_points_for_ninja_training(int n,vector<vector<int>>&points){
    int day = 0;
    int last = 3;

    return solve1(last,day,n,points);
}

//---------------------------------------------------------------------------------------------------------------

// 2 -> Memoization
int solve2(int last,int day,int n,vector<vector<int>>&arr,vector<vector<int>>&dp){

    // base case ->we are on the last day
    if(day==n-1){
        int maxi = 0;
        for(int i = 0;i<=2;i++){
            if(i!=last){
                maxi = max(maxi,arr[day][i]);
            }
        }
        return maxi;
    }

    if(dp[day][last]!=-1){return dp[day][last];}

    int maxi = 0;
    for(int i = 0;i<=2;i++){
        if(i!=last){
            maxi = max(maxi,arr[day][i] + solve2(i,day+1,n,arr,dp));
        }
    }

    return dp[day][last] = maxi;
}   

int max_points_for_ninja_training2(int n,vector<vector<int>>&points){
    int day = 0;
    int last = 3;
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve2(last,day,n,points,dp);
}

//----------------------------------------------------------------------------------------------------------------

// 3 -> Tabulation
int max_points_for_ninja_training3(int n,vector<vector<int>>&points){
    int day = 0;
    int last = 3;
    vector<vector<int>>dp(n,vector<int>(4,-1));
    

    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][2],points[0][1]));
    

    for(int day = 1;day<n;day++){

        for(int last = 0;last<=3;last++){

            for(int task = 0;task<=2;task++){

                if(task!=last){
                    dp[day][last] = max(dp[day][last],points[day][task] + dp[day-1][task]);
                }

            }
        }
    }

    return dp[n-1][3];

}

int main()
{


    return 0;
}