class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> ans;
        int n = points.size();
        sort(points.begin(), points.end());
        for(auto point : points){
            if(ans.empty() || ans.back()[1] < point[0]){
                ans.push_back(point);
            }else{
                ans.back()[0] = max(ans.back()[0], point[0]);
                ans.back()[1] = min(ans.back()[1], point[1]);
            }
        }
        return ans.size();
    }
};