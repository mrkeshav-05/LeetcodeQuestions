class Solution {
public:
    int fun(vector<int> &coins, int amt, int idx, vector<vector<int>> &dp){
        if(amt == 0) return 0;
        if(idx < 0 || amt < 0) return 1e9;

        if (dp[idx][amt] != -1) {
            return dp[idx][amt];
        }
        int nottake = fun(coins, amt, idx-1, dp);
        
        // Choice 2: Take the current coin (we stay at 'idx' so we can reuse it)
        int take = 1e9;
        if(amt >= coins[idx]){
            take = 1 + fun(coins, amt - coins[idx], idx, dp);
        }
        
        // Save the minimum step to the DP matrix
        return dp[idx][amt] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
    vector<int> valid_coins;
    for(int coin : coins) {
        if(coin <= amount) {
            valid_coins.push_back(coin);
        }
    }
    
    int n = valid_coins.size();
    if (amount == 0) return 0;
    if (n == 0) return -1; // No valid coins available

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = fun(valid_coins, amount, n-1, dp);
    
    return (ans >= 1e9) ? -1 : ans;
}
};
