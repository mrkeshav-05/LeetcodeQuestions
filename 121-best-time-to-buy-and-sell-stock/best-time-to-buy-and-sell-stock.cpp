class Solution {
public:
    int fun(int index, int min_price_so_far, vector<int>& prices, vector<int>& dp) {
        // Base Case: Out of days, no more profit can be made
        if (index == prices.size()) {
            return 0;
        }

        // Memoization Check: If we have already calculated the max profit 
        // starting from this day, return it.
        if (dp[index] != -1) {
            return dp[index];
        }

        // 1. Calculate potential profit if we sold everything today
        int current_profit = prices[index] - min_price_so_far;

        // 2. Update the minimum price seen so far for the next days
        int next_min_price = min(min_price_so_far, prices[index]);

        // 3. Recurse to find the maximum profit available in the future days
        int future_profit = fun(index + 1, next_min_price, prices, dp);

        // Save and return the maximum of today's profit vs any future profit
        return dp[index] = max(current_profit, future_profit);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // dp[i] will store the maximum profit achievable from day i onwards
        vector<int> dp(n, -1);
        
        // Start from day 0, with the initial minimum price set to infinity (INT_MAX)
        return fun(0, INT_MAX, prices, dp);
    }
};