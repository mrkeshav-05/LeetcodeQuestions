class Solution {
public:
    int fun(vector<int> &nums, int idx, int previdx, vector<vector<int>> &dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][previdx+1] != -1){
            return dp[idx][previdx+1];
        }
        int nottake = 0 + fun(nums, idx+1, previdx, dp);
        int take = 0;
        if(previdx == -1 || nums[idx] > nums[previdx]){
            take = 1 + fun(nums, idx+1, idx, dp);
        }
        return dp[idx][previdx+1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fun(nums, 0, -1, dp);
    }
};