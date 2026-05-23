class Solution {
public:
    int fun(vector<int>& nums, int target, int idx){
        if(idx < 0) {
            return target == 0 ? 1 : 0;
        }
        int take = 0;
        if(target >= nums[idx]){
            take = fun(nums, target - nums[idx], idx-1);
        }
        int nottake = fun(nums, target, idx-1);

        return take + nottake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum + target) % 2 != 0){
            return 0;
        }
        if(target > sum){
            return 0;
        }
        int newtarget = (sum + target)/2;

        return fun(nums, newtarget, n-1);
    }
};