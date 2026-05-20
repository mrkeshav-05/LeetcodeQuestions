class Solution {
public:
    int fun(vector<int> &prices, int n, int idx, int canbuy, int fee, vector<vector<int>> &dp){
        if(idx == n){
            return 0;
        }
        if(dp[idx][canbuy] != -1){
            return dp[idx][canbuy];
        }
        int profit = 0;
        if(canbuy){
            int buy_today = -prices[idx] + fun(prices, n, idx+1, 0, fee, dp);
            int skip_today = 0 + fun(prices, n, idx+1, 1, fee, dp);

            profit = max(buy_today, skip_today);
        }else{
            int sell_today = prices[idx] + fun(prices, n, idx+1, 1, fee, dp) - fee;
            int skip_today = 0 + fun(prices, n, idx+1, 0, fee, dp);

            profit = max(sell_today, skip_today);
        }

        return dp[idx][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fun(prices, n, 0, 1, fee, dp);
    }
};