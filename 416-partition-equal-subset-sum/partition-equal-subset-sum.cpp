class Solution {
public:
    bool fun(vector<int>& nums, int idx, int sum, int currsum, vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(sum == currsum){
                return true;
            }
            return false;
        }
        if(dp[idx][currsum] != -1){
            return dp[idx][currsum];
        }
        // take
        bool take = fun(nums, idx+1, sum, currsum+nums[idx], dp);
        bool nottake = fun(nums, idx+1, sum, currsum, dp);

        return dp[idx][currsum] = take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum %2 != 0){
            return false;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
        return fun(nums, 0, sum/2, 0, dp);
    }
};