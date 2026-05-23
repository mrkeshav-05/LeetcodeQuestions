class Solution {
public:
    int fun(vector<int> &coins, int amt, int idx, vector<vector<int>> &dp){
        if(idx < 0){
            if(amt == 0) return 1;
            return 0;
        }
        if (dp[idx][amt] != -1) {
            return dp[idx][amt];
        }
        int take = 0;
        if(amt >= coins[idx]){
            take = fun(coins, amt-coins[idx], idx, dp);
        }
        int nottake = fun(coins, amt, idx-1, dp);

        return dp[idx][amt] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return fun(coins, amount, n-1, dp);
    }
};
