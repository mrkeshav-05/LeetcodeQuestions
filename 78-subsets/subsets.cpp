class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int> &temp, vector<int> &nums, int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        // take condition
        temp.push_back(nums[i]);
        generate(temp, nums, i+1);
        temp.pop_back();

        // not take
        generate(temp, nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        generate(temp, nums, 0);
        return ans;
    }
};

