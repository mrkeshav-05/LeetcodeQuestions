class Solution {
public:
    vector<vector<int>> ans;
    void generate(int k, int n, vector<int>& nums, vector<int>& temp, int sum, int idx){
        if(idx == nums.size()){
            if(sum == n && temp.size() == k){
                ans.push_back(temp);
            }
            return;
        }
        // take
        temp.push_back(nums[idx]);
        generate(k, n, nums, temp, sum+nums[idx], idx+1);
        temp.pop_back();

        //nottake
        generate(k, n, nums, temp, sum, idx+1);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        nums[0] = 1;
        for(int i=1; i<9; i++){
            nums[i] = i+1;
        }
        // nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;
        generate(k, n, nums, temp, 0, 0);

        return ans;
    }
};