class Solution {
public:
    int fun(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        // 1. Base Case
        if(i == 0){
            return matrix[0][j];
        }
        
        // 2. Memoization Check
        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        }
        
        // Initialize with a very large number so invalid paths aren't chosen as the minimum
        int up = 1e9, left_diag = 1e9, right_diag = 1e9;
        
        // 3. The three possible moves
        up = fun(matrix, i-1, j, dp);
        
        if(j > 0){
            left_diag = fun(matrix, i-1, j-1, dp);
        }
        
        if(j < matrix[0].size() - 1){
            right_diag = fun(matrix, i-1, j+1, dp); // Fixed: j+1
        }
        
        // 4. Add the CURRENT cell's value to the minimum of the paths above
        return dp[i][j] = matrix[i][j] + min(up, min(left_diag, right_diag));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Memoization table initialized to -1
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        
        // Initialize to a large number!
        int minSum = 1e9; 
        
        // Try starting the falling path from every cell in the bottom row
        for(int j = 0; j < n; j++){
            minSum = min(minSum, fun(matrix, n-1, j, dp));
        }
        
        return minSum;
    }
};