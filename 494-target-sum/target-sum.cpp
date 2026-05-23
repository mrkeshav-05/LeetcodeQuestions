class Solution {
public:
    int fun(vector<int>& nums, int target, int idx, vector<vector<int>> &dp){
        if(idx < 0) {
            return target == 0 ? 1 : 0;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        int take = 0;
        if(target >= nums[idx]){
            take = fun(nums, target - nums[idx], idx-1, dp);
        }
        int nottake = fun(nums, target, idx-1, dp);

        return dp[idx][target] = take + nottake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum + target) % 2 != 0){
            return 0;
        }
        if(abs(target) > sum){
            return 0;
        }
        int newtarget = (sum + target)/2;
        vector<vector<int>> dp(n, vector<int>(newtarget + 1, -1));

        return fun(nums, newtarget, n-1, dp);
    }
};