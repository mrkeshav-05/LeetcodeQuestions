class Solution {
public:
    int fun(string text1, string text2, int n, int m, int i, int j, vector<vector<int>> &dp){
        if(i == n || j == m){
            return 0;
        }
        int take = 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(text1[i] == text2[j]){
            take = 1 + fun(text1, text2, n, m, i+1, j+1, dp);
        }
        int nottake = max(fun(text1, text2, n, m, i+1, j, dp), fun(text1, text2, n, m, i, j+1, dp));

        return dp[i][j] = max(take, nottake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // return fun(text1, text2, n, m, 0, 0, dp);
        return dp[n][m];

    }
};
