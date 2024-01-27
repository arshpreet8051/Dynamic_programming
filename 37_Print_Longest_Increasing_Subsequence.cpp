#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 

// Algorithm Tabulation Logic to get max length
class Tabulation{
    int longestIncreasingSubsequence(int arr[], int n)
{
    
    vector<int>dp(n,1);

    int maxi = 1;
    for(int i = 0;i<n;i++){
        for(int prev = 0;prev<=i;prev++){

            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i],1 + dp[prev]);
            }
        }

        maxi = max(maxi,dp[i]);
    }

    return maxi;
}
};

//---------------------------------------------------------------------------

// Printing LIS - using backtrack array

class Solution{
    
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {

    // Write Your Code here
	vector<int> ans;
    vector<int>dp(n,1),hash(n);

    int maxi = 1;
	int lastIndex = 0;

    for(int i = 0;i<n;i++){
		hash[i] = i;
        for(int prev = 0;prev<=i;prev++){

            if(arr[prev] < arr[i] and (1+dp[prev]) > dp[i]){
                
				dp[i] = 1 + dp[prev];
				hash[i] = prev;
            }
        }

		if(dp[i]>maxi){
			maxi = dp[i];
			lastIndex = i;
		}
    }

	ans.push_back(arr[lastIndex]);
	while(hash[lastIndex]!=lastIndex){
		lastIndex = hash[lastIndex];		
		ans.push_back(arr[lastIndex]);
	}

	reverse(ans.begin(),ans.end());
	return ans;
};

};