#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define or |
#define and &
 
bool check(string& str1,string& str2){

    if(str1.size() != str2.size()+1){return false;}

    int first = 0;
    int second = 0;

    while(first!=str1.size()){

        if(str1[first] == str2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }

    if(first == str1.size() and second == str2.size())return true;
    return false;
}

bool comp(string&str1,string &str2){
    return (str1.size() < str2.size());
}
int longestStrChain(vector<string> &arr){
    // Write your code here.

    // sorting because they are asking about "sequence" and not "subsequence"
    std::sort(arr.begin(),arr.end(),comp);
    int n = arr.size();
    int maxi = 1;
    vector<int> dp(n,1);

    for(int i=0;i<n;i++){

        for(int prev = 0;prev<i;prev++){

            if(check(arr[i],arr[prev]) and 1+dp[prev]>dp[i]){
                dp[i] = 1 + dp[prev];
            }

            maxi = max(maxi,dp[i]);
        }
    }

    return maxi;
}