class Solution {
public:
    int fun(vector<int>& prices, int n, int idx, int number_of_trans_left, int canbuy, vector<vector<vector<int>>> &dp){
        if(idx == n){
            return 0;
        }
        if(dp[idx][canbuy][number_of_trans_left] != -1){
            return dp[idx][canbuy][number_of_trans_left];
        }
        int profit = 0;
        if(number_of_trans_left > 0){
            if(canbuy){
                int buy_today = -prices[idx] + fun(prices, n, idx+1, number_of_trans_left, 0, dp);
                int skip_today = 0 + fun(prices, n, idx+1, number_of_trans_left, 1, dp);

                profit = max(buy_today, skip_today);
            }else{
                int sell_today = prices[idx] + fun(prices, n, idx+1, number_of_trans_left-1, 1, dp);
                int skip_today = 0 + fun(prices, n, idx+1, number_of_trans_left, 0, dp);

                profit = max(sell_today, skip_today);
            }
        }
        return dp[idx][canbuy][number_of_trans_left] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return fun(prices, n, 0, k, 1, dp);
    }
};