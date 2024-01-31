/*
    Logic :
            Apply LIS from both sides and consider adding them and subtracting common point
*/

#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	   // LIS - Longest Increasing Subsequence Logic

	vector<int>dp1(n,1);
    for(int i = 0;i<n;i++){
        for(int prev = 0;prev<=i;prev++){

            if(arr[prev] < arr[i]){
                dp1[i] = max(dp1[i],1 + dp1[prev]);
            }
        }
    }

    vector<int>dp2(n,1);

    
    for(int i = n-1;i>=0;i--){
        for(int prev = n-1;prev>i;prev--){

            if(arr[prev] < arr[i]){
                dp2[i] = max(dp2[i],1 + dp2[prev]);
            }
        }
    }

	int maxi = 1;


	for(int i = 0 ;i<n;i++){
		maxi = max ( maxi , dp1[i] + dp2[i] - 1);

	}

	return maxi;

    
}
