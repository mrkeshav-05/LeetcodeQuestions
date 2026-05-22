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
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(sum+1));
        for(int i=0; i<sum+1; i++){
            dp[0][i] = false;
        }
        for(int i=0; i<nums.size()+1; i++){
            dp[i][0] = true;
        }
        for(int i=1; i<nums.size()+1; i++){
            for(int j=1; j<sum+1; j++){
                if(j >= nums[i-1]){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][sum/2];
    }
};