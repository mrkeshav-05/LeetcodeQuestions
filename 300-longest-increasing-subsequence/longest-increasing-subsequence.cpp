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
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // int ans = fun(nums, 0, -1, dp);
        // return dp[0][0];
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n+1; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // return ans;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int p = i-1; p>=-1; p--){
                int nottake = 0+dp[i+1][p+1];
                int take = 0;
                if(p == -1 || nums[i] > nums[p]){
                    take = 1+dp[i+1][i+1];
                }
                dp[i][p+1] = max(nottake, take);
            }
        }
        return dp[0][0];
    }
};