class Solution {
public:
    int fun(int idx, int canBuy, vector<int>& prices, vector<vector<int>> &dp) {
        if(idx == prices.size()){
            return 0;
        }
        int max_profit = 0;
        if(dp[idx][canBuy] != -1){
            return dp[idx][canBuy];
        }
        if(canBuy == 1){
            int buy_today = -prices[idx] + fun(idx+1, 0, prices, dp);
            int skip_today = 0 + fun(idx+1, 1, prices, dp);
            max_profit = max(buy_today, skip_today);
        }else{
            int sell_today = prices[idx];
            int skip_today = 0 + fun(idx + 1, 0, prices, dp);
            max_profit = max(sell_today, skip_today);
        }

        return dp[idx][canBuy] = max_profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return fun(0, 1, prices, dp);
    }
};