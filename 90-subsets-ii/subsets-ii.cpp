class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>&nums, vector<int>& temp, int idx){

        ans.push_back(temp);
        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }

            temp.push_back(nums[i]);
            generate(nums, temp, i+1);
            temp.pop_back();

            // generate(nums, temp, i+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        generate(nums, temp, 0);
        // vector<vector<int>> a(ans.begin(), ans.end());
        return ans;
    }
};
