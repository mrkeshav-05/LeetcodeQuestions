class Solution {
public:
    int fun(vector<int>& prices, int n, int idx, bool canbuy, vector<vector<int>> &dp){
        if(idx == n){
            return 0;
        }
        int profit = 0;
        if(dp[idx][canbuy] != -1){
            return dp[idx][canbuy];
        }
        if(canbuy){
            int buy_today = -prices[idx] + fun(prices, n, idx+1, false, dp);
            int skip_today = 0 + fun(prices, n, idx+1, true, dp);

            profit = max(buy_today, skip_today);
        }else{
            int sell_today = prices[idx] + fun(prices, n, idx+1, true, dp);
            int skip_today = 0 + fun(prices, n, idx+1, false, dp);
            profit = max(sell_today, skip_today);
        }
        return dp[idx][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fun(prices, n, 0, true, dp);
    }
};