class Solution {
public:

vector<vector<int>> ans;
    void generate(vector<int> & candidates, int target, vector<int> &temp, int start, int sum){
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            if(sum+candidates[i] > target){
                break;
            }
            temp.push_back(candidates[i]);
            generate(candidates, target, temp, i+1, sum+candidates[i]);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        generate(candidates, target, temp, 0, 0);
        return ans;
    }
};