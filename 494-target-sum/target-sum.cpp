class Solution {
public:
    int fun(vector<int> &nums, int sum, int idx, int currsum, vector<vector<int>> &dp){
        if(idx >= nums.size()){
            if(sum == currsum){
                return 1;
            }
            return 0;
        }
        if(dp[idx][currsum] != -1){
            return dp[idx][currsum];
        }
        // nottake
        int nottake = fun(nums, sum, idx+1, currsum, dp);
        // take
        int take = fun(nums, sum, idx+1, currsum + nums[idx], dp);

        return dp[idx][currsum] = nottake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < target) return 0;
        if((target+sum) % 2 != 0) return 0;
        int s1 = (target + sum)/2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return fun(nums, s1, 0, 0, dp);
    }
};