#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class solution{
        
        int solve(vector<int>&prices)
        {
            int mini = INT_MAX;
            int profit = 0;

            for(int i = 0;i<prices.size();i++){

                if(prices[i]<mini)mini = prices[i];
                profit = max(profit,(prices[i]-mini));
            }

            return profit;}
};