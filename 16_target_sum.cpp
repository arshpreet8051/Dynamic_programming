
/*
    Question:
            You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. 
            Your task is to build an expression out of an array by adding one of the 
            symbols '+' and '-' before each integer in an array, and then by concatenating
            all the integers, you want to achieve a target. 
            You have to return the number of ways the target can be achieved.
*/
/*
    Note:
            -> let subset one has sum S1 and subset two has sum S2
            -> Subset one will have all numbers with positive sign
            -> Subset two will have all numbers with negative sign
            -> Let S1 - S2 = target
            -> Let S1 = Total - S2
            -> Total - S2 - S2 = target
            -> S2 = Total - target / 2
            -> this problem boils down to no of subsets with sum k
*/

#include<iostream>
#include<vector>
using namespace std;
#define or |
#define and &

class Recursion{
int subsets_with_sum_k(int n,vector<int>&arr,int k){

   // if(k==0)return 1;

    if(n==0){
        if(k==0 and arr[0]==0){return 2;}
        if(k==0 or arr[0]==k){return 1;}
        return 0;
    }

    if(k<0 or n<0){return -1;}

    int not_take = subsets_with_sum_k(n-1, arr, k);
    int take = 0;
    int t = subsets_with_sum_k(n-1, arr, k-arr[n]);

    if(t!=-1)take = t;

    return take+not_take;
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.

    int total = 0;

    for(auto x : arr){
        total+=x;
    }

    // s1 - s2 = target
    // total - s2 - s2 = target
    // total - target / 2 = s2
    // the problem boils down no of subsets with sum k

    if((total-target)%2 or (total-target<0))return 0;

    int new_target = (total-target)/2;

    int ans = subsets_with_sum_k(n-1,arr,new_target);

    return ans>=0 ? ans : 0;
}

};
 
