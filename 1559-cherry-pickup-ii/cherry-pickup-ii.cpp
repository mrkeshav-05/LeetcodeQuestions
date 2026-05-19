class Solution {
public:
    int fun(vector<vector<int>>& grid, int idx, int col1, int col2, vector<vector<vector<int>>> &dp){
        if(col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size()){
            return -1e9; 
        }
        if(idx == grid.size()-1){
            if(col1 == col2){
                return grid[idx][col1];
            }else{
                return grid[idx][col1] + grid[idx][col2];
            }
        }
        if(dp[idx][col1][col2] != -1){
            return dp[idx][col1][col2];
        }
        int maxSum = -1e9;
        vector<int> v = {-1, 0, 1};
        for(auto i:v){
            for(auto j:v){
                int newRobot1col = col1 + i;
                int newRobot2col = col2 + j;
                maxSum = max(maxSum, fun(grid, idx+1, newRobot1col, newRobot2col, dp));
            }
        }
        int current_cherries = 0;
        if(col1 == col2){
            current_cherries = grid[idx][col1];
        } else {
            current_cherries = grid[idx][col1] + grid[idx][col2];
        }
        return dp[idx][col1][col2] = current_cherries + maxSum;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, -1)));
        int ans = fun(grid, 0, 0, m-1, dp);
        return ans;
    }
};