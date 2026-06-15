class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        if (m == 0 || n == 0)
            return {};

        int i = 0;
        int j = 0;
        vector<vector<int>> res;

        while (i < n && j < m) {
            int s1 = firstList[i][0], e1 = firstList[i][1];
            int s2 = secondList[j][0], e2 = secondList[j][1];

            int st = max(s1, s2);
            int end = min(e1, e2);

            if (st <= end)
                res.push_back({st, end});

            if (e1 < e2)
                i++;
            else
                j++;
        }

        return res;

    }
};