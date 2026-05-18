class Solution {
public:
    int fun(vector<int> &nums, int idx, vector<int> &memo){
        if (idx < 0) {
            return 0;
        }
        if(idx == 0){
            return nums[idx];
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        
        //include
        int temp1 = nums[idx] + fun(nums, idx-2, memo);
        //not include
        int temp2 = fun(nums, idx-1, memo);

        return memo[idx] = max(temp1, temp2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return fun(nums, n-1, memo);
    }
};