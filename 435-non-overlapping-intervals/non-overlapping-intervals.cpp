class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int ans = 0;
        int n = intervals.size();
        vector<vector<int>> str;
        for(auto interval:intervals){
            if(str.empty() || str.back()[1] <= interval[0]){
                str.push_back(interval);
            }else{
                ans++;
            }
        }
        return ans;
    }
};