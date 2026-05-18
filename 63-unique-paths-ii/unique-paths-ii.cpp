class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == 0 && j == 0){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int temp1 = 0;
        int temp2 = 0;
        //up
        if(i > 0 && obstacleGrid[i-1][j] != 1) temp1 = fun(i-1, j, obstacleGrid, dp);
        if(j > 0 && obstacleGrid[i][j-1] != 1) temp2 = fun(i, j-1, obstacleGrid, dp);

        return dp[i][j] = temp1 + temp2;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();//rows
        int n = obstacleGrid[0].size();//col
        vector<vector<int>>dp (m, vector<int> (n, -1));
        return fun(m-1, n-1, obstacleGrid, dp);
    }
};