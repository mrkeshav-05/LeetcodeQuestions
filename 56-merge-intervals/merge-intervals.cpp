class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto arr : intervals){
            if(ans.empty() || ans.back()[1] < arr[0]){
                ans.push_back(arr);
            }else{
                ans.back()[1] = max(arr[1], ans.back()[1]);
            }
        }
        return ans;
    }
};