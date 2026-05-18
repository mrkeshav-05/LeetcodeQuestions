class Solution {
public:
    int fun(int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // up
        int temp1 = 0;
        int temp2 = 0;
        if(i > 0) temp1 = fun(i-1, j, dp);
        //left
        if(j > 0) temp2 = fun(i, j-1, dp);

        return dp[i][j] = temp1 + temp2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return fun(m-1, n-1, dp);
    }
};