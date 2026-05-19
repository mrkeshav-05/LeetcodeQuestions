class Solution {
public:
    int fun(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        if(i == 0){
            return triangle[0][0];
        }
        if(dp[i][j] != INT_MIN){
            return dp[i][j];
        }
        int up = 1e9, left_diag = 1e9;
        if(j < i){
            up = fun(triangle, i-1, j, dp);
        }
        if(j != 0){
            left_diag = fun(triangle, i-1, j-1, dp);
        }

        return dp[i][j] = triangle[i][j] + min(up, left_diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int sum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for(int idx=0; idx < n ; idx++){
            sum = min(sum, fun(triangle, n-1, idx, dp));
        }
        return sum;
    }
};

// class Solution {
// public:
//     int fun(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
//         if(i == 0){
//             return matrix[0][j];
//         }
//         if(dp[i][j] != INT_MIN){
//             return dp[i][j];
//         }
//         int up = 1e9, left_diag = 1e9, right_diag = 1e9;
//         up = fun(matrix, i-1, j, dp);
        
//         if(j > 0){
//             left_diag = fun(matrix, i-1, j-1, dp);
//         }
        
//         if(j < matrix[0].size() - 1){
//             right_diag = fun(matrix, i-1, j+1, dp); // Fixed: j+1
//         }
//         return dp[i][j] = matrix[i][j] + min(up, min(left_diag, right_diag));
//     }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
//         int minSum = 1e9; 
//         for(int j = 0; j < n; j++){
//             minSum = min(minSum, fun(matrix, n-1, j, dp));
//         }
        
//         return minSum;
//     }
// };