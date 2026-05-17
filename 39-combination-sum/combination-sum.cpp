class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int> & candidates, int target, vector<int> &temp, int i, int sum){
        if(sum == target && i < candidates.size()){
            ans.push_back(temp);
            return;
        }
        if(sum > target || i == candidates.size()){
            return;
        }
        
        // take
        temp.push_back(candidates[i]);
        generate(candidates, target,temp, i, sum+candidates[i]);
        temp.pop_back();

        // nottake
        generate(candidates, target,temp, i+1, sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        generate(candidates, target, temp, 0, 0);
        return ans;
    }
};