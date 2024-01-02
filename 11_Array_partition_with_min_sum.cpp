#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Follow-up question for " Subset Sum K "

class Tabulation{

    int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int sum = 0;

	for(int x:arr){
		sum+=x;
	}

	vector<vector<bool>>dp(n,vector<bool>(sum+1,false));

	for(int ind = 0;ind<n;ind++){
		dp[ind][0] = true; // base case for every ind when target is zero
	}

	dp[0][arr[0]] = true; // special base case when ind = 0 and target==arr[0];

	for(int ind = 1;ind<n;ind++){
		for(int target = 0;target<=sum;target++){

			bool not_take = dp[ind-1][target];

			bool take = false;
			if(arr[ind]<=target)take = dp[ind-1][target-arr[ind]];

			dp[ind][target] = (take | not_take);
		}

	}

	int min_diff = INT_MAX;

	for(int target = 0;target<=sum/2;target++){

		if(dp[n-1][target]){
			int s1 = target;
			int s2 = sum-target;

			min_diff = min(min_diff,abs(s2-s1));
		}
	}

	return min_diff;

}
};


int main()
{


    return 0;
}