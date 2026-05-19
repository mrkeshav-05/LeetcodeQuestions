class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return grid[i][j];
        }
        //up
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = INT_MAX;
        if(i>0){
            up = fun(grid, i-1, j, dp) + grid[i][j];
        }
        //left
        int left = INT_MAX;
        if(j > 0){
            left = fun(grid, i, j-1, dp) + grid[i][j];
        }
        return dp[i][j] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(grid, m-1, n-1, dp);
        // dp[0][0] = grid[0][0];
        // for(int j = 1; j<n; j++){
        //     dp[0][j] = grid[0][j] + dp[0][j-1];
        // }
        // for(int j=0; j<n; j++){
        //     for(int i=1; i<m; i++){
        //         if(j == 0){
        //             dp[i][j] = dp[i-1][j] + grid[i][j];
        //         }else{
        //             dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
    }
};

// [
    //9 [9, 9, 9, 9, 9, 9]
//    9 [1, 3, 1, 1, 3, 1]
//    9 [1, 5, 1, 1, 3, 1]
//    9 [4, 2, 1, 1, 3, 1]
//    9 [4, 2, 1, 1, 3, 1]
// ]
// dp = 
// [
//     [1, 4, 5]
//     [2, 7, 6]
//     [6, 8, 7]

// ]