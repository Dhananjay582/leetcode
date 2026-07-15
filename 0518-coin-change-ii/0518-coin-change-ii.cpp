class Solution {
public:
    int fn(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(i==0) {
            if(amount%coins[i] == 0) return 1;
            return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int skip = fn(i-1,amount,coins,dp);
        int take = 0;
        if(coins[i]<=amount) take = fn(i,amount-coins[i],coins,dp);
        return dp[i][amount] = skip+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return fn(n-1,amount,coins,dp);
    }
};